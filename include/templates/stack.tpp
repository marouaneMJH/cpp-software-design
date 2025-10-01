#include "./../stack.h"
template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::Stack(const Stack *stack)
{
    if (!stack)
        return;

    if (this->empty())
    {
        _head = stack->_head;
        _data = stack->_data;
        _size = stack->_size;
    }

    _head->next = stack->_data;
    _head = stack->_head;
    _size += stack->_size;
}

template <typename T>
Stack<T>::~Stack()
{
    freeStack();
}

template <typename T>
bool Stack<T>::empty()
{
    return this->_size == 0;
}

template <typename T>
bool Stack<T>::push(T newElement)
{
    Node<T> *node = new Node<T>;
    if (!node)
        return false;
    node->_data = newElement;
    node->_prev = nullptr;
    if (this->empty())
    {
        _head = node;
        _data = node;
    }
    else
    {
        node->_prev = _head;
        _head = node;
    }
    _size++;
    return true;
}

template <typename T>
void Stack<T>::freeStack()
{

    while (!empty())
    {
        pop();
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (empty())
        throw new runtime_error("Error");

    Node<T> *nodeHead = _head;
    T returnedVal = _head->_data;

    _head = _head->_prev;
    _size--;

    delete nodeHead;

    return returnedVal;
}

template <typename T>
int Stack<T>::getSize()
{
    return _size;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack)
{
    Node<T> *current = stack._head;
    os << "[";
    while (current)
    {
        os << current->_data;
        current = current->_prev;
        if (current)
            os << ", ";
    }
    os << "]";
    return os;
}
