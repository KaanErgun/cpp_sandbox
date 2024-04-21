/**
 * Student Grade Book Application
 *
 * This application manages student grades and personal information.
 * It allows adding, updating, displaying, and exiting student records management.
 * Each student record consists of a name, ID, and grade. This is a simple
 * console-based application that demonstrates basic data management and
 * manipulation in C++ using structured data.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student structure to hold student details
struct Student {
    string name;
    int id;
    double grade;

    // Constructor to initialize a student record
    Student(string n, int i, double g) : name(move(n)), id(i), grade(g) {}
};

class GradeBook {
private:
    vector<Student> students;  // Vector to store student records

public:
    // Adds a new student to the grade book
    void addStudent(const string& name, int id, double grade) {
        students.emplace_back(name, id, grade);
        cout << "Student added successfully." << endl;
    }

    // Updates the grade of an existing student by ID
    void updateGrade(int id, double newGrade) {
        for (auto& student : students) {
            if (student.id == id) {
                student.grade = newGrade;
                cout << "Grade updated successfully for student ID " << id << "." << endl;
                return;
            }
        }
        cout << "Student not found with ID " << id << "." << endl;
    }

    // Displays all students in the grade book
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students to display." << endl;
            return;
        }
        cout << "Student Records:" << endl;
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << endl;
        }
    }
};

int main() {
    GradeBook myGradeBook;
    string name;
    int id;
    double grade;

    cout << "Student Grade Book Application" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Update Student Grade" << endl;
    cout << "3. Display All Students" << endl;
    cout << "4. Exit" << endl;  // Exit option

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student's name: ";
                cin >> ws;  // Consumes any leading whitespace
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student's grade: ";
                cin >> grade;
                myGradeBook.addStudent(name, id, grade);
                break;
            case 2:
                cout << "Enter student ID to update grade: ";
                cin >> id;
                cout << "Enter new grade: ";
                cin >> grade;
                myGradeBook.updateGrade(id, grade);
                break;
            case 3:
                myGradeBook.displayAllStudents();
                break;
            case 4:
                cout << "Exiting application." << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
