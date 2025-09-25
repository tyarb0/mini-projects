// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string id;
    std::string name;
    double test[3];
    double average;
    char letter;
};

#endif // STUDENT_H
