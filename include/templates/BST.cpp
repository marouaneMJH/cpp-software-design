#include "./../class/binary-search-tree/BST.hpp"
#include <vector>
#include <algorithm>

BST::~BST() { clear(); }

void BST::insert(const std::string& word) {
    if (!root_) {
        root_ = new Node(word);
        ++size_;
        return;
    }
    Node* cur = root_;
    for (;;) {
        if (word < cur->key) {
            if (cur->left) cur = cur->left;
            else { cur->left = new Node(word); ++size_; return; }
        } else if (word > cur->key) {
            if (cur->right) cur = cur->right;
            else { cur->right = new Node(word); ++size_; return; }
        } else {
            ++cur->count; // duplicate: bump frequency
            return;
        }
    }
}

std::size_t BST::bfs_colorize_to_green() {
    if (!root_) return 0;
    std::queue<Node*> q;
    q.push(root_);
    std::size_t changed = 0;

    while (!q.empty()) {
        Node* n = q.front(); q.pop();

        if (n->color == Color::Red) {
            n->color = Color::Green;
            ++changed;
        }
        if (n->left)  q.push(n->left);
        if (n->right) q.push(n->right);
    }
    return changed;
}

bool BST::all_green() const {
    if (!root_) return true;
    std::queue<const Node*> q;
    q.push(root_);
    while (!q.empty()) {
        const Node* n = q.front(); q.pop();
        if (n->color != Color::Green) return false;
        if (n->left)  q.push(n->left);
        if (n->right) q.push(n->right);
    }
    return true;
}

void BST::clear() {
    if (!root_) return;
    // Iterative post-order to avoid recursion depth issues on large trees
    std::vector<Node*> stack;
    Node* cur = root_;
    Node* last = nullptr;

    while (cur || !stack.empty()) {
        if (cur) {
            stack.push_back(cur);
            cur = cur->left;
        } else {
            Node* peek = stack.back();
            if (peek->right && last != peek->right) {
                cur = peek->right;
            } else {
                stack.pop_back();
                last = peek;
                delete peek;
            }
        }
    }
    root_ = nullptr;
    size_ = 0;
}
