// Stack.cpp
#include "Stack.h"
#include <stdexcept>

Stack::Stack(int initialCap)
    : data(nullptr), capacity(initialCap > 0 ? initialCap : 16), topIndex(0)
{
    data = new std::string[capacity];
}

Stack::~Stack() {
    delete[] data;
}

Stack::Stack(const Stack& other)
    : data(new std::string[other.capacity]), capacity(other.capacity), topIndex(other.topIndex)
{
    for (int i = 0; i < topIndex; ++i) data[i] = other.data[i];
}

Stack& Stack::operator=(const Stack& other) {
    if (this == &other) return *this;
    std::string* newData = new std::string[other.capacity];
    for (int i = 0; i < other.topIndex; ++i) newData[i] = other.data[i];
    delete[] data;
    data = newData;
    capacity = other.capacity;
    topIndex = other.topIndex;
    return *this;
}

void Stack::resize(int newCap) {
    if (newCap <= capacity) return;
    std::string* newData = new std::string[newCap];
    for (int i = 0; i < topIndex; ++i) newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCap;
}

void Stack::push(const std::string& value) {
    if (topIndex >= capacity) resize(capacity * 2);
    data[topIndex++] = value;
}

bool Stack::pop(std::string& out) {
    if (isEmpty()) return false;
    out = data[--topIndex];
    // optional: data[topIndex].clear();
    return true;
}
