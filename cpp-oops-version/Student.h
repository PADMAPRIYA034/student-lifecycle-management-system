#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int rollNo;
    int semester;
    bool feesPaid;
    bool graduated;

public:
    Student();

    void input();
    void display();

    int getRollNo();
    void setRollNo(int r);

    void updateSemester();
    void updateFees();
    void graduate();

    string toFileString();
    void fromFileString(string line);
};

#endif