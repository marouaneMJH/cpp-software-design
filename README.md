# C++ OOP Design Patterns & Data Structures

## Project Overview

This comprehensive C++ project demonstrates advanced object-oriented programming principles, design patterns, and data structure implementations with performance benchmarking. It showcases modern C++17 features including templates, RAII, and sophisticated memory management techniques.

## Project Architecture

```
.
├── include/                     # Header files and templates
│   ├── index.h                  # Main project header
│   ├── class/                   # Core data structure implementations
│   │   ├── stack/               # Stack implementations
│   │   │   ├── stack-dynamic.h  # Dynamic array-based stack
│   │   │   ├── stack-linked.h   # Linked list-based stack
│   │   │   ├── stack-vector.h   # STL vector-based stack
│   │   │   └── node.h           # Node structure definitions
│   │   ├── tree/                # Tree data structures
│   │   │   ├── binary_tree_search.h  # Binary Search Tree
│   │   │   ├── red_black_tree.h      # Red-Black Tree
│   │   │   ├── avl_tree.h            # AVL Self-balancing Tree
│   │   │   └── tree.h                # Base tree interface
│   │   ├── lists/               # List implementations
│   │   ├── helpers/             # Utility classes
│   │   ├── dic.h                # Dictionary implementation
│   │   └── math-expression.h    # Mathematical expression parser
│   ├── interface/               # Abstract interfaces
│   │   ├── stack.h              # Stack interface
│   │   └── benchmark.h          # Benchmarking interface
│   ├── templates/               # Template implementations (.tpp files)
│   ├── benchmarks/              # Benchmarking framework
│   └── shared/                  # Shared utilities and color definitions
├── src/                         # Source implementations
│   ├── main.cpp                 # Main entry point
│   └── benchmarks/              # Benchmark implementations
├── build/                       # Compiled output (auto-generated)
├── assets/                      # Test data files
│   ├── big_int_numbers.txt      # Large integer datasets
│   ├── big_float_numbers.txt    # Large float datasets
│   ├── big_strings.txt          # Large string datasets
│   └── ...                      # Additional test files
├── docs/                        # Documentation
│   ├── Benchmark.md             # Performance analysis
│   └── tasks.md                 # Development tasks
├── scripts/                     # Utility scripts
└── Makefile                     # Build automation
```

## Implemented Data Structures

### Stack Implementations

-   **`StackVec`**: High-performance stack using STL `std::vector`
-   **`StackLinked`**: Memory-efficient linked list implementation
-   **`StackDynamic`**: Custom dynamic array with manual memory management

### Tree Data Structures

-   **Binary Search Tree (BST)**: Basic ordered tree structure
-   **Red-Black Tree**: Self-balancing BST with guaranteed O(log n) operations
-   **AVL Tree**: Height-balanced tree with strict balancing criteria

### Advanced Features

-   **Generic Templates**: Type-safe implementations for any data type
-   **Iterator Patterns**: STL-compatible iterator implementations
-   **Memory Management**: RAII principles and smart pointer usage
-   **Mathematical Expressions**: Parser and evaluator for mathematical expressions

## Interface Design

All data structures implement standardized interfaces promoting:

-   **Polymorphism**: Common base classes for similar structures
-   **SOLID Principles**: Single responsibility and interface segregation
-   **Template Specialization**: Optimized implementations for specific types

## Performance Benchmarking

This project includes a comprehensive benchmarking framework that measures:

-   **Execution Time**: Precise timing using `std::chrono::high_resolution_clock`
-   **Memory Usage**: Peak memory consumption analysis
-   **CPU Utilization**: Performance profiling across different implementations
-   **Comparative Analysis**: Head-to-head performance comparisons

## Build System & Usage

### Prerequisites

-   **Compiler**: GCC 7.0+ or Clang 8.0+ (C++17 support required)
-   **Build System**: Make utility
-   **OS**: Linux/Unix-based system (tested on Ubuntu/Debian)

### Building the Project

#### Quick Start

```bash
# Build and run in one command
make

# Or step by step
make compile  # Compile all sources
make run      # Execute the main binary
```

#### Advanced Build Options

```bash
# Clean build (removes all build artifacts)
make clean

# Build optimized version
make compile CXXFLAGS="-O3 -DNDEBUG"

# Build with debug symbols
make compile CXXFLAGS="-g -O0"
```

### Running Benchmarks

The project supports multiple benchmark modes:

```bash
# Stack and basic data structure benchmarks
./build/main adaptor

# Tree structure performance tests
./build/main tree           # Basic binary tree
./build/main bs-tree        # Binary Search Tree
./build/main rb-tree        # Red-Black Tree

# Comprehensive comparison benchmarks
./build/main ben-rb-bs-map-set

# Mathematical expression parsing
./build/main math-expression
```

#### Automated Testing

```bash
# Run all benchmark suites
make test                    # Main test suite
make test-adaptor           # Adaptor pattern tests
make test-tree              # Tree implementation tests
make test-bs-tree           # BST specific tests
make test-rb-tree           # Red-Black tree tests
make test-ben-compare-tree  # Comparative tree analysis
```

## Design Patterns Implemented

### Structural Patterns

-   **Adaptor Pattern**: Interface adaptation for legacy code integration
-   **Template Method**: Algorithmic skeleton with customizable steps

### Behavioral Patterns

-   **Strategy Pattern**: Interchangeable algorithm implementations
-   **Iterator Pattern**: STL-compatible traversal mechanisms

### Creational Patterns

-   **Factory Pattern**: Object creation abstraction
-   **RAII Pattern**: Resource acquisition and automatic cleanup

## Testing & Quality Assurance

### Test Data

The `assets/` directory contains comprehensive test datasets:

-   **Large Datasets**: 10K+ elements for stress testing
-   **Type Coverage**: Integer, float, double, and string data
-   **Edge Cases**: Empty sets, single elements, and boundary conditions

### Memory Safety

-   **Valgrind Integration**: Memory leak detection
-   **ASAN Support**: AddressSanitizer compatibility
-   **Smart Pointers**: Modern C++ memory management

## Learning Resources

This project demonstrates:

1. **Advanced C++ Features**

    - Template metaprogramming
    - SFINAE (Substitution Failure Is Not An Error)
    - Move semantics and perfect forwarding
    - Variadic templates

2. **Algorithm Complexity**

    - Time complexity analysis: O(1), O(log n), O(n)
    - Space complexity optimization
    - Cache-friendly data structure design

3. **Software Engineering Principles**
    - SOLID design principles
    - DRY (Don't Repeat Yourself)
    - KISS (Keep It Simple, Stupid)
    - Separation of concerns

## Contributing

1. **Code Style**: Follow the existing naming conventions
2. **Documentation**: Add inline comments for complex algorithms
3. **Testing**: Include benchmarks for new implementations
4. **Performance**: Profile and optimize critical paths

## Future Enhancements

-   [ ] **Concurrent Data Structures**: Thread-safe implementations
-   [ ] **Cache-Oblivious Algorithms**: Memory hierarchy optimization
-   [ ] **GPU Acceleration**: CUDA/OpenCL integration
-   [ ] **Serialization**: Binary and JSON persistence
-   [ ] **Network Integration**: Distributed data structure protocols

---

## Performance Notes

> **Tip**: For production use, compile with `-O3 -DNDEBUG -march=native` for maximum performance.

> **Memory**: The project is designed for educational purposes. Production code should use `std::unique_ptr` and `std::shared_ptr` more extensively.

For detailed implementation notes and algorithmic analysis, see the [documentation](docs/) directory.
