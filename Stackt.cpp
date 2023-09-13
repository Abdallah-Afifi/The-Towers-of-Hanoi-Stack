#include "Stackt.h"
#include <stdexcept>

template <typename T>
Stackt<T>::Stackt(int capacity) : capacity(capacity), topIndex(-1) {
    stackArray = new T[capacity];
}

template <typename T>
Stackt<T>::~Stackt() {
    delete[] stackArray;
}

template <typename T>
bool Stackt<T>::isEmpty() const {
    return topIndex == -1;
}

template <typename T>
bool Stackt<T>::isFull() const {
    return topIndex == capacity - 1;
}

template <typename T>
void Stackt<T>::push(const T& item) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    stackArray[++topIndex] = item;
}

template <typename T>
void Stackt<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    --topIndex;
}

template <typename T>
T& Stackt<T>::top() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return stackArray[topIndex];
}

template <typename T>
const T& Stackt<T>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return stackArray[topIndex];
}
