#pragma once

template <class T>
class Stack
{

public:
    virtual ~Stack() = default;

    virtual bool empty() const = 0;

    virtual bool push(T newElement) = 0;

    virtual T pop() = 0;

    virtual unsigned getSize() const = 0;
};