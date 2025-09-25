# Resume Projects (Code Samples)

This bundle includes four small, black‑and‑white friendly, ATS‑safe code projects you can link on your resume.

## 1) C++ Stack ADT (no STL containers; uses std::string only)
- Files: `Stack.h`, `Stack.cpp`, `main.cpp`
- Build: `g++ -std=c++17 -O2 Stack.cpp main.cpp -o stack_app`
- Run: `./stack_app input.txt`

## 2) C++ Reading & Processing Inputs
- Files: `Student.h`, `Student.cpp`, `main.cpp`, `students.txt`
- Build: `g++ -std=c++17 -O2 main.cpp -o students_app`
- Run: `./students_app students.txt`

## 3) Java CSV Cleaner (CLI)
- File: `CSVCleaner.java`
- Build: `javac CSVCleaner.java`
- Run: `java CSVCleaner input.csv output.csv`

## 4) Python CSV Report (CLI)
- File: `csv_report.py`
- Run: `python csv_report.py input.csv summary.txt`

> Note: If your course forbids `std::string`, I can swap to C-style strings. The C++ code already separates interface (`.h`) and implementation (`.cpp`) and uses clear comments for readability.
