#pragma once

#include <iostream>

#define RESIZE_FACTOR 2

template <typename T>
class StackDynamic
{
private:
    T *arr;       // Pointer to the dynamically allocated array
    int capacity; // Current capacity of the array
    int topIndex; // Index of the top element

    void resize();

public:
    StackDynamic();

    ~StackDynamic();

    void push(T value);

    T pop();

    T top();

    bool isEmpty();

    int size();

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const StackDynamic<U> &stack);
};

#include "./templates/stack-dynamic.tpp"