#include "../class/red-black-tree/rbt_tree.h"

// ===================== CTOR / DTOR =====================

RBTTree::RBTTree() : root(nullptr) {}

RBTTree::~RBTTree() {
    destroy(root);
}

void RBTTree::destroy(RBTNode *node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// ===================== INSERT =====================

void RBTTree::insert(int key) {
    RBTNode *z = new RBTNode(key);

    RBTNode *y = nullptr;
    RBTNode *x = root;

    while (x != nullptr) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == nullptr)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    insertFixup(z);
}

// ===================== SEARCH =====================

RBTNode* RBTTree::search(int key) const {
    RBTNode *x = root;
    while (x != nullptr) {
        if (key == x->key) return x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return nullptr;
}

// ===================== INORDER =====================

void RBTTree::inorder() const {
    inorderHelper(root);
    std::cout << "\n";
}

void RBTTree::inorderHelper(RBTNode *node) const {
    if (node == nullptr) return;

    inorderHelper(node->left);
    std::cout << node->key << "(" << (node->color == RED ? "R" : "B") << ") ";
    inorderHelper(node->right);
}

// ===================== PRINT TREE =====================

void RBTTree::printStructure() const {
    printHelper(root, 0);
}

void RBTTree::printHelper(RBTNode *node, int depth) const {
    if (node == nullptr) return;

    printHelper(node->right, depth + 1);

    for (int i = 0; i < depth; i++) std::cout << "    ";
    std::cout << node->key << "[" << (node->color == RED ? "R" : "B") << "]\n";

    printHelper(node->left, depth + 1);
}

// ===================== ROTATIONS =====================

void RBTTree::leftRotate(RBTNode *x) {
    RBTNode *y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RBTTree::rightRotate(RBTNode *y) {
    RBTNode *x = y->left;
    y->left = x->right;

    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr) root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// ===================== INSERT FIXUP =====================

void RBTTree::insertFixup(RBTNode *z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTNode *y = z->parent->parent->right;

            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } 
        else { // mirror
            RBTNode *y = z->parent->parent->left;

            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}
