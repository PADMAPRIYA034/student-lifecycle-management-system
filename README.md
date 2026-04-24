# 🎓 Student Admission & Lifecycle Management System

🚀 A full-stack web application to manage student records from admission to graduation, evolved from an Object-Oriented Programming (OOPS) based C++ system.

---

## 📌 Project Overview

This project is designed to manage the complete lifecycle of students in a college system.

It started as a **C++ OOPS-based console application using file handling**, and was later extended into a **full-stack web application** using modern technologies.

---

## 🔄 Project Evolution

### 🔹 Phase 1: C++ OOPS Implementation
- Developed using Object-Oriented Programming concepts
- Used file handling for data storage
- Console-based system

📁 Folder: `cpp-oops-version/`

---

### 🔹 Phase 2: Full Stack Web Application
- Built using Node.js, Express, and MongoDB
- Designed REST APIs for scalability
- Interactive frontend using HTML, CSS, JavaScript

📁 Folder: `web-app/`

---

## 🏗️ System Architecture
User → Frontend → Backend (Express APIs) → MongoDB → Response → UI


---

## ⚙️ Tech Stack

### 🌐 Web Application
- Frontend: HTML, CSS, JavaScript  
- Backend: Node.js, Express.js  
- Database: MongoDB (Mongoose)

### 💻 C++ Version
- Language: C++  
- Concepts: OOPS, File Handling  

---

## ✨ Features

- ➕ Add student records  
- 🔢 Automatic roll number generation  
- 📋 View all students  
- 📈 Update semester  
- 💰 Track fee status  
- 🎓 Mark students as graduated  
- 💾 Persistent storage (MongoDB)  
- 🔁 REST API-based architecture  

---

## 🧠 Key Implementation Highlight

### 🔹 Automatic Roll Number Generation

Roll number is generated using:
Roll No = (Last 2 digits of Year) + (Branch Code) + (Serial Number)


Example:

2024, CSE → 24 + 12 + 001 → 2412001

---

## 🧩 OOPS Concepts Applied

- **Encapsulation** → Data handled through structured models  
- **Abstraction** → Frontend interacts via APIs without backend complexity  
- **Inheritance** → Applied in initial C++ version (Person → Student)  
- **Modularity** → Separate frontend, backend, and database layers  

---

## 👥 Contributors & Roles

### 👩‍💻 R.V.Padma Priya (Lead Developer)
- Designed and implemented full-stack architecture  
- Developed backend using Node.js, Express, MongoDB  
- Built frontend and integrated APIs  
- Designed database schema  
- Implemented roll number generation logic  
- Converted C++ system into scalable web application  

### 👩 Amisha Kumari Jha (Teammate)
- Prepared project documentation and report  
- Assisted in presentation preparation  

---

## 🚀 How to Run (Web App)

```bash
cd web-app
npm install
npm start