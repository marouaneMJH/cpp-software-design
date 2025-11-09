#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <chrono>
#include "./../include/class/binary-search-tree/BST.hpp"

static inline std::string normalize_token(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    auto is_punct = [](char c){
        return !std::isalnum(static_cast<unsigned char>(c)) && c != '\'' && c != '-';
    };
    std::size_t i = 0; while (i < s.size() && is_punct(s[i])) ++i;
    std::size_t j = s.size(); while (j > i && is_punct(s[j-1])) --j;
    s = s.substr(i, j - i);
    std::string out; out.reserve(s.size());
    for (char c : s) if (std::isalnum(static_cast<unsigned char>(c)) || c=='\'' || c=='-') out.push_back(c);
    return out;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <./assets/file.txt>\n";
        return 1;
    }

    const std::string path = argv[1];
    std::ifstream in(path);
    if (!in) {
        std::cerr << "Error: cannot open file: " << path << "\n";
        return 1;
    }

    BST tree;
    std::string tok;
    std::size_t raw = 0, kept = 0;

    using clock = std::chrono::steady_clock;

    // --- Insert phase timing ---
    auto t0 = clock::now();
    while (in >> tok) {
        ++raw;
        std::string w = normalize_token(tok);
        if (!w.empty()) {
            tree.insert(w);
            ++kept;
        }
    }
    auto t1 = clock::now();

    // --- BFS phase timing ---
    auto t2 = clock::now();
    std::size_t turned = tree.bfs_colorize_to_green();
    auto t3 = clock::now();

    // Durations (ms)
    double insert_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    double bfs_ms    = std::chrono::duration<double, std::milli>(t3 - t2).count();

    // Human-readable
    std::cout << "File tokens read: " << raw << "\n";
    std::cout << "Normalized non-empty tokens inserted/updated: " << kept << "\n";
    std::cout << "Unique nodes (unique words) in BST: " << tree.size() << "\n";
    std::cout << "BFS done. Nodes turned green: " << turned
              << " | All green? " << (tree.all_green() ? "yes" : "no") << "\n";
    std::cout << "Insert time (ms): " << insert_ms << "\n";
    std::cout << "BFS time (ms): " << bfs_ms << "\n";

    // CSV (single line) — easy to append to results.csv
    #if defined(_MSC_VER)
      const char* compiler = "MSVC";
    #elif defined(__clang__)
      const char* compiler = "Clang";
    #elif defined(__GNUC__)
      const char* compiler = "GCC";
    #else
      const char* compiler = "Unknown";
    #endif

    std::cout << "RUN,Insert_ms = " << insert_ms
              << "\n BFS_ms = " << bfs_ms
              << "\n Tokens = " << raw
              << "\n Kept = " << kept
              << "\n Unique = " << tree.size()
              << "\n Compiler = " << compiler
              << "\n Build = Release"
              << "\n";

    return 0;
}
