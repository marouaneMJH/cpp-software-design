#include "../../class/helpers/benchmark-helpers.h"
#include <iostream>
#include <iomanip>

// ANSI colors
static const std::string RESET  = "\033[0m";
static const std::string GREEN  = "\033[32m";
static const std::string YELLOW = "\033[33m";
static const std::string CYAN   = "\033[36m";
static const std::string BLUE   = "\033[34m";

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
long long Benchmark::run(const std::string& label, const std::function<void()>& fn)
{
    begin();
    fn();
    long long ms = end();

    log(label, ms);
    history.push_back({ label, ms });

    return ms;
}

// Colored log
void Benchmark::log(const std::string& label, long long ms)
{
    std::cout
        << CYAN << "[Benchmark] "
        << YELLOW << label << RESET
        << " executed in "
        << GREEN << ms << " ms" << RESET
        << std::endl;
}

// Print all benchmark history entries
void Benchmark::printHistory()
{
    std::cout << BLUE << "\n=== Benchmark History ===\n" << RESET;

    for (std::size_t i = 0; i < history.size(); i++) {
        const Entry& e = history[i];

        std::cout 
            << std::setw(3) << i << " | "
            << YELLOW << e.label << RESET << " : "
            << GREEN << e.durationMs << " ms" << RESET
            << std::endl;
    }

    std::cout << std::endl;
}

// Clear history
void Benchmark::clearHistory()
{
    history.clear();
}
