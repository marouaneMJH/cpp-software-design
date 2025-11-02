#include "../include/index.h"

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <random>
#include <algorithm>

// -------------------------------------------------------------
// Utility: Generate random integers in a given range
// -------------------------------------------------------------
std::vector<int> generateRandomNumbers(std::size_t count, int min, int max)
{
    std::vector<int> numbers;
    numbers.reserve(count);

    std::random_device rd;                         // Non-deterministic seed
    std::mt19937 gen(rd());                        // Mersenne Twister engine
    std::uniform_int_distribution<> dist(min, max);

    for (std::size_t i = 0; i < count; ++i)
    {
        numbers.push_back(dist(gen));
    }
    return numbers;
}

// -------------------------------------------------------------
// Fill a stack from a vector of integers
// -------------------------------------------------------------
template <class T>
std::stack<T> fillStack(const std::vector<T>& data)
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
// (Consumes the stack; copy the stack before calling if needed)
// -------------------------------------------------------------
template <class T>
std::priority_queue<T> stackToPriorityQueue(std::stack<T>& s)
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
// Convert stack to priority queue
// (Consumes the stack; copy the stack before calling if needed)
// -------------------------------------------------------------

// -------------------------------------------------------------
// Convert any container to priority queue with custom comparator
// -------------------------------------------------------------
template <typename T, typename InputContainer,
          typename Container = std::vector<T>, 
          typename Compare = std::less<typename Container::value_type>>
std::priority_queue<T, Container, Compare> containerToPriorityQueue(const InputContainer& input)
{
    std::priority_queue<T, Container, Compare> pq;
    for (const auto& item : input)
    {
        pq.push(item);
    }
    return pq;
}

// Convenience wrapper for the old function name
template <typename T, typename Container = std::vector<T>, 
          typename Compare = std::less_equal<typename Container::value_type>>
std::priority_queue<T, Container, Compare> vectorToPriorityQueue(const std::vector<T>& v)
{
    return containerToPriorityQueue<T, std::vector<T>, Container, Compare>(v);
}


// -------------------------------------------------------------
// Extract top K elements from a priority queue (generic)
// -------------------------------------------------------------
template <typename T, typename Container, typename Compare>
std::vector<T> getTopK(std::priority_queue<T, Container, Compare>& pq, std::size_t k)
{
    std::vector<T> result;
    k = std::min(k, pq.size()); // Avoid out of range
    result.reserve(k);

    for (std::size_t i = 0; i < k; ++i)
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}






// -------------------------------------------------------------
// Print vector of integers
// -------------------------------------------------------------
template <class T>
void printVector(const std::vector<T>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
    {
        std::cout <<  "'" << v[i] << "'\t";
    }
    std::cout << "\n";
}




int adaptorClass()
{
    // Test for random generated int vector
    // vector<int> randomNumbersVector = generateRandomNumbers(1'000'000,0,10000000);

    // auto  pq = vectorToPriorityQueue<int>(randomNumbersVector);

    // const int k=2;
    // vector <int> v = getTopK(pq,50);

    // cout<<"The first "<< k<< " greater word in the file is: ";

    // printVector(v);



    // Dic dic;
    // vector<string> v;

    // dic.readFromFile("assets/out_file.txt");
    
    // // priority_queue<string> pq  = vectorToPriorityQueue<string>(dic.getDic());
    // auto  pq = vectorToPriorityQueue<string>(dic.getDic());

    // const int k=2;
    // v = getTopK(pq,2);

    // cout<<"The first "<< k<< " greater word in the file is: ";

    // printVector(v);

    return 0;
}

// -------------------------------------------------------------
// Main Program
// -------------------------------------------------------------
int main(int arc,  char* argv[])
{
    // iterator
    // h-list
    // math-expression

    // Todo: a time function to truck the time of execution of each functionality

    if(string(argv[1]) == "adaptor")
        return adaptorClass();
    if(string(argv[1]) == "iterator")
        return adaptorClass();
    if(string(argv[1]) == "math-expression")
        return adaptorClass();

    return 0;
}
