#ifndef RBT_NODE_H
#define RBT_NODE_H

#include <string>

enum Color { RED, BLACK };

struct RBTNode {
    std::string key;   
    Color color;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;

    explicit RBTNode(const std::string &k);
};

#endif // RBT_NODE_H
