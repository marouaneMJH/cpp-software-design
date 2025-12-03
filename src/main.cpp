#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

 #include "../include/class/red-black-tree/rbt_tree.h"

int main(int argc, char* argv[]) {

    std::string filename = "assets/file.txt";
    if (argc >= 2) {
        filename = argv[1];
    }

    // Measure total time
    auto start_total = std::chrono::high_resolution_clock::now();

    // ============================================================
    // 1) Lire le fichier
    // ============================================================

    auto start_read = std::chrono::high_resolution_clock::now();

    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error: cannot open " << filename << "\n";
        return 1;
    }

    long long count = 0;
    std::string token;

    RBTTree tree;

    while (fin >> token) {
        tree.insert(token);
        ++count;
    }

    fin.close();

    auto end_read = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_read = end_read - start_read;


    // ============================================================
    // 2) BFS silencieux
    // ============================================================

    auto start_bfs = std::chrono::high_resolution_clock::now();

    tree.breadthFirst();   // silencieux

    auto end_bfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_bfs = end_bfs - start_bfs;


    // ============================================================
    // 3) Temps total
    // ============================================================

    auto end_total = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_total = end_total - start_total;


    // ============================================================
    // 4) Résultats
    // ============================================================

    const std::string CYAN  = "\033[96m";
    const std::string GREEN = "\033[92m";
    const std::string YELLOW = "\033[93m";
    const std::string RESET = "\033[0m";

    std::cout << "\n\n==============================================\n";
    std::cout << CYAN << "         📊 RESULTATS DU BENCHMARK" << RESET << "\n";
    std::cout << "==============================================\n";

    std::cout << YELLOW << "→ Fichier analyse : " << RESET << filename << "\n\n";

    std::cout << GREEN  << " Tokens lus                       : " << RESET << count << "\n";
    std::cout << GREEN  << " Temps lecture + insertion        : " 
              << RESET << std::fixed << std::setprecision(4) << time_read.count()  << " sec\n";

    std::cout << GREEN  << " Temps BFS (silencieux)           : " 
              << RESET << std::fixed << std::setprecision(4) << time_bfs.count()   << " sec\n";

    std::cout << GREEN  << " Temps total programme            : " 
              << RESET << std::fixed << std::setprecision(4) << time_total.count() << " sec\n";

    std::cout << "==============================================\n\n";

    return 0;
}
