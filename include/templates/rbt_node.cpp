#include "../class/red-black-tree/rbt_node.h"

RBTNode::RBTNode(const std::string &k)
    : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
