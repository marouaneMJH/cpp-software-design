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
    auto start = high_resolution_clock::now();
    auto pq = DataStructureUtils::vectorToPriorityQueue<std::string>(dic.getDic());
    auto end = high_resolution_clock::now();
    auto buildMs = duration_cast<milliseconds>(end - start).count();
    std::cout << "vectorToPriorityQueue() took " << buildMs << " ms\n";

    // Extract top-K elements
    const std::size_t k = 2;
    start = high_resolution_clock::now();
    topWords = DataStructureUtils::getTopK(pq, k); // pq is consumed here
    end = high_resolution_clock::now();
    auto extractMs = duration_cast<milliseconds>(end - start).count();
    std::cout << "getTopK(pq, " << k << ") executed in " << extractMs << " ms\n";

    std::cout << "The top " << k << " greatest word(s) in the file are: ";
    DataStructureUtils::printVector(topWords);

    return 0;
}

int treeImplementation()
{
    Tree<string>* t;

    t  = Dic::loadFileToTree("assets/test.txt");

    if (!t) {
        std::cerr << "Failed to load tree\n";
        return 1;
    }

    std::cout << "isEmpty(): " << std::boolalpha << t->isEmpty() << '\n';

    const std::string probe = "example";
    auto foundNode = t->find(probe);
    std::cout << "find(\"" << probe << "\"): " << (foundNode ? "found" : "not found") << '\n';

    t->addChild("inserted-node");

    std::cout << "\nprintPreOrder():\n";
    t->printPreOrder();

    std::cout << "\nprintPostOrder():\n";
    t->printPostOrder();

    std::cout << "\nprintLevelOrder():\n";
    t->printLevelOrder();

    std::cout << "\ncountNodes(): " << t->countNodes() << '\n';
    std::cout << "getHeight(): " << t->getHeight() << '\n';

    return 0;
}

int bstImplementationTest()
{
    BSTree<std::string> tree;

    try {
        tree.loadFromFile("assets/mid_long_numbers.txt");
    }
    catch (const std::exception& ex) {
        std::cerr << "Failed to load tree: " << ex.what() << "\n";
        return 1;
    }

    std::cout << "Tree loaded successfully.\n";
    std::cout << "Current tree (in-order): " << tree << "\n";

    // Search
    const std::string probe = "example";
    bool found = tree.search(probe);
    std::cout << "search(\"" << probe << "\"): "
              << (found ? "found" : "not found") << "\n";

    // Insert
    std::string newValue = "inserted-node";
    std::cout << "Inserting \"" << newValue << "\"...\n";
    tree.insert(newValue);

    std::cout << "Tree after insert: " << tree << "\n";

    // Delete
    std::string toDelete = "delete-me";
    std::cout << "Deleting \"" << toDelete << "\"...\n";
    tree.remove(toDelete);

    std::cout << "Tree after delete: " << tree << "\n";

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