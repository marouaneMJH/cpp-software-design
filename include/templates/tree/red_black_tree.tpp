// rbtree.hpp
#pragma once
#include "../../class/tree/red_black_tree.h"

template <class T>
RBNode<T>::RBNode()
    : data(), color(BLACK), parent(nullptr), left(nullptr), right(nullptr)
{
}

template <class T>
RBNode<T>::RBNode(const T& value, Color c, RBNode<T>* nil)
    : data(value), color(c), parent(nil), left(nil), right(nil)
{
}

template <class T>
RBTree<T>::RBTree()
{
    nil = new RBNode<T>(); // default node is black with nullptrs
    nil->parent = nil;
    nil->left = nil;
    nil->right = nil;
    root = nil;
}

template <class T>
RBTree<T>::~RBTree()
{
    freeSubtree(root);
    delete nil;
    nil = nullptr;
    root = nullptr;
}

template <class T>
void RBTree<T>::freeSubtree(RBNode<T>* node)
{
    if (node == nil) {
        return;
    }
    freeSubtree(node->left);
    freeSubtree(node->right);
    delete node;
}

template <class T>
void RBTree<T>::leftRotate(RBNode<T>* x)
{
    RBNode<T>* y = x->right;
    x->right = y->left;
    if (y->left != nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

template <class T>
void RBTree<T>::rightRotate(RBNode<T>* y)
{
    RBNode<T>* x = y->left;
    y->left = x->right;
    if (x->right != nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

template <class T>
void RBTree<T>::insert(const T& value)
{
    RBNode<T>* z = new RBNode<T>(value, RED, nil);
    RBNode<T>* y = nil;
    RBNode<T>* x = root;

    while (x != nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else if (z->data > x->data) {
            x = x->right;
        } else {
            // duplicate: don't insert, free and return
            delete z;
            return;
        }
    }
    z->parent = y;
    if (y == nil) {
        root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = RED;

    insertFixup(z);
}

template <class T>
void RBTree<T>::insertFixup(RBNode<T>* z)
{
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode<T>* y = z->parent->parent->right; // uncle
            if (y->color == RED) {
                // case 1
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    // case 2
                    z = z->parent;
                    leftRotate(z);
                }
                // case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            // mirror
            RBNode<T>* y = z->parent->parent->left; // uncle
            if (y->color == RED) {
                // case 1
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    // case 2
                    z = z->parent;
                    rightRotate(z);
                }
                // case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

template <class T>
RBNode<T>* RBTree<T>::treeMinimum(RBNode<T>* x) const
{
    while (x->left != nil) {
        x = x->left;
    }
    return x;
}

template <class T>
void RBTree<T>::transplant(RBNode<T>* u, RBNode<T>* v)
{
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template <class T>
bool RBTree<T>::remove(const T& value)
{
    RBNode<T>* z = root;
    while (z != nil) {
        if (value == z->data) {
            break;
        } else if (value < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == nil) {
        // not found
        return false;
    }

    RBNode<T>* y = z;
    Color yOriginalColor = y->color;
    RBNode<T>* x = nullptr;

    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = treeMinimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;

    if (yOriginalColor == BLACK) {
        deleteFixup(x);
    }
    return true;
}

template <class T>
void RBTree<T>::deleteFixup(RBNode<T>* x)
{
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode<T>* w = x->parent->right;
            if (w->color == RED) {
                // case 1
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                // case 2
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    // case 3
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                // case 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            // mirror
            RBNode<T>* w = x->parent->left;
            if (w->color == RED) {
                // case 1
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                // case 2
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    // case 3
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                // case 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

template <class T>
bool RBTree<T>::search(const T& value) const
{
    RBNode<T>* current = root;
    while (current != nil) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

template <class T>
std::size_t RBTree<T>::loadFromFile(const std::string& fileName)
{
    std::ifstream in(fileName.c_str());
    if (!in.is_open()) {
        throw std::runtime_error("RBTree::loadFromFile: Unable to open file: " + fileName);
    }


    // optional : clear existing tree before loading
    freeSubtree(root);
    root = nil;

    T value;
    std::size_t count = 0;
    while (in >> value) {
        insert(value);
        ++count;
    }

    in.close();
    return count;
}

template <class T>
void RBTree<T>::printInOrder(RBNode<T>* node, std::ostream& os) const
{
    if (node == nil) {
        return;
    }
    printInOrder(node->left, os);
    os << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
    printInOrder(node->right, os);
}

template <class T>
void RBTree<T>::printLevelOrder(std::ostream& os) const
{
    if (root == nil) {
        return;
    }
    std::queue<RBNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        RBNode<T>* node = q.front();
        q.pop();
        if (node == nil) {
            continue;
        }
        os << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
        if (node->left != nil) q.push(node->left);
        if (node->right != nil) q.push(node->right);
    }
}

template <class T>
void RBTree<T>::print(std::ostream& os) const
{
    printInOrder(root, os);
    os << std::endl;
}

template <class U>
std::ostream& operator<<(std::ostream& os, const RBTree<U>& tree)
{
    tree.print(os);
    return os;
}
