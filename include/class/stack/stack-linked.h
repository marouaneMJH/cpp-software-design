#pragma once

#include <iostream>

#include "./../../interface/stack.h"
#include "node.h"

using namespace std;

template <class T>
class StackLinked : public Stack<T>
{
private:
    Node<T> *_data;
    Node<T> *_head;
    unsigned int _size;

    void freeStack();

public:
    StackLinked();

    // StackLinked(const StackLinked<T> &stack);
    ~StackLinked();

    bool empty() const override;

    bool push(T newElement) override;

    T pop() override;

    unsigned getSize() const override;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const StackLinked<U> &stack);
};

#include "./../../templates/stack-linked.tpp"