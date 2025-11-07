#include "./../class/tree/treenode.h"
#define TEMPLATE(T) template <class T>

TEMPLATE(T)
TreeNode<T>::TreeNode(T value, TreeNode<T> *left,TreeNode<T> *right) : _value(value), _left(left,_right(right))
{
}

TEMPLATE(T)
TreeNode<T>::~TreeNode()
{
}

TEMPLATE(T)
TreeNode<T> *TreeNode<T>::getright() const
{
    return _right;
}
TEMPLATE(T)
TreeNode<T> *TreeNode<T>::getleft() const
{
    return _left;
}
TEMPLATE(T)
T TreeNode<T>::getData() const
{
    return _value;
}