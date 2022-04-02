/*
 * Kevin Vicente
 * This is an implementation of a doubly linked list.
 * We choose a doubly linked list
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>
#include <string>

using std::string;


template <typename T> struct LinkedListNode {
    T data;
    LinkedListNode<T>* next;
    LinkedListNode<T>* prev;
    LinkedListNode(T d) : data{d}, next{nullptr}, prev{nullptr} {}
};

template <typename T> class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        T get(unsigned index);
        void insert(unsigned index, T data);
        void set(unsigned index, T data);
        void remove(unsigned index);
        T first();
        T last();
        void pop_first();
        void pop_last();
        void append(T data);
        void prepend(T data);
        unsigned length();
        string inorder();
        string postorder();

    private:
        LinkedListNode<T>* head;
        LinkedListNode<T>* tail;
        unsigned size;
};


template <typename T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* curr = head;
    while (curr != nullptr) {
        LinkedListNode<T>* temp = curr->next;
        delete curr;
        curr = temp; 
    }
}

template <typename T>
LinkedList<T>::LinkedList() : size{0}, head{nullptr}, tail{nullptr} {}

template <typename T>
T LinkedList<T>::get(unsigned index) {
    if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    LinkedListNode<T>* curr = head;
    for (unsigned i = 0; i < index; i += 1) {
        curr = curr->next;
    }
    return curr->data;
}

template <typename T>
void LinkedList<T>::insert(unsigned index, T data) {
    if (index == 0) {
        prepend(data);
        return;
    } else if (index == size) {
        append(data);
        return;
    } else if (index > size) {
        throw std::out_of_range("Index is out of range");
    }

    unsigned i = 0;
    LinkedListNode<T>* curr = head;
    LinkedListNode<T>* node = new LinkedListNode<T>(data);
    while (curr != nullptr && i < index) {
        curr = curr->next;
        i += 1;
    }

    curr->prev->next = node;
    node->prev = curr->prev;
    node->next = curr;
    curr->prev = node;
    size += 1;
}

template <typename T>
void LinkedList<T>::set(unsigned index, T data) {
    if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    LinkedListNode<T>* curr = head;
    for (unsigned i = 0; i < index; i += 1) {
        curr = curr->next;
    }
    curr->data = data;
}

template <typename T>
void LinkedList<T>::remove(unsigned index) {
    if (index == 0) {
        pop_first();
    } else if (index == size - 1) {
        pop_last();
    } else if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    LinkedListNode<T>* curr = head;
    for (unsigned i = 0; i < index; i += 1) {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    size -= 1;
}

template <typename T>
void LinkedList<T>::append(T data) {
    LinkedListNode<T>* node = new LinkedListNode<T>(data);
    size += 1;
    if (tail == nullptr) {
        tail = node;
        head = tail;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

template <typename T>
void LinkedList<T>::prepend(T data) {
    LinkedListNode<T>* node = new LinkedListNode<T>(data);
    size += 1;
    if (head == nullptr) {
        head = node;
        tail = head;
    } else {
        head->prev = node;
        node->next = head;
        head = node;
    }
}

template <typename T>
T LinkedList<T>::first() {
    if (head == nullptr) {
        throw std::out_of_range("Index is out of range");
    }
    return head->data;
}

template <typename T>
T LinkedList<T>::last() {
    if (tail == nullptr) {
        throw std::out_of_range("Index is out of range");
    }
    return tail->data;
}

template <typename T>
void LinkedList<T>::pop_first() {
    if (head == nullptr) {
        throw std::out_of_range("Index is out of range");
    }
    LinkedListNode<T>* temp = head;
    head = head->next;
    delete temp;
    if (size == 1) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }
    size -= 1;
}

template <typename T>
void LinkedList<T>::pop_last() {
    if (tail == nullptr) {
        throw std::out_of_range("Index is out of range");
    }
    LinkedListNode<T>* temp = tail;
    tail = tail->prev;
    delete temp;
    if (size == 1) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }
    size -= 1;
}

template <typename T>
unsigned LinkedList<T>::length() {
    return size;
}

template <typename T>
string LinkedList<T>::inorder() {
    std::string s;
    LinkedListNode<T>* curr = head;
    for (unsigned i = 0; i < size; i += 1) {
        s += std::to_string(curr->data);
        curr = curr->next;
    }
    return s;
}

template <typename T>
string LinkedList<T>::postorder() {
    std::string s;
    LinkedListNode<T>* curr = tail;
    for (unsigned i = 0; i < size; i += 1) {
        s += std::to_string(curr->data);
        curr = curr->prev;
    }
    return s;
}

#endif
