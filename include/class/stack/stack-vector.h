#pragma once

#include <iostream>
#include <vector>

using namespace std;

// STL vector
// Linked list
// Dynamic table

template <class T>
class StackVec : public Stack<T>
{
private:
    vector<T> _data;

public:
    StackVec();

    StackVec(const StackVec *stack);

    ~StackVec();

    bool empty() const override;

    bool push(T newElement) override;

    T pop() override;

    // T getHead();

    unsigned getSize() const override;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const StackVec<U> &stack);
};

#include "./../../templates/stack-vector.tpp"