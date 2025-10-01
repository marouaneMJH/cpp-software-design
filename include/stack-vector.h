#pragma once

#include <iostream>
#include <vector>

// #define MAX_RAND_ELE 1000000
// #define STACK_INSERT_ELE_COUNT 100

using namespace std;

// STL vector
// Linked list
// Dynamic table

template <class T>
class StackVec
{
private:
    vector<T> _data;

public:
    StackVec();

    StackVec(const StackVec *stack);

    ~StackVec();

    bool empty();

    bool push(T newElement);

    T pop();

    T getHead();

    int getSize();

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const StackVec<U> &stack);
};

#include "./templates/stack-vector.tpp"