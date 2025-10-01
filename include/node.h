#pragma once

template <class T>
class Node
{
private:
    T _data;
    Node<T> *_prev;

public:
    Node(T data, Node<T> *prev);

    ~Node();

    Node<T> *getPrev() const;
    T getData() const;
};

#include "./templates/node.tpp"