#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "FileManager.h"
#include <iostream>
#include <vector>
#include "Student.h"

class GradeBook {
private:
    std::vector<Student> students;
    std::string filename;

public:
    GradeBook(const std::string& filename) : filename(filename) {
        students = FileManager::loadStudents(filename);
    }

    void addStudent(const std::string& name, int id, double grade) {
        students.emplace_back(name, id, grade);
        FileManager::saveStudents(filename, students);
        std::cout << "Student added and saved successfully." << std::endl;
    }

    void updateGrade(int id, double newGrade) {
        for (auto& student : students) {
            if (student.id == id) {
                student.grade = newGrade;
                FileManager::saveStudents(filename, students);
                std::cout << "Grade updated and saved successfully for student ID " << id << "." << std::endl;
                return;
            }
        }
        std::cout << "Student not found with ID " << id << "." << std::endl;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "No students to display." << std::endl;
            return;
        }
        std::cout << "Student Records:" << std::endl;
        for (const auto& student : students) {
            std::cout << "Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << std::endl;
        }
    }
};

#endif // GRADEBOOK_H
