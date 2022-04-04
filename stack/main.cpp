#include <iostream>
#include <exception>
#include "stack.hpp"

using std::cout;
using std::endl;

int main() {
    const int N = 5;
    Stack<int> s;
    for (int i = 0; i < N; i += 1){
        s.push(i);
    }
    for (int i = 0; i < N; i += 1) {
        cout << s.top() << " " << s.size() << endl;
        s.pop();
    }

    try {
        s.top();
    } catch (std::logic_error& le) {
        std::cerr << le.what() << endl;
    }

    try {
        s.pop();
    } catch (std::logic_error& le) {
        std::cerr << le.what() << endl;
    }
}
