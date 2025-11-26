#include "../../include/index.h"
#include "index.h"




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
