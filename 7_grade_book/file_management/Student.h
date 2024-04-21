#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Student structure to hold student details
struct Student {
    std::string name;
    int id;
    double grade;

    // Constructor to initialize a student record
    Student(std::string n, int i, double g) : name(std::move(n)), id(i), grade(g) {}
};

#endif // STUDENT_H
