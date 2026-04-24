#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "Student.h"
#include <vector>

class Management {
private:
    vector<Student> students;

public:
    void loadFromFile();
    void saveToFile();

    void addStudent();
    void viewStudents();
    void updateSemester();
    void updateFees();
    void graduateStudent();
};

#endif