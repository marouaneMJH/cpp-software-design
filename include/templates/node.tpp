#include "./../node.h"
#define TEMPLATE(T) template <class T>

TEMPLATE(T)
Node<T>::Node(T data, Node<T> *prev) : _data(data), _prev(prev)
{
}

TEMPLATE(T)
Node<T>::~Node()
{
}

TEMPLATE(T)
Node<T> *Node<T>::getPrev() const
{
    return _prev;
}
TEMPLATE(T)
T Node<T>::getData() const
{
    return _data;
}
