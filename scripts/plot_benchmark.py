#!/usr/bin/env python3
"""
plot_benchmarks_bottom_legend.py
Génère une image PNG avec la légende en bas.
"""

import numpy as np
import matplotlib.pyplot as plt

operations = ["loadFromFile", "insert_sorted", "search_sorted", "remove_sorted"]
structures = ["RBTree", "unordered_set", "std::set", "std::map", "AVLTree"]
types = ["int", "long", "float", "string"]

times = {
    "loadFromFile": {
        "RBTree":    [1002,  964, 1070, 2165],
        "unordered_set":[743, 804, 966, 1100],
        "std::set":  [1125, 1114, 1344, 2549],
        "std::map":  [800,  845, 970, 1648],
        "AVLTree":   [1509, 1597, 1691, 2967],
    },
    "insert_sorted": {
        "RBTree":    [3290, 2949, 3223, 35538],
        "unordered_set":[2846, 2817, 5846, 13723],
        "std::set":  [8898, 9644, 8981, 31937],
        "std::map":  [9480,10403,9214, 33819],
        "AVLTree":   [9163, 8109, 8754, 32005],
    },
    "search_sorted": {
        "RBTree":    [1686, 1582, 1642, 25096],
        "unordered_set":[1012,1042,3161,11346],
        "std::set":  [5328, 5149, 5263, 21900],
        "std::map":  [5485, 5386, 5127, 22816],
        "AVLTree":   [2380, 1804, 2502, 25779],
    },
    "remove_sorted": {
        "RBTree":    [1510, 1420, 1495, 13726],
        "unordered_set":[1657,1672,4053,11838],
        "std::set":  [8584, 7972, 8070, 30028],
        "std::map":  [8616, 8634, 7903, 30051],
        "AVLTree":   [6452, 5549, 7227, 21900],
    },
}

n_types = len(types)
n_struct = len(structures)
x = np.arange(n_types)
bar_width = 0.13

fig, axs = plt.subplots(1, 4, figsize=(22, 7), constrained_layout=False)

for idx_op, op in enumerate(operations):
    ax = axs[idx_op]
    for i, struct in enumerate(structures):
        vals = times[op][struct]
        offset = (i - (n_struct - 1) / 2.0) * bar_width
        ax.bar(x + offset, vals, width=bar_width, label=struct)

    ax.set_xticks(x)
    ax.set_xticklabels(types)
    ax.set_ylabel("Time (ms)")

    if op == "loadFromFile":
        ax.set_title("Load from file (100k)")
    elif op == "insert_sorted":
        ax.set_title("Insert sorted (10M)")
    elif op == "search_sorted":
        ax.set_title("Search sorted (10M)")
    elif op == "remove_sorted":
        ax.set_title("Remove sorted (10M)")

    ax.grid(axis='y', linestyle=':', linewidth=0.5, alpha=0.6)

handles, labels = axs[-1].get_legend_handles_labels()

fig.legend(
    handles, labels,
    loc='lower center',
    ncol=len(structures),
    frameon=False,
    bbox_to_anchor=(0.5, -0.05)
)

plt.subplots_adjust(bottom=0.18)

plt.suptitle("Benchmark Comparison Across Data Structures", fontsize=16)

output_file = "benchmark_summary_bottom.png"
plt.savefig(output_file, dpi=150, bbox_inches='tight')
print(f"Saved plot to {output_file}")
