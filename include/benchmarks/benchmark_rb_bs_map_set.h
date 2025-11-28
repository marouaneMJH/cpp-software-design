#pragma once
#include "../index.h"

class BenchmarkRbBsMapSet
{
public:
    // Entry point: runs all benchmarks and returns 0 on success
    static int compareBenchmarkRbBsMapSet();

private:
    // private helpers - one per data structure
    static void benchRBTree();
    static void benchUnorderedSet();
    static void benchSet();
    static void benchMap();
    static void benchBSTree();

    // small utility for printing header
    static void printHeader(const std::string& title);
};


#include "../templates/benchmarks/benchmark_rb_bs_map_set.tpp"