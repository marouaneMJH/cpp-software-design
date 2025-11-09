#pragma once
#include <cstdint>
#include <string>

enum class Color : std::uint8_t { Red = 0, Green = 1 };

struct Node {
    std::string key;         // the word
    std::uint32_t count = 1; // occurrences of this word
    Color color = Color::Red;
    Node* left = nullptr;
    Node* right = nullptr;

    explicit Node(std::string k) : key(std::move(k)) {}
    // Non-owning raw pointers; BST manages lifetime.
};
