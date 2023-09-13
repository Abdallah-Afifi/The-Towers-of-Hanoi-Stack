#ifndef STACKT_H
#define STACKT_H

template <typename T>
class Stackt {
private:
    T* stackArray;
    int size;
    int top;

public:
    Stackt(int s);
    ~Stackt();

    void push(T value);
    T pop();
    bool isEmpty() const;
    int getSize() const;
};

#endif // STACKT_H
