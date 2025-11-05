#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace collections {

class Dictionary {
private:
    std::vector<std::string> data_;

    void print_(std::ostream& os) const {
        for (const auto& w : data_) os << w << ' ';
    }

public:
    Dictionary() = default;

    // Load vector data from stdin (type words, end with \exit)
    void readFromStdin() {
        std::string token;
        while (std::cin >> token) {
            if (token == "\\exit") break;
            data_.push_back(token);
        }
    }

    // Load vector data from file (path relative to running directory)
    bool readFromFile(const std::string& filePath) {
        std::ifstream in(filePath);
        if (!in.is_open()) {
            std::cerr << "Error opening \"" << filePath << "\"\n";
            return false;
        }
        std::string word;
        while (in >> word) data_.push_back(word);
        return true;
    }

    // Print first N words
    void printHead(std::size_t wordsCount) const {
        const std::size_t n = std::min(wordsCount, data_.size());
        for (std::size_t i = 0; i < n; ++i) std::cout << data_[i] << ' ';
        std::cout << '\n';
    }

    // Accessors
    std::vector<std::string>& data() { return data_; }
    const std::vector<std::string>& data() const { return data_; }

    std::size_t size() const { return data_.size(); }

    // Sort ascending (A..Z)
    void sortAscending() {
        std::sort(data_.begin(), data_.end());
    }

    // Sort descending (Z..A)
    void sortDescending() {
        std::sort(data_.begin(), data_.end(), std::greater<std::string>());
    }

    // Find first exact match
    std::vector<std::string>::iterator findFirst(const std::string& word) {
        return std::find(data_.begin(), data_.end(), word);
    }

    // Print all matches with positions
    void printAllOccurrences(const std::string& word) const {
        bool found = false;
        auto it = data_.cbegin();
        while (it != data_.cend()) {
            it = std::find(it, data_.cend(), word);
            if (it != data_.cend()) {
                std::cout << "Found \"" << *it << "\" at position: " << std::distance(data_.cbegin(), it) << '\n';
                found = true;
                ++it; // continue after this match
            }
        }
        if (!found) {
            std::cout << "Word \"" << word << "\" not found in dictionary.\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Dictionary& dic) {
        dic.print_(os);
        return os;
    }
};

} // namespace collections
