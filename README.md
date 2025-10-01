# C++ OOP Stack Implementations

## Project Architecture

This project demonstrates different stack implementations in C++ using object-oriented programming and templates. The directory structure is organized as follows:

```
.
├── include/                # Header files and templates
│   ├── index.h
│   ├── class/stack/        # Stack class definitions
│   │   ├── node.h
│   │   ├── stack-dynamic.h
│   │   ├── stack-linked.h
│   │   ├── stack-vector.h
│   │   └── index.h
│   ├── interface/stack.h   # Stack interface (abstract base class)
│   └── templates/          # Template implementations
│       ├── node.tpp
│       ├── stack-dynamic.tpp
│       ├── stack-linked.tpp
│       └── stack-vector.tpp
├── src/
│   └── main.cpp            # Entry point for the project
├── build/                  # Compiled output files (created by Makefile)
├── Makefile                # Build automation
├── Benchmark.md            # Benchmark results and analysis
└── README.md               # Project documentation
```

-   **Stack Implementations:**

    -   `StackVec`: Stack using STL `vector`
    -   `StackLinked`: Stack using a linked list of `Node` objects
    -   `StackDynamic`: Stack using a dynamically resizing array

-   **Interface:**  
    All stack classes implement the common [`Stack`](include/interface/stack.h) interface.

## How to Build and Run

This project uses a `Makefile` for building and running the code.

### Compile the Project

To compile the project, run:

```sh
make compile
```

This will compile all source files and place the output in the `build/` directory.

### Run the Project

To run the compiled executable:

```sh
make run
```

This will execute the binary located at `build/main`.

### Compile and Run in One Step

You can also compile and run the project in a single command:

```sh
make
```

### Clean Build Files

To remove all compiled files and the `build/` directory:

```sh
make clean
```

---

For more details on benchmarks and implementation, see [Benchmark.md](Benchmark.md).
