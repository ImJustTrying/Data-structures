#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <exception>

template <typename T>
class Queue {
    public:
        Queue();
        ~Queue();
        void enqueue(T data);
        void dequeue();
        T& front();
        unsigned size();

    private:
        T* array;
        unsigned capacity, front_index, back_index, array_size;
        void resize();
};


template <typename T>
Queue<T>::Queue() {
    array = new T[1];
    capacity = 1;
    front_index = back_index = array_size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] array;
}

template <typename T>
T& Queue<T>::front() {
    if (array_size == 0) {
        throw std::logic_error("Attempted to get front of empty queue");
    }
    return array[front_index];
}

template <typename T>
void Queue<T>::dequeue() {
    if (array_size == 0) {
        throw std::logic_error("Attempted to dequeue from empty queue");
    }
    front_index = (front_index + 1) % capacity;
    array_size -= 1;
}

template <typename T>
void Queue<T>::enqueue(T data) {
    if (array_size == capacity) {
        resize();
    }
    back_index = (back_index + 1) % capacity;
    array[back_index] = data;
    array_size += 1;
}

template <typename T>
unsigned Queue<T>::size() {
    return array_size;
}

template <typename T>
void Queue<T>::resize() {
    T* new_array = new T[capacity * 2];
    unsigned index = front_index;
    for (int i = 0; i < array_size; i += 1) {
        new_array[i] = array[index];
        index = (index + 1) % capacity;
    }
    capacity *= 2;
    front_index = 0;
    back_index = array_size - 1;
}

#endif
