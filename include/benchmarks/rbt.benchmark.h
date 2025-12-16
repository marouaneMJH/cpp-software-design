#pragma once

#include "../index.h"

class RBTBenchmark
{
public:
    // Static method to benchmark the BST
    static int run()
    {

        cout << RED << "MAX_ELE: " << YELLOW << MAX_ELE << endl;

        // --- RBTree ---
        {
            RBTree<int> tree;

            // --- Load from file ---
            Benchmark::run("RBTree::loadFromFile", [&]()
                           {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt"); // must contain integers
        std::cout << count << " loaded items from given file\n"; });

            // --- Insert test ---
            Benchmark::run("RBTree::insert(k*13) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(i * 13);
        } });

            // --- Search test (batch, summary) ---
            Benchmark::run("RBTree::search(k*13) k <= MAX_ELE (summary)", [&]()
                           {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(i * 13)) ++foundCount;
        }
        std::cout << "RBTree: found " << foundCount << " / MAX_ELE searched keys\n"; });

            // --- Single search checks ---
            Benchmark::run("RBTree::search(41)", [&]()
                           {
        bool found = tree.search(41);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n"; });

            // --- Remove test ---
            Benchmark::run("RBTree::remove(13*k) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(i * 13);
        } });

            Benchmark::run("RBTree::search(42) after removals", [&]()
                           {
        bool found = tree.search(42);
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n"; });

            Benchmark::printHistory();
            Benchmark::clearHistory();
        }

        // --- unordered_set ---
        {
            // If DataStructureUtils provides a loader that returns std::unordered_set<int>
            std::unordered_set<int> unorderedSet;

            Benchmark::run("UnorderedSet::loadFromFile", [&]()
                           {
        unorderedSet = DataStructureUtils::unorderedSetLoadFromFile<int>("assets/big_int_numbers.txt");
        std::cout << unorderedSet.size() << " loaded items into unordered_set\n"; });

            Benchmark::run("UnorderedSet::insert(k*13) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
    // set
    // sorted BST
            unorderedSet.insert(i * 13);
        } });

            Benchmark::run("UnorderedSet::search(k*13) k <= MAX_ELE (summary)", [&]()
                           {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (unorderedSet.find(i * 13) != unorderedSet.end()) ++foundCount;
        }
        std::cout << "unordered_set: found " << foundCount << " / MAX_ELE searched keys\n"; });

            Benchmark::run("UnorderedSet::search(41)", [&]()
                           {
        bool found = (unorderedSet.find(41) != unorderedSet.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n"; });

            Benchmark::run("UnorderedSet::remove(13*k) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            unorderedSet.erase(i * 13);
        } });

            Benchmark::run("UnorderedSet::search(42) after removals", [&]()
                           {
        bool found = (unorderedSet.find(42) != unorderedSet.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n"; });

            Benchmark::printHistory();
            Benchmark::clearHistory();
        }

        // --- std::set (sorted BST / red-black in libstdc++ typically) ---
        {
            std::set<int> orderedSet;

            Benchmark::run("Set::loadFromFile", [&]()
                           {
        orderedSet = DataStructureUtils::setLoadFromFile<int>("assets/big_int_numbers.txt");
        std::cout << orderedSet.size() << " loaded items into std::set\n"; });

            Benchmark::run("Set::insert(k*13) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            orderedSet.insert(i * 13);
        } });

            Benchmark::run("Set::search(k*13) k <= MAX_ELE (summary)", [&]()
                           {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (orderedSet.find(i * 13) != orderedSet.end()) ++foundCount;
        }
        std::cout << "std::set: found " << foundCount << " / 100000 searched keys\n"; });

            Benchmark::run("Set::search(41)", [&]()
                           {
        bool found = (orderedSet.find(41) != orderedSet.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n"; });

            Benchmark::run("Set::remove(13*k) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            orderedSet.erase(i * 13);
        } });

            Benchmark::run("Set::search(42) after removals", [&]()
                           {
        bool found = (orderedSet.find(42) != orderedSet.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n"; });

            Benchmark::printHistory();
            Benchmark::clearHistory();
        }

        // --- std::map<long int, long int> ---
        {
            std::map<long int, int> orderedMap;

            // --- Load from file ---
            Benchmark::run("Map::loadFromFile", [&]()
                           {
        orderedMap = DataStructureUtils::mapLoadFromFile<long int,int>("assets/big_int_numbers.txt");
        std::cout << orderedMap.size() << " loaded items from given file\n"; });

            // --- Insert test ---
            Benchmark::run("Map::insert(k*13) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            orderedMap[key] = key;
        } });

            // --- Search test (batch, summary) ---
            Benchmark::run("Map::search(k*13) k <= MAX_ELE (summary)", [&]()
                           {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            if (orderedMap.find(key) != orderedMap.end()) ++foundCount;
        }
        std::cout << "Map: found " << foundCount << " / " << MAX_ELE << " searched keys\n"; });

            // --- Remove test ---
            Benchmark::run("Map::remove(13*k) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            orderedMap.erase(key);
        } });

            Benchmark::printHistory();
            Benchmark::clearHistory();
        }

        // --- BSTree<long int> ---
        {
            BSTree<long int> tree;

            // --- Load from file ---
            Benchmark::run("BSTree::loadFromFile", [&]()
                           {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt"); // must contain integers
        std::cout << count << " loaded items from given file\n"; });

            // --- Insert test ---
            Benchmark::run("BSTree::insert(k*13) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(static_cast<long int>(i) * 13L);
        } });

            // --- Search test (batch, summary) ---
            Benchmark::run("BSTree::search(k*13) k <= MAX_ELE (summary)", [&]()
                           {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(static_cast<long int>(i) * 13L)) ++foundCount;
        }
        std::cout << "BSTree: found " << foundCount << " / " << MAX_ELE << " searched keys\n"; });

            // --- Single search checks ---
            Benchmark::run("BSTree::search(41)", [&]()
                           {
        bool found = tree.search(41L);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n"; });

            // --- Remove test ---
            Benchmark::run("BSTree::remove(13*k) k <= MAX_ELE", [&]()
                           {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(static_cast<long int>(i) * 13L);
        } });

            Benchmark::printHistory();
            Benchmark::clearHistory();
        }

        return 0;
    }
};