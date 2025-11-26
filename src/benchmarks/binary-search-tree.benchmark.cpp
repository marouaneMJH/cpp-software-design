// #include "../../include/index.h"
// #include "index.h"

// int bstImplementationTest()
// {
//     BSTree<long int> tree;

//     try {
//         Benchmark::run("BSTree::loadFromFile", [&]() {
//             size_t count = tree.loadFromFile("assets/big_int_numbers.txt");
//             cout << count << " loaded items form given file \n" ;

//         });
//     }
//     catch (const std::exception& ex) {
//         std::cerr << "Failed to load tree: " << ex.what() << "\n";
//         return 1;
//     }

//     std::cout << "Tree loaded successfully.\n";
//     // std::cout << "Current tree (in-order): " << tree << "\n";


//         // Insert
//     int newValue = 21;
//     std::cout << "Inserting \"" << newValue << "\"...\n";
//     Benchmark::run("BSTree::insert", [&]() {
//         tree.insert(newValue);
//     });

//     // Search
//     const int probe = 42;
//     bool found = false;
//     Benchmark::run("BSTree::search", [&]() {
//         found = tree.search(probe);
//     });
//     std::cout << "search(\"" << probe << "\"): " << (found ? "found" : "not found") << "\n";

//         // Delete
//     int  toDelete = 21;
//     std::cout << "Deleting \"" << toDelete << "\"...\n";
//     bool removed = false;
//     Benchmark::run("BSTree::remove", [&]() {
//         removed = (void(), tree.remove(toDelete), true); // keep remove behavior; capture result if needed
//     });


//     // Search
//     Benchmark::run("BSTree::search", [&]() {
//         found = tree.search(probe);
//     });
//     std::cout << "search(\"" << probe << "\"): " << (found ? "found" : "not found") << "\n";

//     Benchmark::printHistory();



//     return 0;
// }
