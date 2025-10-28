#include <iostream>
#include <vector>
#include <memory>
#include <string>

/// Base abstract class representing a generic element in the heterogeneous list.
/// Every derived element must implement the `print()` method.
class Element {
public:
    virtual void print() const = 0;
    virtual ~Element() = default;
};

/// Concrete element representing an integer value.
class IntElement : public Element {
    int value;
public:
    explicit IntElement(int v) : value(v) {}
    void print() const override { std::cout << "Int: " << value << '\n'; }
};

/// Concrete element representing a string value.
class StringElement : public Element {
    std::string value;
public:
    explicit StringElement(std::string v) : value(std::move(v)) {}
    void print() const override { std::cout << "String: " << value << '\n'; }
};

/// Concrete element representing a function pointer.
/// When printed, it executes the associated function.
class FunctionElement : public Element {
    void (*func)();
public:
    explicit FunctionElement(void (*f)()) : func(f) {}
    void print() const override {
        std::cout << "Function call: ";
        func();
    }
};

/// Example function used by FunctionElement.
void sayHello() { std::cout << "Hello from function!\n"; }

// int main() {
//     // A heterogeneous list storing elements of different types
//     // using polymorphism and smart pointers for safe memory management.
//     std::vector<std::shared_ptr<Element>> list;

//     // Add elements of various types to the list
//     list.push_back(std::make_shared<IntElement>(42));
//     list.push_back(std::make_shared<StringElement>("Rawal"));
//     list.push_back(std::make_shared<FunctionElement>(sayHello));

//     // Iterate through all elements and invoke their respective print methods
//     for (const auto& e : list)
//         e->print();
// }
