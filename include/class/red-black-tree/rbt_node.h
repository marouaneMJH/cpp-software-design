#ifndef RBT_NODE_H
#define RBT_NODE_H

enum Color { RED, BLACK };

struct RBTNode {
    int   key;
    Color color;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;

    explicit RBTNode(int k);
};

#endif // RBT_NODE_H
