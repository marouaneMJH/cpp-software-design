# =========================
# C++ Project Makefile
# Works on MSYS2 UCRT64 / Linux / macOS
# =========================

SHELL := bash

# Detect .exe on Windows
ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

# ---- Toolchain & flags ----
CXX      ?= g++
CXXFLAGS ?= -std=c++23 -Wall -Wextra -O2 -MMD -MP
# On Windows console apps this helps choose the right entry point
# Use -mconsole instead of -Wl,--subsystem,console for better MinGW compatibility
LDFLAGS  ?= -mconsole
LDLIBS   ?=

# ---- Targets & sources ----
TARGET := build/main$(EXE)
# Default input file (can be overridden: make run FILE=custom.txt)
FILE ?= assets/file.txt

# All .cpp under src/ become objects under build/
# Use bash find command explicitly for cross-platform compatibility
SRCS := $(shell bash -c "find src -type f -name '*.cpp' 2>/dev/null")
# Also include implementation files from include/templates/
TEMPLATE_SRCS := $(shell bash -c "find include/templates -type f -name '*.cpp' 2>/dev/null")
ALL_SRCS := $(SRCS) $(TEMPLATE_SRCS)
OBJS := $(patsubst src/%.cpp,build/%.o,$(SRCS)) $(patsubst include/templates/%.cpp,build/templates/%.o,$(TEMPLATE_SRCS))
DEPS := $(OBJS:.o=.d)

# Default target: compile and run with default file
.PHONY: all
all: compile run

# Build only (no run)
.PHONY: build
build: compile

# Ensure build directory structure exists
.PHONY: build_dirs
build_dirs:
	@mkdir -p $(dir $(OBJS)) $(dir $(TARGET))

# Compile everything (link included)
.PHONY: compile
compile: build_dirs $(TARGET)

# Link
$(TARGET): $(OBJS)
	@echo "[!] Linking into $(TARGET)"
	@rm -f $(TARGET)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@echo "[+] Build successful"

# Compile .cpp -> .o (with dep files)
build/%.o: src/%.cpp
	@echo "[*] Compiling $<"
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile template implementation files
build/templates/%.o: include/templates/%.cpp
	@echo "[*] Compiling $<"
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Auto-include header dependency files (safe if missing)
-include $(DEPS)

# Run with default or specified file
.PHONY: run
run: $(TARGET)
	@echo "[!] Running $(TARGET) with $(FILE)"
	@./$(TARGET) $(FILE)
	@echo "[+] Done running"

# Quick single-file sanity (optional)
.PHONY: main
main:
	@mkdir -p build
	@$(CXX) $(CXXFLAGS) -o build/main$(EXE) src/main.cpp
	@./build/main$(EXE)

# Parametrized tests (adjust if your main reads args)
.PHONY: test test-adaptor test-iterator test-h-list test-math-expression
test: compile
	@./$(TARGET) main

test-adaptor: compile
	@./$(TARGET) adaptor

test-iterator: compile
	@./$(TARGET) iterator

test-h-list: compile
	@./$(TARGET) h-list

test-math-expression: compile
	@./$(TARGET) math-expression

# Clean
.PHONY: clean
clean:
	@echo "[!] Cleaning build/"
	@rm -rf build

# Help
.PHONY: help
help:
	@echo "Targets:"
	@echo "  make                    -> compile and run with assets/file.txt"
	@echo "  make build              -> compile only (no run)"
	@echo "  make run                -> run with default file (assets/file.txt)"
	@echo "  make run FILE=path.txt  -> run with custom file"
	@echo "  make clean              -> remove build/"
	@echo ""
	@echo "Examples:"
	@echo "  make                    # Compile and run with default file"
	@echo "  make run FILE=test.txt  # Run with custom file"
