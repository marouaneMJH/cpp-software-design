#include "../include/index.h"

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include "./../include/class/data-structur.utils.h"

using namespace std::chrono;

// -------------------------------------------------------------------------
// Benchmark functions definitions (the implement exists after the main fn)
// -------------------------------------------------------------------------
int adaptorClass();

int treeImplementation();

int bstImplementationTest();

int rbtImplementationTest();



// -------------------------------------------------------------
// Main Program
// -------------------------------------------------------------
int main(int arc,  char* argv[])
{

    // Todo: a time function to truck the time of execution of each functionality

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

// ---------- treeImplementation ----------
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

// ---------- bstImplementationTest ----------
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
    RBTree<int> tree;

    // --- Load from file ---
    Benchmark::run("RBTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt");   // must contain integers
        cout << count << " loaded items form given file \n" ;
    });

    // --- Insert test ---
    Benchmark::run("RBTree::insert(42)", [&]() {
        tree.insert(42);
    });

    // --- Search test ---
    Benchmark::run("RBTree::search(42)", [&]() {
        bool found = tree.search(42);
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });

    // --- Search test ---
    Benchmark::run("RBTree::search(41)", [&]() {
        bool found = tree.search(41);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // --- Remove test ---
    Benchmark::run("RBTree::remove(42)", [&]() {
        tree.remove(42);
    });

    // --- Search test ---
    Benchmark::run("RBTree::search(42)", [&]() {
        bool found = tree.search(42);
        std::cout << "search(42) = " << (found ? "found" : "not found") << "\n";
    });


    // --- Print full benchmark history ---
    Benchmark::printHistory();

    return 0;
}