#include "../../include/index.h"
#include "index.h"


int rbtImplementationTest()
{
    RBTree<int> tree;

    // --- Load from file ---
    Benchmark::run("RBTree::loadFromFile", [&]() {
        size_t count = tree.loadFromFile("assets/big_int_numbers.txt");   // must contain integers
        cout << count << " loaded items form given file \n" ;
    });

    // --- Insert test ---
    Benchmark::run("RBTree::insert(k*13) k <= 1'000'000 ", [&]() {

        for(int i=0;i<MAX_ELE;i++)
        {
            tree.insert(i*13);
        }
    });

    // --- Search test ---
    Benchmark::run("RBTree::search(k*13) k <= 1'000'000 ", [&]() {

        for(int i=0;i<100'000;i++)
        {
            bool found = tree.search(13*i);
            std::cout << "search("<<i*13<<") = " << (found ? "found" : "not found") << "\n";
        }
    });

    // --- Search test ---
    Benchmark::run("RBTree::search(41)", [&]() {
        bool found = tree.search(41);
        std::cout << "search(41) = " << (found ? "found" : "not found") << "\n";
    });

    // --- Remove test ---
    Benchmark::run("RBTree::remove(13*k) k <= 1'000'000 ", [&]() {
        for(int i=0;i<100'000;i++)
        {
            tree.remove(13*i);
        }
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