/*
 * Kevin Vicente
 * April 2022
 *
 * This is effectively a binary search tree stored in memory as an array.
 */

#ifndef SORTED_ARRAY_HPP
#define SORTED_ARRAY_HPP

#include <iostream>
#include <exception>

template <typename K, typename V>
class SortedArray {
    public:
        SortedArray();
        ~SortedArray();
        unsigned size();
        void insert(K key, V value);
        void remove(K key);
        V& get(K key);
        void set(K key, V value);
        V& max();
        V& min();
        void inorder();

    private:
        K* keys;
        V* values;
        unsigned array_size, capacity;

        void resize();
        unsigned get_index(K key);
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
    int high = array_size - 1;
    int low = 0;
    int index = high / 2;
    while (keys[index] != key && high >= low) {
        if (keys[index] < key) {
            low = index + 1;
        } else {
            high = index - 1;
        }
        index = (high - low) / 2 + low;
    }
    return index;
}

// Does not overwrite values with the same key, will throw an exception instead
template <typename K, typename V>
void SortedArray<K,V>::insert(K key, V value) {
    std::cout << "value: " << value << std::endl;
    if (array_size == 0) {
        keys[0] = key;
        values[0] = value;
        array_size += 1;
        std::cout << "inserting " << key << " at index 0" << std::endl;
        return;
    } else if (array_size == capacity) {
        resize();
    }

    std::cout << "key = " << key << std::endl;
    // search for the index of the key -- if it 
    unsigned index = get_index(key);
    if (keys[index] == key) {
        throw std::logic_error("Attempted to insert key already in sorted list");
    }
    std::cout << "inserting " << key << " at index " << index << std::endl;

    // shift the values past the index we are inserting the key to
    for (int i = array_size; i > index; i -= 1) {
        keys[i] = keys[i-1];
        values[i] = values[i-1];
    }
    keys[index] = key;
    values[index] = value;
    array_size += 1;
}

template <typename K, typename V>
V& SortedArray<K,V>::get(K key) {
    unsigned index = get_index(key);
    if (keys[index] == key) {
        return values[index];
    } else {
        throw std::logic_error("Attempted to get value associated with non existent key");
    }
}

template <typename K, typename V>
void SortedArray<K,V>::inorder() {
    for (int i = 0; i < array_size; i += 1) {
        std::cout << "(" << keys[i] << ", " << values[i] << ")" << std::endl;
    }
}

template <typename K, typename V>
V& SortedArray<K,V>::min() {
    return values[0];
}

template <typename K, typename V>
V& SortedArray<K,V>::max() {
    return values[array_size - 1];
}

template <typename K, typename V>
void SortedArray<K,V>::set(K key, V value) {
    if (array_size == 0) {
        throw std::logic_error("Attempted to set with an empty sorted array");
    }
    unsigned index = get_index(key);
    if (keys[index] != key) {
        throw std::logic_error("Attempted to set key value pair with non existent key");
    }
    values[index] = value;
}

template <typename K, typename V>
void SortedArray<K,V>::remove(K key) {
    if (array_size == 0) {
        throw std::logic_error("Attempted to set with an empty sorted array");
    }

    unsigned index = get_index(key);
    if (keys[index] != key) {
        throw std::logic_error("Attempted to remove key value pair with non existent key");
    }

    for (int i = index; i < array_size; i += 1) {
        keys[i] = keys[i + 1];
        values[i] = values[i + 1];
    }
    array_size -= 1;
}

template <typename K, typename V>
void SortedArray<K,V>::resize() {
    K* new_keys = new K[capacity * 2];    
    V* new_values = new V[capacity * 2];
    capacity *= 2;
    for (int i = 0; i < array_size; i += 1) {
        new_keys[i] = keys[i];
        new_values[i] = values[i];
    }
    delete[] keys;
    delete[] values;
    keys = new_keys;
    values = new_values;
}
#endif
