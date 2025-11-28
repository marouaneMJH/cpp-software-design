#pragma once
#include <iostream>
#include <string>

template <class T>
class AVLNode
{
public:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;

public:
    AVLNode();
    AVLNode(const T& value);
};


template <class T>
class AVLTree
{
private:
    AVLNode<T>* root;

private:
    // Internal helpers
    AVLNode<T>* insertNode(AVLNode<T>* node, const T& value);
    AVLNode<T>* deleteNode(AVLNode<T>* node, const T& value);
    AVLNode<T>* searchNode(AVLNode<T>* node, const T& value) const;
    AVLNode<T>* findMinNode(AVLNode<T>* node) const;
    void printInOrder(AVLNode<T>* node, std::ostream& os) const;
    void freeTree(AVLNode<T>* node);

    // AVL-specific helpers
    int getHeight(AVLNode<T>* node) const;
    int getBalanceFactor(AVLNode<T>* node) const;
    void updateHeight(AVLNode<T>* node);
    AVLNode<T>* rotateRight(AVLNode<T>* y);
    AVLNode<T>* rotateLeft(AVLNode<T>* x);
    AVLNode<T>* balance(AVLNode<T>* node);

public:
    AVLTree();
    ~AVLTree();

    // Core features
    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;

    // Additional utilities
    int getTreeHeight() const;
    bool isBalanced() const;

    // IO
    size_t loadFromFile(const std::string& fileName);
    void print(std::ostream& os) const;

    // Operator overload
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const AVLTree<U>& tree);
};

#include "../../templates/tree/avl_tree.tpp"