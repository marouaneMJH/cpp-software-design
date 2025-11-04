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

    dic.readFromFile("assets/out_file.txt");

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

    return 0;
}
