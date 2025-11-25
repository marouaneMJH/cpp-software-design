#pragma once
#include "../../class/tree/binary_tree_search.h"


// The binary search tree default constructor
template <class T>
BSNode<T>::BSNode()
    : data(), left(nullptr), right(nullptr)
{
}


// The binary search tree  constructor with value
template <class T>
BSNode<T>::BSNode(const T& value)
    : data(value), left(nullptr), right(nullptr)
{
}


template <class T>
BSTree<T>::BSTree()
    : root(nullptr)
{
}

template <class T>
BSTree<T>::~BSTree()
{
    freeTree(root);
    root = nullptr;
}

template <class T>
void BSTree<T>::freeTree(BSNode<T>* node)
{
    if (node == nullptr) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

template <class T>
BSNode<T>* BSTree<T>::insertNode(BSNode<T>* node, const T& value)
{
    if (node == nullptr) {
        BSNode<T>* newNode = new BSNode<T>(value);
        return newNode;
    }

    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    } else {
        // value already in tree — do nothing (no duplicates)
    }
    return node;
}

template <class T>
void BSTree<T>::insert(const T& value)
{
    root = insertNode(root, value);
}

template <class T>
BSNode<T>* BSTree<T>::findMinNode(BSNode<T>* node) const
{
    if (node == nullptr) {
        return nullptr;
    }
    BSNode<T>* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <class T>
BSNode<T>* BSTree<T>::deleteNode(BSNode<T>* node, const T& value)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        // node found
        if (node->left == nullptr && node->right == nullptr) {
            // no children
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            // only right child
            BSNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            // only left child
            BSNode<T>* temp = node->left;
            delete node;
            return temp;
        } else {
            // two children: replace with inorder successor (min in right subtree)
            BSNode<T>* minRight = findMinNode(node->right);
            // copy value
            node->data = minRight->data;
            // delete successor node
            node->right = deleteNode(node->right, minRight->data);
        }
    }
    return node;
}

template <class T>
void BSTree<T>::remove(const T& value)
{
    root = deleteNode(root, value);
}

template <class T>
BSNode<T>* BSTree<T>::searchNode(BSNode<T>* node, const T& value) const
{
    if (node == nullptr) {
        return nullptr;
    }
    if (value == node->data) {
        return node;
    } else if (value < node->data) {
        return searchNode(node->left, value);
    } else {
        return searchNode(node->right, value);
    }
}

template <class T>
bool BSTree<T>::search(const T& value) const
{
    BSNode<T>* found = searchNode(root, value);
    return (found != nullptr);
}

template <class T>
void BSTree<T>::printInOrder(BSNode<T>* node, std::ostream& os) const
{
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left, os);
    os << node->data << " ";
    printInOrder(node->right, os);
}

template <class T>
void BSTree<T>::print(std::ostream& os) const
{
    printInOrder(root, os);
    os << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const BSTree<T>& tree)
{
    tree.print(os);
    return os;
}

template <class T>
size_t BSTree<T>::loadFromFile(const std::string& fileName)
{
    std::ifstream in(fileName.c_str());
    if (!in.is_open()) {
        throw std::runtime_error("Unable to open file: " + fileName);
    }

    T value;
    size_t count =0 ;
    while (in >> value) {
        insert(value);
        ++count;
    }

    in.close();
    return count;
}
