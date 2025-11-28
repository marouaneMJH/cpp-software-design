#include "../../benchmarks/benchmark_rb_bs_map_set.h"

#ifndef MAX_ELE
#define MAX_ELE 10'000'000
#endif

template<typename T>
void BenchmarkRbBsMapSet<T>::printHeader(const string& title) {
    cout << "===== " << title << " (" << BenchmarkHelper<T>::getTypeName() << ") =====\n";
}

//
// RBTree
//
template<typename T>
void BenchmarkRbBsMapSet<T>::benchRBTree(const string& filePath) {
    printHeader("RBTree");

    RBTree<T> tree;

    Benchmark::run("RBTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile(filePath);
        cout << count << " loaded items into RBTree\n";
    });

    Benchmark::run("RBTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::run("RBTree::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(BenchmarkHelper<T>::generateValue(i))) {
                ++foundCount;
            }
        }
        cout << "RBTree: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    Benchmark::run("RBTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

//
// AVLTree
//
template<typename T>
void BenchmarkRbBsMapSet<T>::benchAVLTree(const string& filePath) {
    printHeader("AVLTree");

    AVLTree<T> tree;

    Benchmark::run("AVLTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile(filePath);
        cout << count << " loaded items into AVLTree\n";
    });

    Benchmark::run("AVLTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::run("AVLTree::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(BenchmarkHelper<T>::generateValue(i))) {
                ++foundCount;
            }
        }
        cout << "AVLTree: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    Benchmark::run("AVLTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

//
// unordered_set
//
template<typename T>
void BenchmarkRbBsMapSet<T>::benchUnorderedSet(const string& filePath) {
    printHeader("unordered_set");

    unordered_set<T> uset;

    Benchmark::run("UnorderedSet::loadFromFile", [&]() {
        uset = DataStructureUtils::unorderedSetLoadFromFile<T>(filePath);
        cout << uset.size() << " loaded items into unordered_set\n";
    });

    Benchmark::run("UnorderedSet::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            uset.insert(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::run("UnorderedSet::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (uset.find(BenchmarkHelper<T>::generateValue(i)) != uset.end()) {
                ++foundCount;
            }
        }
        cout << "unordered_set: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    Benchmark::run("UnorderedSet::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            uset.erase(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

//
// set
//
template<typename T>
void BenchmarkRbBsMapSet<T>::benchSet(const string& filePath) {
    printHeader("set");
    set<T> oset;

    Benchmark::run("Set::loadFromFile", [&]() {
        oset = DataStructureUtils::setLoadFromFile<T>(filePath);
        cout << oset.size() << " loaded items into set\n";
    });

    Benchmark::run("Set::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            oset.insert(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::run("Set::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (oset.find(BenchmarkHelper<T>::generateValue(i)) != oset.end()) {
                ++foundCount;
            }
        }
        cout << "set: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    Benchmark::run("Set::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            oset.erase(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

//
// map<T,T>
// (we put key->value = key)
//
template<typename T>
void BenchmarkRbBsMapSet<T>::benchMap(const string& filePath) {
    printHeader("map");

    map<T, T> omap;

    Benchmark::run("Map::loadFromFile", [&]() {
        omap = DataStructureUtils::mapLoadFromFile<T, T>(filePath);
        cout << omap.size() << " loaded items into map\n";
    });

    Benchmark::run("Map::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            T key = BenchmarkHelper<T>::generateValue(i);
            omap[key] = key;
        }
    });

    Benchmark::run("Map::search(k*13) k <= MAX_ELE", [&]() {
        size_t foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            T key = BenchmarkHelper<T>::generateValue(i);
            if (omap.find(key) != omap.end()) {
                ++foundCount;
            }
        }
        cout << "map: found " << foundCount << " / " << MAX_ELE << "\n";
    });

    Benchmark::run("Map::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            omap.erase(BenchmarkHelper<T>::generateValue(i));
        }
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

//
// Entrypoint
//
template<typename T>
int BenchmarkRbBsMapSet<T>::compareBenchmarkRbBsMapSet(const string& filePath) {
    try {
        cout << YELLOW << "MAX_ELE: "<< GREEN << MAX_ELE << RESET <<  "\n";
        benchRBTree(filePath);
        benchUnorderedSet(filePath);
        benchSet(filePath);
        benchMap(filePath);
        benchAVLTree(filePath);
        return 0;
    } catch (const exception& ex) {
        cerr << "Benchmark execution failed: " << ex.what() << "\n";
        return 1;
    } catch (...) {
        cerr << "Benchmark execution failed: unknown error\n";
        return 1;
    }
}

// Explicit instantiations - only for valid types
template class BenchmarkRbBsMapSet<int>;
template class BenchmarkRbBsMapSet<long>;
template class BenchmarkRbBsMapSet<float>;
template class BenchmarkRbBsMapSet<string>;