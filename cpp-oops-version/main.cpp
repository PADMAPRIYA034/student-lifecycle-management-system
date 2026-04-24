#include "Management.h"

int main() {
    Management m;
    m.loadFromFile();

    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Semester\n";
        cout << "4. Update Fees\n";
        cout << "5. Graduate Student\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: m.addStudent(); break;
            case 2: m.viewStudents(); break;
            case 3: m.updateSemester(); break;
            case 4: m.updateFees(); break;
            case 5: m.graduateStudent(); break;
        }

    } while (choice != 0);

    return 0;
}