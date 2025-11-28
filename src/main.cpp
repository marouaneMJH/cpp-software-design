#include "../include/index.h"
#include "../include/benchmarks/index.h"


using namespace std::chrono;

// -------------------------------------------------------------------------
// Benchmark functions definitions (the implement exists after the main fn)
// -------------------------------------------------------------------------
int adaptorClass();

int treeImplementation();

int bstImplementationTest();

int rbtImplementationTest();

// todo: bnenchmark functionality compares between rb-tree, bs-tree, set, map

/**
 * - Benchmark for rb,set,map,bs with:
 * - Insertion (loading a random numbers from a file)
 * - Insertion sorted numbers
 * - Deleting the sorted numbers
 * - Search for all the sorted numbers
*/

// -------------------------------------------------------------
// Main Program
// -------------------------------------------------------------
int main(int arc,  char* argv[])
{

    if(string(argv[1]) == "adaptor")
        return adaptorClass();
    if(string(argv[1]) == "iterator")
        return adaptorClass();
    if(string(argv[1]) == "math-expression")
        return adaptorClass();
    if(string(argv[1]) == "tree")
        return treeImplementation();
    if(string(argv[1]) == "bs-tree")
        return bstImplementationTest();
    if(string(argv[1]) == "rb-tree")
        return rbtImplementationTest();
    if(string(argv[1]) == "ben-rb-bs-map-set")
    {
        return 
        !(
            !BenchmarkRbBsMapSet<int>::compareBenchmarkRbBsMapSet("assets/big_int_numbers.txt") &&
            !BenchmarkRbBsMapSet<long>::compareBenchmarkRbBsMapSet("assets/big_long_numbers.txt") &&
            !BenchmarkRbBsMapSet<float>::compareBenchmarkRbBsMapSet("assets/big_float_numbers.txt") &&
            !BenchmarkRbBsMapSet<std::string>::compareBenchmarkRbBsMapSet("assets/big_strings.txt")
        );
    }

    printf("\nMake sure to add the tp name after the main (ex: ./build/main bs-tree)");

    return 1;
}



int adaptorClass()
{
    Dic dic;
    std::vector<std::string> topWords;

    dic.readFromFile("assets/long-file.txt");

    // Measure time to build priority queue from vector
    decltype(DataStructureUtils::vectorToPriorityQueue<std::string>(dic.getDic())) pq;
    Benchmark::run("vectorToPriorityQueue", [&]() {
        pq = DataStructureUtils::vectorToPriorityQueue<std::string>(dic.getDic());
    });

    // Extract top-K elements
    const std::size_t k = 2;
    Benchmark::run("getTopK", [&]() {
        topWords = DataStructureUtils::getTopK(pq, k); // pq is consumed here
    });

    std::cout << "The top " << k << " greatest word(s) in the file are: ";
    DataStructureUtils::printVector(topWords);

    return 0;
}

int treeImplementation()
{
    Tree<std::string>* t = nullptr;

    // Load into tree (benchmarked)
    Benchmark::run("Dic::loadFileToTree", [&]() {
        t = Dic::loadFileToTree("assets/test.txt");
    });

    if (!t) {
        std::cerr << "Failed to load tree\n";
        return 1;
    }

    std::cout << "isEmpty(): " << std::boolalpha << t->isEmpty() << '\n';

    const std::string probe = "example";
    auto foundNode = t->find(probe);
    std::cout << "find(\"" << probe << "\"): " << (foundNode ? "found" : "not found") << '\n';

    t->addChild("inserted-node");

    Benchmark::run("printPreOrder", [&]() {
        std::cout << "\nprintPreOrder():\n";
        t->printPreOrder();
    });

    Benchmark::run("printPostOrder", [&]() {
        std::cout << "\nprintPostOrder():\n";
        t->printPostOrder();
    });

    Benchmark::run("printLevelOrder", [&]() {
        std::cout << "\nprintLevelOrder():\n";
        t->printLevelOrder();
    });

    std::cout << "\ncountNodes(): " << t->countNodes() << '\n';
    std::cout << "getHeight(): " << t->getHeight() << '\n';

    return 0;
}

int bstImplementationTest()
{
    BSTree<long int> tree;

    try {
        Benchmark::run("BSTree::loadFromFile", [&]() {
            size_t count = tree.loadFromFile("assets/big_int_numbers.txt");
            cout << count << " loaded items form given file \n" ;

        });
    }
    catch (const std::exception& ex) {
        std::cerr << "Failed to load tree: " << ex.what() << "\n";
        return 1;
    }

    std::cout << "Tree loaded successfully.\n";
    // std::cout << "Current tree (in-order): " << tree << "\n";


        // Insert
    int newValue = 21;
    std::cout << "Inserting \"" << newValue << "\"...\n";
    Benchmark::run("BSTree::insert", [&]() {
        tree.insert(newValue);
    });

    // Search
    const int probe = 42;
    bool found = false;
    Benchmark::run("BSTree::search", [&]() {
        found = tree.search(probe);
    });
    std::cout << "search(\"" << probe << "\"): " << (found ? "found" : "not found") << "\n";

        // Delete
    int  toDelete = 21;
    std::cout << "Deleting \"" << toDelete << "\"...\n";
    bool removed = false;
    Benchmark::run("BSTree::remove", [&]() {
        removed = (void(), tree.remove(toDelete), true); // keep remove behavior; capture result if needed
    });


    // Search
    Benchmark::run("BSTree::search", [&]() {
        found = tree.search(probe);
    });
    std::cout << "search(\"" << probe << "\"): " << (found ? "found" : "not found") << "\n";

    Benchmark::printHistory();



    return 0;
}

int rbtImplementationTest()
{
    cout << RED << "MAX_ELE: " << YELLOW << MAX_ELE << endl;
    
    // --- RBTree ---
{
    RBTree<int> tree;

    // --- Load from file ---
    Benchmark::run("RBTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt"); // must contain integers
        std::cout << count << " loaded items from given file\n";
    });

    // --- Insert test ---
    Benchmark::run("RBTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(i * 13);
        }
    });

    // --- Search test (batch, summary) ---
    Benchmark::run("RBTree::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(i * 13)) ++foundCount;
        }
        std::cout << "RBTree: found " << foundCount << " / MAX_ELE searched keys\n";
    });

    // --- Single search checks ---
    Benchmark::run("RBTree::search(41)", [&]() {
        bool found = tree.search(41);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // --- Remove test ---
    Benchmark::run("RBTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(i * 13);
        }
    });

    Benchmark::run("RBTree::search(42) after removals", [&]() {
        bool found = tree.search(42);
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

// --- unordered_set ---
{
    // If DataStructureUtils provides a loader that returns std::unordered_set<int>
    std::unordered_set<int> unorderedSet;

    Benchmark::run("UnorderedSet::loadFromFile", [&]() {
        unorderedSet = DataStructureUtils::unorderedSetLoadFromFile<int>("assets/big_int_numbers.txt");
        std::cout << unorderedSet.size() << " loaded items into unordered_set\n";
    });

    Benchmark::run("UnorderedSet::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
    // set
    // sorted BST
            unorderedSet.insert(i * 13);
        }
    });

    Benchmark::run("UnorderedSet::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (unorderedSet.find(i * 13) != unorderedSet.end()) ++foundCount;
        }
        std::cout << "unordered_set: found " << foundCount << " / MAX_ELE searched keys\n";
    });

    Benchmark::run("UnorderedSet::search(41)", [&]() {
        bool found = (unorderedSet.find(41) != unorderedSet.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::run("UnorderedSet::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            unorderedSet.erase(i * 13);
        }
    });

    Benchmark::run("UnorderedSet::search(42) after removals", [&]() {
        bool found = (unorderedSet.find(42) != unorderedSet.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

// --- std::set (sorted BST / red-black in libstdc++ typically) ---
{
    std::set<int> orderedSet;

    Benchmark::run("Set::loadFromFile", [&]() {
        orderedSet = DataStructureUtils::setLoadFromFile<int>("assets/big_int_numbers.txt");
        std::cout << orderedSet.size() << " loaded items into std::set\n";
    });

    Benchmark::run("Set::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            orderedSet.insert(i * 13);
        }
    });

    Benchmark::run("Set::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (orderedSet.find(i * 13) != orderedSet.end()) ++foundCount;
        }
        std::cout << "std::set: found " << foundCount << " / 100000 searched keys\n";
    });

    Benchmark::run("Set::search(41)", [&]() {
        bool found = (orderedSet.find(41) != orderedSet.end());
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::run("Set::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            orderedSet.erase(i * 13);
        }
    });

    Benchmark::run("Set::search(42) after removals", [&]() {
        bool found = (orderedSet.find(42) != orderedSet.end());
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}

// --- std::map<long int, long int> ---
{
    std::map<long int, int> orderedMap;

    // --- Load from file ---
    Benchmark::run("Map::loadFromFile", [&]() {
        orderedMap = DataStructureUtils::mapLoadFromFile<long int,int>("assets/big_int_numbers.txt");
        std::cout << orderedMap.size() << " loaded items from given file\n";
    });

    // --- Insert test ---
    Benchmark::run("Map::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            orderedMap[key] = key;
        }
    });

    // --- Search test (batch, summary) ---
    Benchmark::run("Map::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            if (orderedMap.find(key) != orderedMap.end()) ++foundCount;
        }
        std::cout << "Map: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });


    // --- Remove test ---
    Benchmark::run("Map::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            long int key = static_cast<long int>(i) * 13L;
            orderedMap.erase(key);
        }
    });

    Benchmark::printHistory();
    Benchmark::clearHistory();
}


// --- BSTree<long int> ---
{
    BSTree<long int> tree;


    // --- Load from file ---
    Benchmark::run("BSTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt"); // must contain integers
        std::cout << count << " loaded items from given file\n";
    });

    // --- Insert test ---
    Benchmark::run("BSTree::insert(k*13) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.insert(static_cast<long int>(i) * 13L);
        }
    });

    // --- Search test (batch, summary) ---
    Benchmark::run("BSTree::search(k*13) k <= MAX_ELE (summary)", [&]() {
        int foundCount = 0;
        for (int i = 0; i < MAX_ELE; ++i) {
            if (tree.search(static_cast<long int>(i) * 13L)) ++foundCount;
        }
        std::cout << "BSTree: found " << foundCount << " / " << MAX_ELE << " searched keys\n";
    });

    // --- Single search checks ---
    Benchmark::run("BSTree::search(41)", [&]() {
        bool found = tree.search(41L);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // --- Remove test ---
    Benchmark::run("BSTree::remove(13*k) k <= MAX_ELE", [&]() {
        for (int i = 0; i < MAX_ELE; ++i) {
            tree.remove(static_cast<long int>(i) * 13L);
        }
    });


    Benchmark::printHistory();
    Benchmark::clearHistory();
}



    return 0;
}
