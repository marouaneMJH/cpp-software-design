#pragma once
#include <iostream>
#include <string>

template <class T>
class BSNode
{
public:
    T data;
    BSNode<T>* left;
    BSNode<T>* right;

public:
    BSNode();
    BSNode(const T& value);

    // No copy/move for now — can be added later
};


template <class T>
class BSTree
{
private:
    BSNode<T>* root;

private:
    // Internal helpers
    BSNode<T>* insertNode(BSNode<T>* node, const T& value);
    BSNode<T>* deleteNode(BSNode<T>* node, const T& value);
    BSNode<T>* searchNode(BSNode<T>* node, const T& value) const;
    BSNode<T>* findMinNode(BSNode<T>* node) const;
    void printInOrder(BSNode<T>* node, std::ostream& os) const;
    void freeTree(BSNode<T>* node);

public:
    BSTree();
    ~BSTree();

    // Core features
    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;

    // IO
    size_t loadFromFile(const std::string& fileName);
    void print(std::ostream& os) const;

    // Operator overload
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const BSTree<U>& tree);
};

#include "../../templates/tree/binary_searrch_tree.tpp"