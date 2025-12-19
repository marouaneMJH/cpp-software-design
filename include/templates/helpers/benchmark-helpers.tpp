#include "../../class/helpers/benchmark-helpers.h"
#include <iostream>
#include <iomanip>

// static members
std::vector<Benchmark::Entry> Benchmark::history;
std::chrono::high_resolution_clock::time_point Benchmark::startTime;
std::chrono::high_resolution_clock::time_point Benchmark::endTime;

// Start measurement
void Benchmark::begin()
{
    startTime = std::chrono::high_resolution_clock::now();
}

// End measurement
long long Benchmark::end()
{
    endTime = std::chrono::high_resolution_clock::now();
    long long ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    return ms;
}

// Execute and measure a callback function
long long Benchmark::run(const std::string &label, const std::function<void()> &fn, std::ostream &os)
{
    begin();
    fn();
    long long ms = end();

    log(label, ms, os);
    history.push_back({label, ms});

    return ms;
}

// Colored log
void Benchmark::log(const std::string &label, long long ms, std::ostream &os)
{
    os
        << CYAN << "[Benchmark] "
        << YELLOW << label << RESET
        << " executed in "
        << GREEN << ms << " ms" << RESET
        << std::endl;
}

// Print all benchmark history entries
void Benchmark::printHistory(std::ostream &os)
{
    os << BLUE << "\n=== Benchmark History ===\n"
       << RESET;

    for (std::size_t i = 0; i < history.size(); i++)
    {
        const Entry &e = history[i];

        os
            << std::setw(3) << i << " | "
            << YELLOW << e.label << RESET << " : "
            << GREEN << e.durationMs << " ms" << RESET
            << std::endl;
    }

    os << std::endl;
}

// Clear history
void Benchmark::clearHistory()
{
    history.clear();
}