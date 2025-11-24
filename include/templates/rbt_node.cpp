#include "../class/red-black-tree/rbt_node.h"

RBTNode::RBTNode(int k)
    : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
