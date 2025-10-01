#pragma once

#include <iostream>
#define MAX_RAND_ELE 1000000
#define STACK_INSERT_ELE_COUNT 800000000

using namespace std;

template <class T>
struct Node
{
    T _data;
    Node<T> *next;
    Node<T> *_prev;
};

// STL vector
// Linked list
// Dynamic table

template <class T>
class Stack
{
private:
    Node<T> *_data;
    Node<T> *_head;
    unsigned int _size;

    void freeStack();

public:
    Stack();

    Stack(const Stack *stack);

    ~Stack();

    bool empty();

    bool push(T newElement);

    T pop();

    T getHead();

    int getSize();

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Stack<U> &stack);
};

#include "./templates/stack.tpp"