#ifndef RBT_TREE_H
#define RBT_TREE_H

#include <iostream>
#include <queue>
#include <string>
#include "rbt_node.h"

class RBTTree {
public:
    RBTTree();
    ~RBTTree();

    // API principale
    void insert(const std::string &key);
    RBTNode* search(const std::string &key) const;

    void inorder() const;           // parcours infixe
    void printStructure() const;    // affichage tourné pour debug
    void breadthFirst() const;      // parcours en largeur (BFS)

private:
    RBTNode *root;

    // rotations
    void leftRotate(RBTNode *x);
    void rightRotate(RBTNode *y);

    // réparation après insertion
    void insertFixup(RBTNode *z);

    // helpers
    void destroy(RBTNode *node);
    void inorderHelper(RBTNode *node) const;
    void printHelper(RBTNode *node, int depth) const;
};

#endif // RBT_TREE_H
