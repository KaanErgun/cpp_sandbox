#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Student.h"

class FileManager {
public:
    static void saveStudents(const std::string& filename, const std::vector<Student>& students) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file for writing." << std::endl;
            return;
        }
        for (const auto& student : students) {
            file << student.id << "," << student.name << "," << student.grade << "\n";
        }
        file.close();
    }

    static std::vector<Student> loadStudents(const std::string& filename) {
        std::vector<Student> students;
        std::ifstream file(filename);
        if (!file.is_open()) {
            return students; // Return an empty vector if the file does not exist
        }
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string name, id_str, grade_str;
            getline(ss, id_str, ',');
            getline(ss, name, ',');
            getline(ss, grade_str);

            int id = std::stoi(id_str);
            double grade = std::stod(grade_str);

            students.emplace_back(name, id, grade);
        }
        file.close();
        return students;
    }
};

#endif // FILEMANAGER_H