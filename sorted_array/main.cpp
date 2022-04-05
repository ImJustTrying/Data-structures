#include <iostream>
#include <random>
#include "sorted_array.hpp"

int main() {
    SortedArray<int, char> sa;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 25);
    const int N = 5;
    std::vector<int> keys;

    for (int i = 0; i < N; i += 1) {
        int rand_num = distribution(generator);
        sa.insert(rand_num, 'A' + i);
        keys.push_back(rand_num);
    }

    for (int i = 0; i < N; i += 1) {
        std::cout << sa.get(keys[i]) << " -> ";
        sa.set(keys[i], 'a' + i); 
        std::cout << sa.get(keys[i]);
        sa.remove(keys[i]);
        std::cout << " (remaining size: " << sa.size() << ")" << std::endl;
        sa.inorder();
    }
}
