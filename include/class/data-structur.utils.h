#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <random>
#include <algorithm>

class DataStructureUtils
{
public:
    // -------------------------------------------------------------
    // Generate random integers in a given range
    // -------------------------------------------------------------
    static std::vector<int> generateRandomNumbers(std::size_t count, int min, int max)
    {
        std::vector<int> numbers;
        numbers.reserve(count);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);

        for (std::size_t i = 0; i < count; ++i)
        {
            numbers.push_back(dist(gen));
        }
        return numbers;
    }

    // -------------------------------------------------------------
    // Fill a stack from a vector
    // -------------------------------------------------------------
    template <class T>
    static std::stack<T> fillStack(const std::vector<T>& data)
    {
        std::stack<T> s;
        for (std::size_t i = 0; i < data.size(); ++i)
        {
            s.push(data[i]);
        }
        return s;
    }

    // -------------------------------------------------------------
    // Convert stack to priority queue
    // -------------------------------------------------------------
    template <class T>
    static std::priority_queue<T> stackToPriorityQueue(std::stack<T>& s)
    {
        std::priority_queue<T> pq;
        while (!s.empty())
        {
            pq.push(s.top());
            s.pop();
        }
        return pq;
    }

    // -------------------------------------------------------------
    // Convert any container to priority queue with custom comparator
    // -------------------------------------------------------------
    template <typename T, typename InputContainer,
              typename Container = std::vector<T>,
              typename Compare = std::less<typename Container::value_type>>
    static std::priority_queue<T, Container, Compare>
    containerToPriorityQueue(const InputContainer& input)
    {
        std::priority_queue<T, Container, Compare> pq;
        for (const auto& item : input)
        {
            pq.push(item);
        }
        return pq;
    }

    // -------------------------------------------------------------
    // Wrapper for vector -> priority_queue
    // -------------------------------------------------------------
    template <typename T,
              typename Container = std::vector<T>,
              typename Compare = std::less_equal<typename Container::value_type>>
    static std::priority_queue<T, Container, Compare>
    vectorToPriorityQueue(const std::vector<T>& v)
    {
        return containerToPriorityQueue<T, std::vector<T>, Container, Compare>(v);
    }

    // -------------------------------------------------------------
    // Extract top K elements from a priority queue
    // -------------------------------------------------------------
    template <typename T, typename Container, typename Compare>
    static std::vector<T> getTopK(std::priority_queue<T, Container, Compare>& pq, std::size_t k)
    {
        std::vector<T> result;
        k = std::min(k, pq.size());
        result.reserve(k);

        for (std::size_t i = 0; i < k; ++i)
        {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }

    // -------------------------------------------------------------
    // Print vector of any type
    // -------------------------------------------------------------
    template <class T>
    static void printVector(const std::vector<T>& v)
    {
        for (std::size_t i = 0; i < v.size(); ++i)
        {
            std::cout << "'" << v[i] << "'\t";
        }
        std::cout << "\n";
    }
};
