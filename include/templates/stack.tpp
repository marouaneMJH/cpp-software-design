#include "./../stack.h"

template <typename T>
StackLinked<T>::StackLinked() : _data(nullptr), _head(nullptr), _size(0) {}

template <typename T>
StackLinked<T>::~StackLinked()
{
    freeStack();
}

template <typename T>
bool StackLinked<T>::empty() const
{
    return this->_size == 0 && _head == nullptr;
}

template <typename T>
bool StackLinked<T>::push(T newElement)
{

    Node<T> *node = new Node<T>(newElement, _head);

    if (!node)
        return false;

    if (empty())
    {
        _head = node;
        _data = node;
    }
    else
    {
        _head = node;
    }

    _size++;
    return true;
}

template <typename T>
void StackLinked<T>::freeStack()
{

    while (!empty())
    {
        pop();
    }
}

template <typename T>
T StackLinked<T>::pop()
{
    if (empty())
        throw out_of_range("[-] Can't pop from the stack, stack is empty.");

    // Save the head add to free it after
    Node<T> *nodeHead = _head;
    T returnedVal = _head->getData();

    // Change the head to the prev head
    _head = _head->getPrev();
    _size--;

    delete nodeHead;

    return returnedVal;
}

template <typename T>
unsigned StackLinked<T>::getSize() const
{
    return _size;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const StackLinked<T> &stack)
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
