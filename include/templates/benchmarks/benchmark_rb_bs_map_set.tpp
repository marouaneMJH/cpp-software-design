#include "../../benchmarks/benchmark_rb_bs_map_set.h"

#ifndef MAX_ELE
#define MAX_ELE 10'000'000
#endif

void BenchmarkRbBsMapSet::printHeader(const std::string& title) {
    std::cout << "===== " << title << " =====\n";
}

/* RBTree<int> */
void BenchmarkRbBsMapSet::benchRBTree() {
    printHeader("RBTree<int>");
    RBTree<int> tree;

    // load
    Benchmark::run("RBTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt");
        std::cout << count << " loaded items into RBTree\n";
    });

    // insert
    Benchmark::run("RBTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) tree.insert(i * 13);
    });

    // search (summary)
    Benchmark::run("RBTree::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) if (tree.search(i * 13)) ++foundCount;
        std::cout << "RBTree: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    // remove
    Benchmark::run("RBTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) tree.remove(i * 13);
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

/* std::unordered_set<int> */
void BenchmarkRbBsMapSet::benchUnorderedSet() {
    printHeader("std::unordered_set<int>");
    std::unordered_set<int> uset;

    // load
    Benchmark::run("UnorderedSet::loadFromFile", [&]() {
        uset = DataStructureUtils::unorderedSetLoadFromFile<int>("assets/big_int_numbers.txt");
        std::cout << uset.size() << " loaded items into unordered_set\n";
    });

    // insert
    Benchmark::run("UnorderedSet::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) uset.insert(i * 13);
    });

    // search
    Benchmark::run("UnorderedSet::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) if (uset.find(i * 13) != uset.end()) ++foundCount;
        std::cout << "unordered_set: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    // remove
    Benchmark::run("UnorderedSet::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) uset.erase(i * 13);
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

/* std::set<int> */
void BenchmarkRbBsMapSet::benchSet() {
    printHeader("std::set<int>");
    std::set<int> oset;

    // load
    Benchmark::run("Set::loadFromFile", [&]() {
        oset = DataStructureUtils::setLoadFromFile<int>("assets/big_int_numbers.txt");
        std::cout << oset.size() << " loaded items into std::set\n";
    });

    // insert
    Benchmark::run("Set::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) oset.insert(i * 13);
    });

    // search
    Benchmark::run("Set::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) if (oset.find(i * 13) != oset.end()) ++foundCount;
        std::cout << "std::set: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    // remove
    Benchmark::run("Set::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) oset.erase(i * 13);
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

/* std::map<long int,long int> */
void BenchmarkRbBsMapSet::benchMap() {
    printHeader("std::map<long int,int>");
    std::map<long int, int> omap;

    // load
    Benchmark::run("Map::loadFromFile", [&]() {
        omap = DataStructureUtils::mapLoadFromFile<long int, int>("assets/big_int_numbers.txt");
        std::cout << omap.size() << " loaded items into std::map\n";
    });

    // insert
    Benchmark::run("Map::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = i* 13;
            omap[key] = key;
        }
    });

    // search
    Benchmark::run("Map::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = i* 13;
            if (omap.find(key) != omap.end()) ++foundCount;
        }
        std::cout << "std::map: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    // remove
    Benchmark::run("Map::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) omap.erase( i* 13);
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}


void BenchmarkRbBsMapSet::benAVLTree() {
    printHeader("AVLTree<int>");
    AVLTree<int> tree;

    // load
    Benchmark::run("AVLTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt");
        std::cout << count << " loaded items into AVLTree\n";
    });

    // insert
    Benchmark::run("AVLTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) tree.insert(i * 13);
    });

    // search (summary)
    Benchmark::run("AVLTree::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) if (tree.search(i * 13)) ++foundCount;
        std::cout << "AVLTree: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    // remove
    Benchmark::run("AVLTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) tree.remove(i * 13);
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}



/* Entrypoint */
int BenchmarkRbBsMapSet::compareBenchmarkRbBsMapSet() {
    try {
        std::cout << "MAX_ELE: " << MAX_ELE << "\n";
        benchRBTree();
        benchUnorderedSet();
        benchSet();
        benchMap();
        benAVLTree();
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "Benchmark execution failed: " << ex.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "Benchmark execution failed: unknown error\n";
        return 1;
    }
}
