#include "./../stack-vector.h"
template <typename T>
StackVec<T>::StackVec()
{
}

template <typename T>
StackVec<T>::StackVec(const StackVec *stack)
{
}

template <typename T>
StackVec<T>::~StackVec()
{
}

template <typename T>
bool StackVec<T>::empty()
{
    return _data.size() == 0;
}

template <typename T>
bool StackVec<T>::push(T newElement)
{
    _data.push_back(newElement);
    return true;
}

template <typename T>
T StackVec<T>::pop()
{
    if (_data.empty())
    {
        throw std::out_of_range("StackVec::pop(): empty stack");
    }
    T returnedVal = _data.back();
    _data.pop_back();
    return returnedVal;
}

template <typename T>
int StackVec<T>::getSize()
{
    return _data.size();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const StackVec<T> &stack)
{
    os << "[";
    for (int i = stack._data.size() - 1; i > 0; i--)
        os << stack._data[i] << ", ";

    os << stack._data[0];

    os
        << "]";
    return os;
}
