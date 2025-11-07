
#pragma once
template <class T>
class TreeNode
{
private:
    T _value;
    TreeNode* _left;
    TreeNode* _right;
public:
    TreeNode(T value, TreeNode* _left,TreeNode* _right);
    ~TreeNode();
    TreeNode<T> *getleft() const;
    TreeNode<T> *getright() const;
    T getData() const;
};

#include "./../../templates/treenode.tpp"