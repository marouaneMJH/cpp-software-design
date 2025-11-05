#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>

#include "../include/class/collections/Dictionary.hpp"
#include "../include/utils/DataStructureUtils.hpp"

using std::cout;

int runPriorityQueueDemo() {
    collections::Dictionary dict;
    if (!dict.readFromFile("assets/out_file.txt")) return 1;

    using clock = std::chrono::steady_clock;

    auto t0 = clock::now();
    auto pq = utils::DataStructureUtils::vectorToPriorityQueue<std::string>(dict.data());
    auto t1 = clock::now();
    cout << "vectorToPriorityQueue() took "
         << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
         << " ms\n";

    const std::size_t k = 2;
    t0 = clock::now();
    auto top = utils::DataStructureUtils::getTopKElements(pq, k);
    t1 = clock::now();
    cout << "getTopKElements() took "
         << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
         << " ms\n";

    cout << "Top " << k << " word(s): ";
    utils::DataStructureUtils::printVectorInline(top);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: app <mode>\n"
                     "  modes: adapter | iterator | math-expression\n";
        return 1;
    }
    const std::string mode = argv[1];
    if (mode == "adapter" || mode == "iterator" || mode == "math-expression")
        return runPriorityQueueDemo();

    std::cerr << "Unknown mode: " << mode << '\n';
    return 1;
}
