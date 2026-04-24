require('dotenv').config();

const express = require('express');
const mongoose = require('mongoose');
const Student = require('./models/Student');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());
app.use(express.static('public'));


// ================= DB CONNECTION =================
mongoose.connect(process.env.MONGO_URI)
.then(() => console.log("MongoDB Connected"))
.catch(err => console.log("DB Error:", err));


// ================= ROUTES =================

// Root route (optional but useful)
app.get('/', (req, res) => {
    res.send("API Running...");
});


// ================= ADD STUDENT =================
app.post('/add', async (req, res) => {
    try {
        const { name, year, branch } = req.body;

        if (!name || !year || !branch) {
            return res.status(400).send("All fields required");
        }

        // Count students in same branch
        const count = await Student.countDocuments({ branch });

        const branchCodes = {
            CSE: "12",
            ECE: "14",
            CIVIL: "11",
            ELECTRICAL: "13",
            EIE: "15",
            MECHANICAL: "16"
        };

        const code = branchCodes[branch.toUpperCase()];

        if (!code) {
            return res.status(400).send("Invalid branch");
        }

        const serial = (count + 1).toString().padStart(3, '0');

        // Take last 2 digits of year
        const yearStr = year.toString();

        if (yearStr.length !== 4) {
            return res.status(400).send("Enter valid 4-digit year");
        }

        const shortYear = yearStr.slice(-2); // last 2 digits

        const rollNo = `${shortYear}${code}${serial}`;

        const student = new Student({
            name,
            year,
            branch,
            rollNo
        });

        await student.save();

        res.status(201).json(student);

    } catch (err) {
        res.status(500).send("Error adding student");
    }
});


// ================= GET ALL STUDENTS =================
app.get('/students', async (req, res) => {
    try {
        const students = await Student.find();
        res.json(students);

    } catch (err) {
        console.log(err);
        res.status(500).send("Error fetching students");
    }
});


// ================= UPDATE SEMESTER =================
app.post('/semester', async (req, res) => {
    try {
        const { id } = req.body;

        if (!id) {
            return res.status(400).send("Student ID required");
        }

        const student = await Student.findByIdAndUpdate(
            id,
            { $inc: { semester: 1 } },
            { new: true }
        );

        if (!student) {
            return res.status(404).send("Student not found");
        }

        res.send("Semester Updated");

    } catch (err) {
        console.log(err);
        res.status(500).send("Error updating semester");
    }
});


// ================= UPDATE FEES =================
app.post('/fees', async (req, res) => {
    try {
        const { id } = req.body;

        if (!id) {
            return res.status(400).send("Student ID required");
        }

        const student = await Student.findByIdAndUpdate(
            id,
            { feesPaid: true },
            { new: true }
        );

        if (!student) {
            return res.status(404).send("Student not found");
        }

        res.send("Fees Updated");

    } catch (err) {
        console.log(err);
        res.status(500).send("Error updating fees");
    }
});


// ================= GRADUATE =================
app.post('/graduate', async (req, res) => {
    try {
        const { id } = req.body;

        if (!id) {
            return res.status(400).send("Student ID required");
        }

        const student = await Student.findByIdAndUpdate(
            id,
            { graduated: true },
            { new: true }
        );

        if (!student) {
            return res.status(404).send("Student not found");
        }

        res.send("Student Graduated");

    } catch (err) {
        console.log(err);
        res.status(500).send("Error graduating student");
    }
});

app.delete('/delete/:id', async (req, res) => {
    try {
        const student = await Student.findByIdAndDelete(req.params.id);

        if (!student) {
            return res.status(404).send("Student not found");
        }

        res.send("Student Deleted");

    } catch (err) {
        console.log(err);
        res.status(500).send("Error deleting student");
    }
});

// ================= START SERVER =================
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});