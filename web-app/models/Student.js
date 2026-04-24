const mongoose = require('mongoose');

const studentSchema = new mongoose.Schema({
    name: String,
    year: Number,
    branch: String,
    rollNo: String,   // NEW

    semester: { type: Number, default: 1 },
    feesPaid: { type: Boolean, default: false },
    graduated: { type: Boolean, default: false }
});

module.exports = mongoose.model('Student', studentSchema);