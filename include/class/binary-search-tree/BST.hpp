#pragma once
#include <cstddef>   // size_t
#include <queue>
#include "TreeNode.hpp"

class BST {
public:
    BST() = default;
    ~BST();

    // Non-copyable to avoid double-free; allow moves if you like.
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void insert(const std::string& word);
    std::size_t bfs_colorize_to_green();
    bool all_green() const;
    void clear();

    std::size_t size() const noexcept { return size_; }
    Node* root() const noexcept { return root_; }

private:
    Node* root_ = nullptr;
    std::size_t size_ = 0;
};
