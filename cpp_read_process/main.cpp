// main.cpp
// Reads student records from a file, computes averages and letter grades, prints a formatted table.
// Input format per line: ID Name Test1 Test2 Test3
// Example: 1001 Alice 88 91 79
#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>

static const int MAX_STUDENTS = 200;

double computeAverage(const double t[3]) {
    return (t[0] + t[1] + t[2]) / 3.0;
}

char letterFromAverage(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

int loadStudents(const char* filename, Student arr[], int maxN) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error: cannot open file '" << filename << "'.\n";
        return -1;
    }
    int n = 0;
    while (n < maxN && fin >> arr[n].id >> arr[n].name 
           >> arr[n].test[0] >> arr[n].test[1] >> arr[n].test[2]) {
        arr[n].average = computeAverage(arr[n].test);
        arr[n].letter = letterFromAverage(arr[n].average);
        ++n;
    }
    return n;
}

void printTable(const Student arr[], int n) {
    std::cout << std::left 
              << std::setw(8) << "ID" 
              << std::setw(12) << "Name"
              << std::right
              << std::setw(8) << "Test1"
              << std::setw(8) << "Test2"
              << std::setw(8) << "Test3"
              << std::setw(10) << "Average"
              << std::setw(8)  << "Grade"
              << "\n";

    std::cout << std::string(62, '-') << "\n";

    std::cout.setf(std::ios::fixed); 
    std::cout << std::setprecision(2);
    for (int i = 0; i < n; ++i) {
        std::cout << std::left 
                  << std::setw(8) << arr[i].id
                  << std::setw(12) << arr[i].name
                  << std::right
                  << std::setw(8) << arr[i].test[0]
                  << std::setw(8) << arr[i].test[1]
                  << std::setw(8) << arr[i].test[2]
                  << std::setw(10) << arr[i].average
                  << std::setw(8)  << arr[i].letter
                  << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <students-file>\n";
        return 1;
    }
    Student students[MAX_STUDENTS];
    int n = loadStudents(argv[1], students, MAX_STUDENTS);
    if (n < 0) return 1;

    std::cout << "Loaded " << n << " students from '" << argv[1] << "'.\n\n";
    printTable(students, n);
    return 0;
}
