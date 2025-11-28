#include <iostream>
#include "../include/class/red-black-tree/rbt_tree.h"

int main() {
    RBTTree tree;

    int values[] = {77,14,93,32,5,9,93,12,72,81};
    int n = sizeof(values) / sizeof(values[0]);

    std::cout << "Inserting: ";
    for (int i = 0; i < n; ++i) {
        std::cout << values[i] << " ";
        tree.insert(values[i]);
    }
    std::cout << "\n\n";

    std::cout << "Inorder traversal:\n";
    tree.inorder();

    std::cout << "\nTree structure:\n";
    tree.printStructure();

    int look = 12;
    std::cout << "\nSearching for " << look << "...\n";
    RBTNode* res = tree.search(look);

    if (res)
        std::cout << "Found " << res->key << " (" 
                  << (res->color == RED ? "RED" : "BLACK")
                  << ")\n";
    else
        std::cout << "Not found.\n";

    return 0;
}
