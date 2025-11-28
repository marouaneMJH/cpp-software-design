#include "../../benchmarks/benchmark_rb_bs_map_set.h"


// assume MAX_ELE is defined somewhere globally
#ifndef MAX_ELE
#define MAX_ELE 1000000
#endif

// Implementation

void BenchmarkRbBsMapSet::printHeader(const std::string& title) {
    std::cout << "========== " << title << " ==========\n";
}

void BenchmarkRbBsMapSet::benchRBTree() {
    printHeader("RBTree<int>");

    RBTree<int> tree;

    // Load
    Benchmark::run("RBTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt");
        std::cout << count << " loaded items from given file\n";
    });

    // Insert
    Benchmark::run("RBTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(i * 13);
        }
    });

    // Search summary
    Benchmark::run("RBTree::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(i * 13)) ++foundCount;
        }
        std::cout << "RBTree: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });

    // Single search
    Benchmark::run("RBTree::search(41)", [&]() {
        bool found = tree.search(41);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // Remove
    Benchmark::run("RBTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(i * 13);
        }
    });

    // Search after removals
    Benchmark::run("RBTree::search(42) after removals", [&]() {
        bool found = tree.search(42);
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

void BenchmarkRbBsMapSet::benchUnorderedSet() {
    printHeader("std::unordered_set<int>");

    std::unordered_set<int> unorderedSet;

    // Load
    Benchmark::run("UnorderedSet::loadFromFile", [&]() {
        try {
            unorderedSet = DataStructureUtils::unorderedSetLoadFromFile<int>("assets/big_int_numbers.txt");
            std::cout << unorderedSet.size() << " loaded items into unordered_set\n";
        } catch (const std::exception& ex) {
            std::cerr << "UnorderedSet load failed: " << ex.what() << "\n";
            throw;
        }
    });

    // Insert
    Benchmark::run("UnorderedSet::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            unorderedSet.insert(i * 13);
        }
    });

    // Search summary
    Benchmark::run("UnorderedSet::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (unorderedSet.find(i * 13) != unorderedSet.end()) ++foundCount;
        }
        std::cout << "unordered_set: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });

    // Single search
    Benchmark::run("UnorderedSet::search(41)", [&]() {
        bool found = (unorderedSet.find(41) != unorderedSet.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // Remove
    Benchmark::run("UnorderedSet::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            unorderedSet.erase(i * 13);
        }
    });

    // Search after removals
    Benchmark::run("UnorderedSet::search(42) after removals", [&]() {
        bool found = (unorderedSet.find(42) != unorderedSet.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

void BenchmarkRbBsMapSet::benchSet() {
    printHeader("std::set<int>");

    std::set<int> orderedSet;

    // Load
    Benchmark::run("Set::loadFromFile", [&]() {
        try {
            orderedSet = DataStructureUtils::setLoadFromFile<int>("assets/big_int_numbers.txt");
            std::cout << orderedSet.size() << " loaded items into std::set\n";
        } catch (const std::exception& ex) {
            std::cerr << "Set load failed: " << ex.what() << "\n";
            throw;
        }
    });

    // Insert
    Benchmark::run("Set::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            orderedSet.insert(i * 13);
        }
    });

    // Search summary
    Benchmark::run("Set::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (orderedSet.find(i * 13) != orderedSet.end()) ++foundCount;
        }
        std::cout << "std::set: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });

    // Single search
    Benchmark::run("Set::search(41)", [&]() {
        bool found = (orderedSet.find(41) != orderedSet.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // Remove
    Benchmark::run("Set::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            orderedSet.erase(i * 13);
        }
    });

    // Search after removals
    Benchmark::run("Set::search(42) after removals", [&]() {
        bool found = (orderedSet.find(42) != orderedSet.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

void BenchmarkRbBsMapSet::benchMap() {
    printHeader("std::map<long int, long int>");

    std::map<long int, long int> orderedMap;

    // Load
    Benchmark::run("Map::loadFromFile", [&]() {
        try {
            orderedMap = DataStructureUtils::mapLoadFromFile<long int, long int>("assets/big_int_numbers.txt");
            std::cout << orderedMap.size() << " loaded items from given file\n";
        } catch (const std::exception& ex) {
            std::cerr << "Map load failed: " << ex.what() << "\n";
            throw;
        }
    });

    // Insert
    Benchmark::run("Map::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            orderedMap[key] = key;
        }
    });

    // Search summary
    Benchmark::run("Map::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            if (orderedMap.find(key) != orderedMap.end()) ++foundCount;
        }
        std::cout << "Map: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });

    // Single search
    Benchmark::run("Map::search(41)", [&]() {
        bool found = (orderedMap.find(41L) != orderedMap.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // Remove
    Benchmark::run("Map::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            orderedMap.erase(key);
        }
    });

    // Search after removals
    Benchmark::run("Map::search(42) after removals", [&]() {
        bool found = (orderedMap.find(42L) != orderedMap.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

void BenchmarkRbBsMapSet::benchBSTree() {
    printHeader("BSTree<long int>");

    BSTree<long int> tree;

    // Load
    Benchmark::run("BSTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt");
        std::cout << count << " loaded items from given file\n";
    });

    // Insert
    Benchmark::run("BSTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(static_cast<long int>(i) * 13L);
        }
    });

    // Search summary
    Benchmark::run("BSTree::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(static_cast<long int>(i) * 13L)) ++foundCount;
        }
        std::cout << "BSTree: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });

    // Single search
    Benchmark::run("BSTree::search(41)", [&]() {
        bool found = tree.search(41L);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // Remove
    Benchmark::run("BSTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(static_cast<long int>(i) * 13L);
        }
    });

    // Search after removals
    Benchmark::run("BSTree::search(42) after removals", [&]() {
        bool found = tree.search(42L);
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

int BenchmarkRbBsMapSet::compareBenchmarkRbBsMapSet() {
    try {
        std::cout << "MAX_ELE: " << MAX_ELE << std::endl;

        benchRBTree();
        benchUnorderedSet();
        benchSet();
        benchMap();
        benchBSTree();

        return EXIT_SUCCESS;
    } catch (const std::exception& ex) {
        std::cerr << "Benchmark execution failed: " << ex.what() << "\n";
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Benchmark execution failed: unknown error\n";
        return EXIT_FAILURE;
    }
}
