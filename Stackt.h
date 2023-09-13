#ifndef STACKT_H
#define STACKT_H

template <typename T>
class Stackt {
public:
    Stackt(int capacity);
    ~Stackt();
    bool isEmpty() const;
    bool isFull() const;
    void push(const T& item);
    void pop();
    T& top();
    const T& top() const;

private:
    T* stackArray;
    int topIndex;
    int capacity;
};

#endif
