CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = build/main

# Cherche tous les fichiers .cpp
SRCS = $(shell find src -name "*.cpp")

# Transforme src/foo/bar.cpp → build/foo/bar.o
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))

# Règle par défaut
all:   compile run

# Crée les sous-dossiers dans build/ en miroir de src/
build_dirs:
	@mkdir -p $(dir $(OBJS))


compile:  build_dirs $(TARGET)

# Lien final
$(TARGET): $(OBJS)
	@echo "[!] Linking into $(TARGET)"
	@$(CXX) $(CXXFLAGS) -o $@ $^ && echo "[+] Build successful" || echo "[-] Linking failed"

# Compilation .cpp → .o
build/%.o: src/%.cpp
	@echo "[*] Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Exécution
run: $(TARGET)
	@echo "[!] Running $(TARGET)"
	@./$(TARGET) && echo "[+] Done running" || echo "[-] Runtime error"


test: clean compile
	@echo "[!] testing... "
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./$(TARGET) && echo "[+] Test successful" || echo "[-] Test failed"

# Nettoyage
clean:
	@echo "[!] Cleaning build files"
	@rm -rf build $(TARGET)
