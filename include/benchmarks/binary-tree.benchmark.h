#pragma once

#include "../index.h"

// Binary Seatch tree
class BTBenchmark
{
public:
    static int run()
    {
        Tree<std::string> *t = nullptr;

        // Load into tree (benchmarked)
        Benchmark::run("Dic::loadFileToTree", [&]()
                       { t = Dic::loadFileToTree("assets/test.txt"); });

        if (!t)
        {
            std::cerr << "Failed to load tree\n";
            return 1;
        }

        std::cout << "isEmpty(): " << std::boolalpha << t->isEmpty() << '\n';

        const std::string probe = "example";
        auto foundNode = t->find(probe);
        std::cout << "find(\"" << probe << "\"): " << (foundNode ? "found" : "not found") << '\n';

        t->addChild("inserted-node");

        Benchmark::run("printPreOrder", [&]()
                       {
        std::cout << "\nprintPreOrder():\n";
        t->printPreOrder(); });

        Benchmark::run("printPostOrder", [&]()
                       {
        std::cout << "\nprintPostOrder():\n";
        t->printPostOrder(); });

        Benchmark::run("printLevelOrder", [&]()
                       {
        std::cout << "\nprintLevelOrder():\n";
        t->printLevelOrder(); });

        std::cout << "\ncountNodes(): " << t->countNodes() << '\n';
        std::cout << "getHeight(): " << t->getHeight() << '\n';

        return 0;
    }
};