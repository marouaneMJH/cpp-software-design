#ifndef RBT_TREE_H
#define RBT_TREE_H

#include <iostream>
#include "rbt_node.h"

class RBTTree {
public:
    RBTTree();
    ~RBTTree();

    void insert(int key);
    RBTNode* search(int key) const;

    void inorder() const;
    void printStructure() const;

private:
    RBTNode *root;

    void leftRotate(RBTNode *x);
    void rightRotate(RBTNode *y);
    void insertFixup(RBTNode *z);

    void inorderHelper(RBTNode *node) const;
    void printHelper(RBTNode *node, int depth) const;
    void destroy(RBTNode *node);
};

#endif // RBT_TREE_H
