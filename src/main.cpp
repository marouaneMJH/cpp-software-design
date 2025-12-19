#include "../include/index.h"
#include "../include/benchmarks/index.h"

using namespace std::chrono;

// -------------------------------------------------------------
// Main Program
// -------------------------------------------------------------
int main(int arc, char *argv[])
{

    if (string(argv[1]) == "adaptor")
        return AdaptorBenchmark::run();
    if (string(argv[1]) == "iterator")
        return AdaptorBenchmark::run();
    if (string(argv[1]) == "math-expression")
        return AdaptorBenchmark::run();
    if (string(argv[1]) == "tree")
        return BTBenchmark::run();
    if (string(argv[1]) == "bs-tree")
        return BSTBenchmark::run();
    if (string(argv[1]) == "rb-tree")
        return RBTBenchmark::run();
    if (string(argv[1]) == "ben-rb-bs-map-set")
    {
        return !(
            !BenchmarkRbBsMapSet<int>::compareBenchmarkRbBsMapSet("assets/big_int_numbers.txt") &&
            !BenchmarkRbBsMapSet<long>::compareBenchmarkRbBsMapSet("assets/big_long_numbers.txt") &&
            !BenchmarkRbBsMapSet<float>::compareBenchmarkRbBsMapSet("assets/big_float_numbers.txt") &&
            !BenchmarkRbBsMapSet<std::string>::compareBenchmarkRbBsMapSet("assets/big_strings.txt"));
    }

    std::cout << "\nMake sure to add the tp name after the main (ex: ./build/main bs-tree)" << std::endl;

    return 1;
}
