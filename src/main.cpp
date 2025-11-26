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

    std::cout << "\n--- Resultats du programme ---\n";
    std::cout << "Tokens lus        : " << count << "\n";
    std::cout << "Temps de lecture + insertion : " << time_read.count() << " sec\n";
    std::cout << "Temps BFS silencieux        : " << time_bfs.count() << " sec\n";
    std::cout << "Temps total programme        : " << time_total.count() << " sec\n";
    std::cout << "---------------------------------\n";

    return 0;
}
