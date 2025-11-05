#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <vector>

namespace utils {

class DataStructureUtils {
public:
    // Generate random integers in [min, max]
    static std::vector<int> generateRandomIntegers(std::size_t count, int min, int max) {
        std::vector<int> numbers;
        numbers.reserve(count);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min, max);

        for (std::size_t i = 0; i < count; ++i) {
            numbers.push_back(dist(gen));
        }
        return numbers;
    }

    // Fill a stack from a vector (copying, top will be last element of vector)
    template <class T>
    static std::stack<T> fillStackFromVector(const std::vector<T>& data) {
        std::stack<T> s;
        for (const auto& item : data) s.push(item);
        return s;
    }

    // Convert stack -> priority_queue (consumes 's')
    template <class T>
    static std::priority_queue<T> stackToPriorityQueue(std::stack<T>& s) {
        std::priority_queue<T> pq;
        while (!s.empty()) {
            pq.push(s.top());
            s.pop();
        }
        return pq;
    }

    // Convert any container -> priority_queue with custom comparator
    template <
        typename T,
        typename InputContainer,
        typename Container = std::vector<T>,
        typename Compare = std::less<T> // strict weak ordering (fixes less_equal bug)
    >
    static std::priority_queue<T, Container, Compare>
    containerToPriorityQueue(const InputContainer& input) {
        std::priority_queue<T, Container, Compare> pq;
        for (const auto& item : input) pq.push(item);
        return pq;
    }

    // Wrapper: vector -> priority_queue
    template <
        typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<T>
    >
    static std::priority_queue<T, Container, Compare>
    vectorToPriorityQueue(const std::vector<T>& v) {
        return containerToPriorityQueue<T, std::vector<T>, Container, Compare>(v);
    }

    // Extract top-K elements (consumes 'pq')
    template <typename T, typename Container, typename Compare>
    static std::vector<T> getTopKElements(std::priority_queue<T, Container, Compare>& pq, std::size_t k) {
        std::vector<T> result;
        k = std::min<std::size_t>(k, pq.size());
        result.reserve(k);
        for (std::size_t i = 0; i < k; ++i) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }

    // Print vector on one line
    template <class T>
    static void printVectorInline(const std::vector<T>& v, std::ostream& os = std::cout) {
        for (const auto& item : v) os << "'" << item << "'\t";
        os << '\n';
    }
};

} // namespace utils
