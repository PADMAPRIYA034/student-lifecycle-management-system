#include "Management.h"
#include <fstream>
#include <string>

void Management::loadFromFile() {
    students.clear();
    ifstream file("data.txt");
    string line;

    while (std::getline(file, line)) {
        Student s;
        s.fromFileString(line);
        students.push_back(s);
    }

    file.close();
}

void Management::saveToFile() {
    ofstream file("data.txt");

    for (auto &s : students) {
        file << s.toFileString() << endl;
    }

    file.close();
}

void Management::addStudent() {
    Student s;
    s.input();
    s.setRollNo(students.size() + 1);
    students.push_back(s);

    saveToFile();
    cout << "Student Added Successfully!\n";
}

void Management::viewStudents() {
    for (auto &s : students) {
        s.display();
    }
}

void Management::updateSemester() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.getRollNo() == roll) {
            s.updateSemester();
            saveToFile();
            cout << "Semester Updated!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

void Management::updateFees() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.getRollNo() == roll) {
            s.updateFees();
            saveToFile();
            cout << "Fees Updated!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

void Management::graduateStudent() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.getRollNo() == roll) {
            s.graduate();
            saveToFile();
            cout << "Student Graduated!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}