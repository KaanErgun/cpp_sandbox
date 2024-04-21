#include "GradeBook.h"

int main() {
    GradeBook myGradeBook("students.txt");
    int choice;
    std::string name;
    int id;
    double grade;

    do {
        std::cout << "\nStudent Grade Book Application" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Update Student Grade" << std::endl;
        std::cout << "3. Display All Students" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter student's name: ";
                std::cin >> std::ws; // Clears the input buffer
                std::getline(std::cin, name);
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cout << "Enter student's grade: ";
                std::cin >> grade;
                myGradeBook.addStudent(name, id, grade);
                break;
            case 2:
                std::cout << "Enter student ID to update grade: ";
                std::cin >> id;
                std::cout << "Enter new grade: ";
                std::cin >> grade;
                myGradeBook.updateGrade(id, grade);
                break;
            case 3:
                myGradeBook.displayAllStudents();
                break;
            case 4:
                std::cout << "Exiting application." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (true);

    return 0;
}
