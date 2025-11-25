// rbtree.hpp
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <queue>

enum Color { RED, BLACK };

template <class T>
class RBNode
{
public:
    T data;
    Color color;
    RBNode<T>* parent;
    RBNode<T>* left;
    RBNode<T>* right;

    RBNode();
    RBNode(const T& value, Color c, RBNode<T>* nil);
};




template <class T>
class RBTree
{
private:
    RBNode<T>* root;
    RBNode<T>* nil; // sentinel

    // helpers
    void leftRotate(RBNode<T>* x);
    void rightRotate(RBNode<T>* y);
    void insertFixup(RBNode<T>* z);
    void transplant(RBNode<T>* u, RBNode<T>* v);
    RBNode<T>* treeMinimum(RBNode<T>* x) const;
    void deleteFixup(RBNode<T>* x);
    void freeSubtree(RBNode<T>* node);

    void printInOrder(RBNode<T>* node, std::ostream& os) const;
    void printLevelOrder(std::ostream& os) const;

public:
    RBTree();
    ~RBTree();

    void insert(const T& value);
    bool remove(const T& value);
    bool search(const T& value) const;
    std::size_t loadFromFile(const std::string& fileName);


    void print(std::ostream& os) const;

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const RBTree<U>& tree);
};

#include "../../templates/tree/red_black_tree.tpp"