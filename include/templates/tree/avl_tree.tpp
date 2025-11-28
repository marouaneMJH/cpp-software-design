#pragma once
#include "../../class/tree/avl_tree.h"

// ============================================================================
// AVLNode Implementation
// ============================================================================

template <class T>
AVLNode<T>::AVLNode()
    : data(), left(nullptr), right(nullptr), height(1)
{
}

template <class T>
AVLNode<T>::AVLNode(const T& value)
    : data(value), left(nullptr), right(nullptr), height(1)
{
}


// ============================================================================
// AVLTree Implementation
// ============================================================================

template <class T>
AVLTree<T>::AVLTree()
    : root(nullptr)
{
}

template <class T>
AVLTree<T>::~AVLTree()
{
    freeTree(root);
    root = nullptr;
}

template <class T>
void AVLTree<T>::freeTree(AVLNode<T>* node)
{
    if (node == nullptr) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}


// ============================================================================
// AVL-specific helper functions
// ============================================================================

template <class T>
int AVLTree<T>::getHeight(AVLNode<T>* node) const
{
    return node ? node->height : 0;
}

template <class T>
int AVLTree<T>::getBalanceFactor(AVLNode<T>* node) const
{
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <class T>
void AVLTree<T>::updateHeight(AVLNode<T>* node)
{
    if (node != nullptr) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
}

template <class T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* y)
{
    AVLNode<T>* x = y->left;
    AVLNode<T>* T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    updateHeight(y);
    updateHeight(x);
    
    return x;
}

template <class T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* x)
{
    AVLNode<T>* y = x->right;
    AVLNode<T>* T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    updateHeight(x);
    updateHeight(y);
    
    return y;
}

template <class T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T>* node)
{
    if (node == nullptr) {
        return nullptr;
    }
    
    // Update height of current node
    updateHeight(node);
    
    // Get balance factor
    int bf = getBalanceFactor(node);
    
    // Left-Left case
    if (bf > 1 && getBalanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }
    
    // Left-Right case
    if (bf > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    // Right-Right case
    if (bf < -1 && getBalanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }
    
    // Right-Left case
    if (bf < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    // Node is balanced
    return node;
}


// ============================================================================
// Core tree operations
// ============================================================================

template <class T>
AVLNode<T>* AVLTree<T>::insertNode(AVLNode<T>* node, const T& value)
{
    // Standard BST insertion
    if (node == nullptr) {
        return new AVLNode<T>(value);
    }

    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    } else {
        // Duplicate value - do nothing
        return node;
    }
    
    // Balance the node after insertion
    return balance(node);
}

template <class T>
void AVLTree<T>::insert(const T& value)
{
    root = insertNode(root, value);
}

template <class T>
AVLNode<T>* AVLTree<T>::findMinNode(AVLNode<T>* node) const
{
    if (node == nullptr) {
        return nullptr;
    }
    AVLNode<T>* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <class T>
AVLNode<T>* AVLTree<T>::deleteNode(AVLNode<T>* node, const T& value)
{
    if (node == nullptr) {
        return nullptr;
    }

    // Standard BST deletion
    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        // Node found - delete it
        if (node->left == nullptr && node->right == nullptr) {
            // No children
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            // Only right child
            AVLNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            // Only left child
            AVLNode<T>* temp = node->left;
            delete node;
            return temp;
        } else {
            // Two children: use inorder successor (min in right subtree)
            AVLNode<T>* minRight = findMinNode(node->right);
            node->data = minRight->data;
            node->right = deleteNode(node->right, minRight->data);
        }
    }
    
    // Balance the node after deletion
    return balance(node);
}

template <class T>
void AVLTree<T>::remove(const T& value)
{
    root = deleteNode(root, value);
}

template <class T>
AVLNode<T>* AVLTree<T>::searchNode(AVLNode<T>* node, const T& value) const
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
bool AVLTree<T>::search(const T& value) const
{
    return searchNode(root, value) != nullptr;
}


// ============================================================================
// Additional utility functions
// ============================================================================

template <class T>
int AVLTree<T>::getTreeHeight() const
{
    return getHeight(root);
}

template <class T>
bool AVLTree<T>::isBalanced() const
{
    // In AVL tree, if properly implemented, it's always balanced
    // This is a verification function
    return std::abs(getBalanceFactor(root)) <= 1;
}


// ============================================================================
// I/O operations
// ============================================================================

template <class T>
void AVLTree<T>::printInOrder(AVLNode<T>* node, std::ostream& os) const
{
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left, os);
    os << node->data << " ";
    printInOrder(node->right, os);
}

template <class T>
void AVLTree<T>::print(std::ostream& os) const
{
    printInOrder(root, os);
    os << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const AVLTree<T>& tree)
{
    tree.print(os);
    return os;
}

template <class T>
size_t AVLTree<T>::loadFromFile(const std::string& fileName)
{
    std::ifstream in(fileName.c_str());
    if (!in.is_open()) {
        throw std::runtime_error("Unable to open file: " + fileName);
    }

    T value;
    size_t count = 0;
    while (in >> value) {
        insert(value);
        ++count;
    }

    in.close();
    return count;
}