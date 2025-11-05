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


main: 
	@$(CXX) $(CXXFLAGS) -o build/main.exe src/main.cpp 
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./build/main.exe && echo && echo "[+] Test successful" || echo "[-] Test failed"
	


test: clean compile
	@echo "[!] testing... "
	@echo ;
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./$(TARGET) main && echo && echo "[+] Test successful" || echo "[-] Test failed"

test-adaptor: clean compile
	@echo "[!] testing... "
	@echo ;
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./$(TARGET) adaptor && echo && echo "[+] Test successful" || echo "[-] Test failed"

test-iterator: clean compile
	@echo "[!] testing... "
	@echo ;
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./$(TARGET) iterator && echo && echo "[+] Test successful" || echo "[-] Test failed"

test-h-list: clean compile
	@echo "[!] testing... "
	@echo ;
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./$(TARGET) h-list && echo && echo "[+] Test successful" || echo "[-] Test failed"

test-math-expression: clean compile
	@echo "[!] testing... "
	@echo ;
	@/usr/bin/time -f "Time: %E | Memory: %M KB | CPU: %P" ./$(TARGET) math-expression && echo && echo "[+] Test successful" || echo "[-] Test failed"


# Nettoyage
clean:
	@echo "[!] Cleaning build files"
	@rm -rf build $(TARGET)
