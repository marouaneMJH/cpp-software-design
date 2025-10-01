#include "./../stack-dynamic.h"

template <typename T>
StackDynamic<T>::StackDynamic()
{
    capacity = 1;
    arr = new T[capacity];
    topIndex = -1;
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
    for (int i = 0; i <= topIndex; ++i)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
}

template <typename T>
void StackDynamic<T>::push(T value)
{
    if (topIndex == capacity - 1)
        resize();

    arr[++topIndex] = value;
}

template <typename T>
T StackDynamic<T>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty!");
    }
    return arr[topIndex--];
}

template <typename T>
T StackDynamic<T>::top()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty!");
    }
    return arr[topIndex];
}

template <typename T>
bool StackDynamic<T>::isEmpty()
{
    return topIndex == -1;
}

template <typename T>
int StackDynamic<T>::size()
{
    return topIndex + 1;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const StackDynamic<U> &stack)
{
    os << "[";
    for (int i = stack.topIndex; i > 0; i--)
        os << stack.arr[i] << " ,";

    if (stack.topIndex >= 0)
        os << stack.arr[0];

    os << "]";
    return os;
}