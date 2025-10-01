#include <algorithm>
#include "./../stack-dynamic.h"

template <typename T>
StackDynamic<T>::StackDynamic() : capacity(1), topIndex(-1)
{
    arr = new T[capacity];
}

template <typename T>
StackDynamic<T>::~StackDynamic()
{
    delete[] arr;
}

template <typename T>
void StackDynamic<T>::resize()
{
    capacity *= RESIZE_FACTOR;
    T *newArr = new T[capacity];
    std::copy(arr, arr + topIndex + 1, newArr);
    delete[] arr;
    arr = newArr;
}

template <typename T>
bool StackDynamic<T>::push(T newElement)
{
    if (topIndex == capacity - 1)
        resize();
    arr[++topIndex] = newElement;
    return true;
}

template <typename T>
T StackDynamic<T>::pop()
{
    if (empty())
        throw std::out_of_range("Stack is empty!");
    return arr[topIndex--];
}

template <typename T>
T StackDynamic<T>::getHead()
{
    if (empty())
        throw std::out_of_range("Stack is empty!");
    return arr[topIndex];
}

template <typename T>
bool StackDynamic<T>::empty() const
{
    return topIndex == -1;
}

template <typename T>
unsigned StackDynamic<T>::getSize() const
{
    return topIndex + 1;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const StackDynamic<U> &stack)
{
    os << "[";
    for (int i = stack.topIndex; i >= 0; --i)
    {
        os << stack.arr[i];
        if (i > 0)
            os << ", ";
    }
    os << "]";
    return os;
}
