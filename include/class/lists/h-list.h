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

/// Concrete element representing a double value.
class DoubleElement : public Element {
    double value;
public:
    explicit DoubleElement(double v) : value(v) {}
    void print() const override { std::cout << "Double: " << value << '\n'; }
};

/// Concrete element representing a boolean value.
class BoolElement : public Element {
    bool value;
public:
    explicit BoolElement(bool v) : value(v) {}
    void print() const override { std::cout << "Bool: " << (value ? "true" : "false") << '\n'; }
};

/// Concrete element representing a character value.
class CharElement : public Element {
    char value;
public:
    explicit CharElement(char v) : value(v) {}
    void print() const override { std::cout << "Char: '" << value << "'\n"; }
};

/// Concrete element representing a float value.
class FloatElement : public Element {
    float value;
public:
    explicit FloatElement(float v) : value(v) {}
    void print() const override { std::cout << "Float: " << value << "f\n"; }
};

/// Concrete element representing a long value.
class LongElement : public Element {
    long value;
public:
    explicit LongElement(long v) : value(v) {}
    void print() const override { std::cout << "Long: " << value << "L\n"; }
};

/// Heterogeneous list class that can store different data types
class HList {
private:
    std::vector<std::shared_ptr<Element>> elements;

public:
    /// Add an integer to the list
    void add(int value) {
        elements.push_back(std::make_shared<IntElement>(value));
    }
    
    /// Add a string to the list
    void add(const std::string& value) {
        elements.push_back(std::make_shared<StringElement>(value));
    }
    
    /// Add a double to the list
    void add(double value) {
        elements.push_back(std::make_shared<DoubleElement>(value));
    }
    
    /// Add a boolean to the list
    void add(bool value) {
        elements.push_back(std::make_shared<BoolElement>(value));
    }
    
    /// Add a character to the list
    void add(char value) {
        elements.push_back(std::make_shared<CharElement>(value));
    }
    
    /// Add a float to the list
    void add(float value) {
        elements.push_back(std::make_shared<FloatElement>(value));
    }
    
    /// Add a long to the list
    void add(long value) {
        elements.push_back(std::make_shared<LongElement>(value));
    }
    
    /// Add any Element-derived object
    void add(std::shared_ptr<Element> element) {
        elements.push_back(element);
    }
    
    /// Get the size of the list
    size_t size() const {
        return elements.size();
    }
    
    /// Check if list is empty
    bool empty() const {
        return elements.empty();
    }
    
    /// Clear all elements
    void clear() {
        elements.clear();
    }
    
    /// Overload << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const HList& list) {
        os << "HList [" << list.size() << " elements]:\n";
        for (const auto& element : list.elements) {
            os << "  ";
            element->print();
        }
        return os;
    }
};