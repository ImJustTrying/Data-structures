#include <iostream>
#include <exception>
#include "queue.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main() {
    const int N = 5;
    Queue<int> q;
    for (int i = 0; i < N; i += 1) {
        q.enqueue(i);
    }

    for (int i = 0; i < N; i += 1) {
        cout << q.front() << " " << q.size() << endl;
        q.dequeue();
    }

    try {
        q.front();
    } catch (std::logic_error& le) {
        cerr << le.what() << endl;
    }

    try {
        q.dequeue();
    } catch (std::logic_error& le) {
        cerr << le.what() << endl;
    }
}
