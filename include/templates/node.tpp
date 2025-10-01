#include "./../node.h"
#define TEMPLATE(T) template <class T>

TEMPLATE(T)
Node<T>::Node(T data, Node<T> *prev, Node<T> *next) : _data(data), _prev(prev), _next(next)
{
}

TEMPLATE(T)
Node<T>::~Node()
{
}