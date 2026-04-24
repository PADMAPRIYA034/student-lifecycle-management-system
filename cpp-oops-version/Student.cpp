#include "Student.h"
#include <sstream>

Student::Student() {
    semester = 1;
    feesPaid = false;
    graduated = false;
}

void Student::input() {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
}

void Student::display() {
    cout << "\nRoll No: " << rollNo;
    cout << "\nName: " << name;
    cout << "\nSemester: " << semester;
    cout << "\nFees Paid: " << (feesPaid ? "Yes" : "No");
    cout << "\nGraduated: " << (graduated ? "Yes" : "No") << endl;
}

int Student::getRollNo() {
    return rollNo;
}

void Student::setRollNo(int r) {
    rollNo = r;
}

void Student::updateSemester() {
    semester++;
}

void Student::updateFees() {
    feesPaid = true;
}

void Student::graduate() {
    graduated = true;
}

string Student::toFileString() {
    return to_string(rollNo) + "," + name + "," +
           to_string(semester) + "," +
           to_string(feesPaid) + "," +
           to_string(graduated);
}

void Student::fromFileString(string line) {
    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    rollNo = stoi(temp);

    getline(ss, name, ',');

    getline(ss, temp, ',');
    semester = stoi(temp);

    getline(ss, temp, ',');
    feesPaid = stoi(temp);

    getline(ss, temp, ',');
    graduated = stoi(temp);
}