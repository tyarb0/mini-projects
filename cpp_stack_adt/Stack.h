// Stack.h
// Simple Stack ADT storing strings (no STL containers).
// Implements push/pop/isEmpty/size with dynamic array growth.
// Author: Terrance "TJ" Yarbrough (resume sample)
// Note: Uses std::string (allowed in most courses). If disallowed, replace with C-strings.

#ifndef STACK_H
#define STACK_H

#include <string>

class Stack {
private:
    std::string* data; // dynamic array
    int capacity;
    int topIndex; // index of next free slot (also equal to current size)

    void resize(int newCap);

public:
    explicit Stack(int initialCap = 16);
    ~Stack();

    // Rule of three
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    void push(const std::string& value);
    bool pop(std::string& out); // returns false if empty
    bool isEmpty() const { return topIndex == 0; }
    int size() const { return topIndex; }
};

#endif // STACK_H
