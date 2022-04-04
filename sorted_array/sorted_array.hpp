/*
 * Kevin Vicente
 * April 2022
 *
 * This is effectively a binary search tree stored in memory as an array.
 */

#ifndef SORTED_ARRAY_HPP
#define SORTED_ARRAY_HPP

#include <exception>

template <typename K, typename V>
class SortedArray {
    public:
        SortedArray();
        ~SortedArray();
        unsigned size();
        void insert(K key, V value);
        void remove(K key);// Note: O(N) time complexity
        V get(K key);
        void set(K key, V value);
        V max();
        V min();
        unsigned get_index(K key);

    private:
        K* keys;
        V* values;
        unsigned array_size, capacity;

};


/*
template <typename K, typename V>
SortedArray<K,V>::() {}
*/

template <typename K, typename V>
SortedArray<K,V>::SortedArray() {
    capacity = 1;
    keys = new K[1];
    values = new V[1];
    array_size = 0;
}

template <typename K, typename V>
SortedArray<K,V>::~SortedArray() {
    delete[] keys;
    delete[] values;
}

template <typename K, typename V>
unsigned SortedArray<K,V>::size() {
    return array_size;
}

template <typename K, typename V>
unsigned SortedArray<K,V>::get_index(K key) {
    if (array_size == 0) {
        throw std::logic_error("Attempted to find key in sorted list with no such key");
    }
    unsigned high = array_size - 1;
    unsigned low = 0;
    unsigned index = high / 2;
    while (keys[index] != key && high >= low) {
        if (keys[index] < key) {
            low = index + 1;
        } else {
            high = index - 1;
        }
        index = (high - low) / 2 + low;
    }
    if (keys[index] == key) {
        return index;
    } else {
        throw std::logic_error("Attempted to find key in sorted list with no such key");
    }
}
#endif
