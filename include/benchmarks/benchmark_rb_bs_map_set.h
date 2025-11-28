#pragma once
#include "../index.h"


#include <type_traits>
#include <typeinfo>



// Type trait to check if type is allowed
template<typename T>
struct is_benchmark_valid : std::false_type {};

template<> struct is_benchmark_valid<int> : std::true_type {};
template<> struct is_benchmark_valid<long> : std::true_type {};
template<> struct is_benchmark_valid<float> : std::true_type {};
template<> struct is_benchmark_valid<std::string> : std::true_type {};

// Helper struct to handle type-specific operations
template<typename T>
struct BenchmarkHelper {
    static_assert(is_benchmark_valid<T>::value, 
                  "BenchmarkRbBsMapSet only supports int, long, float, and std::string");
    
    // Generate test value based on index
    static T generateValue(int index);
    
    // Get type name for display
    static std::string getTypeName();
};

// Specializations for each type
template<>
struct BenchmarkHelper<int> {
    static int generateValue(int index) {
        return index * 13;
    }
    static std::string getTypeName() { return "int"; }
};

template<>
struct BenchmarkHelper<long> {
    static long generateValue(int index) {
        return static_cast<long>(index) * 13L;
    }
    static std::string getTypeName() { return "long"; }
};

template<>
struct BenchmarkHelper<float> {
    static float generateValue(int index) {
        return static_cast<float>(index) * 13.0f;
    }
    static std::string getTypeName() { return "float"; }
};

template<>
struct BenchmarkHelper<std::string> {
    static std::string generateValue(int index) {
        // Create deterministic strings that maintain ordering
        // Format: "str_XXXXXXXXXX" where X is zero-padded index
        return "str_" + std::string(10 - std::to_string(index * 13).length(), '0') 
               + std::to_string(index * 13);
    }
    static std::string getTypeName() { return "std::string"; }
};


template<typename T>
class BenchmarkRbBsMapSet {
    static_assert(is_benchmark_valid<T>::value,
                  "BenchmarkRbBsMapSet only supports int, long, float, and std::string");

private:
    static void printHeader(const std::string& title);

public:
    static void benchRBTree(const std::string& filePath);
    static void benchAVLTree(const std::string& filePath);
    static void benchUnorderedSet(const std::string& filePath);
    static void benchSet(const std::string& filePath);
    static void benchMap(const std::string& filePath);
    
    static int compareBenchmarkRbBsMapSet(const std::string& filePath);
};

#include "../templates/benchmarks/benchmark_rb_bs_map_set.tpp"
