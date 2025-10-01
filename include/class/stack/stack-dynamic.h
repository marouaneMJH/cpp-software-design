#pragma once

#include <iostream>
#include "./../../interface/stack.h"

#define RESIZE_FACTOR 2

template <typename T>
class StackDynamic : public Stack<T>
{
private:
    T *arr;       // Pointer to the dynamically allocated array
    int capacity; // Current capacity of the array
    int topIndex; // Index of the top element

    void resize();

public:
    StackDynamic();

    ~StackDynamic();

    bool empty() const override;
    bool push(T newElement) override;
    T pop() override;

    unsigned getSize() const override;

    T getHead();

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const StackDynamic<U> &stack);
};

#include "./../../templates/stack-dynamic.tpp"