#pragma once
#include <string>
#include <vector>
#include <functional>
#include <chrono>
#include <ostream>
#include <iostream>
#include "../../shared/insi-colors.h"
class Benchmark
{
public:
    struct Entry
    {
        std::string label;
        long long durationMs;
    };

private:
    static std::vector<Entry> history;
    static std::chrono::high_resolution_clock::time_point startTime;
    static std::chrono::high_resolution_clock::time_point endTime;

public:
    Benchmark() = delete;

    static void begin();
    static long long end();
    static long long run(const std::string &label, const std::function<void()> &fn, std::ostream &os = std::cout);

    static void log(const std::string &label, long long ms, std::ostream &os = std::cout);
    static void printHistory(std::ostream &os = std::cout);

    static void clearHistory();
};

#include "../../templates/helpers/benchmark-helpers.tpp"