#include "stackt.h"
#include <stdexcept>

// Define the member functions here
template <typename T>
Stackt<T>::Stackt(int s) {
    size = s;
    stackArray = new T[size];
    top = -1;
}

template <typename T>
Stackt<T>::~Stackt() {
    delete[] stackArray;
}

template <typename T>
void Stackt<T>::push(T value) {
    if (top < size - 1) {
        stackArray[++top] = value;
    } else {
        throw std::overflow_error("Stack is full");
    }
}

template <typename T>
T Stackt<T>::pop() {
    if (!isEmpty()) {
        return stackArray[top--];
    } else {
        throw std::underflow_error("Stack is empty");
    }
}

template <typename T>
bool Stackt<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
int Stackt<T>::getSize() const {
    return top + 1;
}

// Explicit instantiation of the template class for int
template class Stackt<int>;
