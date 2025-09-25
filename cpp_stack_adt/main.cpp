// main.cpp
// Reads words from a text file, pushes onto Stack, then pops and prints in LIFO order.
// Usage: ./stack_app input.txt
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>\n";
        return 1;
    }
    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Error: cannot open file '" << argv[1] << "'.\n";
        return 1;
    }

    Stack st;
    std::string word;
    int count = 0;
    while (fin >> word) {
        st.push(word);
        ++count;
    }
    std::cout << "Pushed " << count << " words. Now printing in LIFO order:\n";

    std::string out;
    int idx = 0;
    while (st.pop(out)) {
        std::cout << std::setw(4) << ++idx << ": " << out << "\n";
    }
    return 0;
}
