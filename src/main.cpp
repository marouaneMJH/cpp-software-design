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
        tree.loadFromFile("assets/int_long_file.txt");
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

    return 0;
}
