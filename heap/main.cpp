#include <iostream>
#include <random>
#include "heap.hpp"

int main() {
    Heap<int,char> h;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 25);

}
