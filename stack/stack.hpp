#ifndef STACK_HPP
#define STACK_HPP

#include <exception>

template <typename T>
class Stack {
    public:
        Stack();
        ~Stack();
        void push(T data); // throws std::bad_alloc
        T& top();
        void pop();
        unsigned size();

    private:
        T* array;
        unsigned array_size;
        unsigned capacity;

        void resize();
};


template <typename T>
Stack<T>::Stack() {
    array_size = 0;
    capacity = 1;
    array = new T[1];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template <typename T>
void Stack<T>::resize() {
    T* new_array = new T[capacity * 2];
    capacity *= 2;
    for (int i = 0; i < array_size; i += 1) {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
}

template <typename T>
void Stack<T>::push(T data) {
    if (array_size == capacity) {
        resize();
    }
    array[array_size] = data;
    array_size += 1;
}

template <typename T>
void Stack<T>::pop() {
    if (array_size == 0) {
        throw std::logic_error("Attempted to pop from empty stack");
    }
    array_size -= 1;
}

template <typename T>
T& Stack<T>::top() {
    if (array_size == 0) {
        throw std::logic_error("Attempted to access top from empty stack");
    }
    return array[array_size - 1];
}

template <typename T>
unsigned Stack<T>::size() {
    return array_size;
}

#endif
