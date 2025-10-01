#pragma once

template <class T>
class Node
{
private:
    T _data;
    Node<T> *_next;
    Node<T> *_prev;

public:
    Node(T data, Node<T> *prev, Node<T> *next = nullptr);
    ~Node();
};

#include "./templates/node.tpp"