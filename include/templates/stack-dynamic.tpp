#include <algorithm>
#include "./../class/stack/stack-dynamic.h"

template <typename T>
StackDynamic<T>::StackDynamic() : _capacity(1), _topIndex(-1)
{
    _arr = new T[_capacity];
}

template <typename T>
StackDynamic<T>::~StackDynamic()
{
    delete[] _arr;
}

template <typename T>
void StackDynamic<T>::resize()
{
    _capacity *= RESIZE_FACTOR;
    T *newArr = new T[_capacity];
    std::copy(_arr, _arr + _topIndex + 1, newArr);
    delete[] _arr;
    _arr = newArr;
}

template <typename T>
bool StackDynamic<T>::push(T newElement)
{
    if (_topIndex == _capacity - 1)
        resize();
    _arr[++_topIndex] = newElement;
    return true;
}

template <typename T>
T StackDynamic<T>::pop()
{
    if (empty())
        throw std::out_of_range("Stack is empty!");
    return _arr[_topIndex--];
}

template <typename T>
T StackDynamic<T>::getHead()
{
    if (empty())
        throw std::out_of_range("Stack is empty!");
    return _arr[_topIndex];
}

template <typename T>
bool StackDynamic<T>::empty() const
{
    return _topIndex == -1;
}

template <typename T>
unsigned StackDynamic<T>::getSize() const
{
    return _topIndex + 1;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const StackDynamic<U> &stack)
{
    os << "[";
    for (int i = stack._topIndex; i >= 0; --i)
    {
        os << stack._arr[i];
        if (i > 0)
            os << ", ";
    }
    os << "]";
    return os;
}
