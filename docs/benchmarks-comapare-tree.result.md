========== RBTree<int> ==========

| # | Label | Duration (ms) |
|---:|:---|---:|
| 0 | RBTree::loadFromFile | 1437 |
| 1 | RBTree::insert(k*13) k <= MAX_ELE | 3057 |
| 2 | RBTree::search(k*13) k <= MAX_ELE (summary) | 1205 |
| 3 | RBTree::search(41) | 0 |
| 4 | RBTree::remove(13*k) k <= MAX_ELE | 1272 |
| 5 | RBTree::search(42) after removals | 0 |

========== std::unordered_set<int> ==========
999756 loaded items into unordered_set
[Benchmark] UnorderedSet::loadFromFile executed in 836 ms
[Benchmark] UnorderedSet::insert(k*13) k <= MAX_ELE executed in 2905 ms
unordered_set: found 10000000 / 10000000 searched keys
[Benchmark] UnorderedSet::search(k*13) k <= MAX_ELE (summary) executed in 1050 ms
search(41) = not found
[Benchmark] UnorderedSet::search(41) executed in 0 ms
[Benchmark] UnorderedSet::remove(13*k) k <= MAX_ELE executed in 1862 ms
search(42) = not found
[Benchmark] UnorderedSet::search(42) after removals executed in 0 ms

| # | Label | Duration (ms) |
|---:|:---|---:|
| 0 | UnorderedSet::loadFromFile | 836 |
| 1 | UnorderedSet::insert(k*13) k <= MAX_ELE | 2905 |
| 2 | UnorderedSet::search(k*13) k <= MAX_ELE (summary) | 1050 |
| 3 | UnorderedSet::search(41) | 0 |
| 4 | UnorderedSet::remove(13*k) k <= MAX_ELE | 1862 |
| 5 | UnorderedSet::search(42) after removals | 0 |

========== std::set<int> ==========
999756 loaded items into std::set
[Benchmark] Set::loadFromFile executed in 1225 ms
[Benchmark] Set::insert(k*13) k <= MAX_ELE executed in 11823 ms
std::set: found 10000000 / 10000000 searched keys
[Benchmark] Set::search(k*13) k <= MAX_ELE (summary) executed in 7140 ms
search(41) = not found
[Benchmark] Set::search(41) executed in 0 ms
[Benchmark] Set::remove(13*k) k <= MAX_ELE executed in 10199 ms
search(42) = not found
[Benchmark] Set::search(42) after removals executed in 0 ms

| # | Label | Duration (ms) |
|---:|:---|---:|
| 0 | Set::loadFromFile | 1225 |
| 1 | Set::insert(k*13) k <= MAX_ELE | 11823 |
| 2 | Set::search(k*13) k <= MAX_ELE (summary) | 7140 |
| 3 | Set::search(41) | 0 |
| 4 | Set::remove(13*k) k <= MAX_ELE | 10199 |
| 5 | Set::search(42) after removals | 0 |

========== std::map<long int, long int> ==========
499944 loaded items from given file
[Benchmark] Map::loadFromFile executed in 1528 ms
[Benchmark] Map::insert(k*13) k <= MAX_ELE executed in 12983 ms
Map: found 10000000 / 10000000 searched keys
[Benchmark] Map::search(k*13) k <= MAX_ELE (summary) executed in 5419 ms
search(41) = not found
[Benchmark] Map::search(41) executed in 0 ms
[Benchmark] Map::remove(13*k) k <= MAX_ELE executed in 9037 ms
search(42) = not found
[Benchmark] Map::search(42) after removals executed in 0 ms

| # | Label | Duration (ms) |
|---:|:---|---:|
| 0 | Map::loadFromFile | 1528 |
| 1 | Map::insert(k*13) k <= MAX_ELE | 12983 |
| 2 | Map::search(k*13) k <= MAX_ELE (summary) | 5419 |
| 3 | Map::search(41) | 0 |
| 4 | Map::remove(13*k) k <= MAX_ELE | 9037 |
| 5 | Map::search(42) after removals | 0 |

========== BSTree<long int> ==========
1000000 loaded items from given file
[Benchmark] BSTree::loadFromFile executed in 1271 ms
[Benchmark] BSTree::insert(k*13) k <= MAX_ELE executed in 19418 ms
BSTree: found 10000000 / 10000000 searched keys
[Benchmark] BSTree::search(k*13) k <= MAX_ELE (summary) executed in 17014 ms
search(41) = not found
[Benchmark] BSTree::search(41) executed in 0 ms
[Benchmark] BSTree::remove(13*k) k <= MAX_ELE executed in 2826 ms
search(42) = not found
[Benchmark] BSTree::search(42) after removals executed in 0 ms

| # | Label | Duration (ms) |
|---:|:---|---:|
| 0 | BSTree::loadFromFile | 1271 |
| 1 | BSTree::insert(k*13) k <= MAX_ELE | 19418 |
| 2 | BSTree::search(k*13) k <= MAX_ELE (summary) | 17014 |
| 3 | BSTree::search(41) | 0 |
| 4 | BSTree::remove(13*k) k <= MAX_ELE | 2826 |
| 5 | BSTree::search(42) after removals | 0 |


[+] Test successful
[!] Cleaning build files
[*] Compiling src/main.cpp
[!] Cleaning build files
[*] Compiling src/main.cpp
[!] Cleaning build files
[*] Compiling src/main.cpp
[*] Compiling src/benchmarks/adaptor.benchmark.cpp
[*] Compiling src/benchmarks/binary-search-tree.benchmark.cpp
[*] Compiling src/benchmarks/benchmarks/red-black-tree.benchmark.cpp
[*] Compiling src/benchmarks/benchmarks/tree.benchmark.cpp
[!] Linking into build/main
[+] Build successful
[!] testing... 

MAX_ELE: 10000000
========== RBTree<int> ==========
1000000 loaded items from given file
[36m[Benchmark] [33mRBTree::loadFromFile[0m executed in [32m912 ms[0m
[36m[Benchmark] [33mRBTree::insert(k*13) k <= MAX_ELE[0m executed in [32m3346 ms[0m
RBTree: found 10000000 / 10000000 searched keys
[36m[Benchmark] [33mRBTree::search(k*13) k <= MAX_ELE (summary)[0m executed in [32m1308 ms[0m
search(41) = not found
[36m[Benchmark] [33mRBTree::search(41)[0m executed in [32m0 ms[0m
[36m[Benchmark] [33mRBTree::remove(13*k) k <= MAX_ELE[0m executed in [32m1543 ms[0m
search(42) = not found
[36m[Benchmark] [33mRBTree::search(42) after removals[0m executed in [32m0 ms[0m
[34m
=== Benchmark History ===
[0m  0 | [33mRBTree::loadFromFile[0m : [32m912 ms[0m
  1 | [33mRBTree::insert(k*13) k <= MAX_ELE[0m : [32m3346 ms[0m
  2 | [33mRBTree::search(k*13) k <= MAX_ELE (summary)[0m : [32m1308 ms[0m
  3 | [33mRBTree::search(41)[0m : [32m0 ms[0m
  4 | [33mRBTree::remove(13*k) k <= MAX_ELE[0m : [32m1543 ms[0m
  5 | [33mRBTree::search(42) after removals[0m : [32m0 ms[0m

[34m
| # | Label | Duration (ms) |
[0m[34m|---:|:---|---:|
[0m| 0 | RBTree::loadFromFile | 912 |
| 1 | RBTree::insert(k*13) k <= MAX_ELE | 3346 |
| 2 | RBTree::search(k*13) k <= MAX_ELE (summary) | 1308 |
| 3 | RBTree::search(41) | 0 |
| 4 | RBTree::remove(13*k) k <= MAX_ELE | 1543 |
| 5 | RBTree::search(42) after removals | 0 |

========== std::unordered_set<int> ==========
999756 loaded items into unordered_set
[36m[Benchmark] [33mUnorderedSet::loadFromFile[0m executed in [32m805 ms[0m
[36m[Benchmark] [33mUnorderedSet::insert(k*13) k <= MAX_ELE[0m executed in [32m3146 ms[0m
unordered_set: found 10000000 / 10000000 searched keys
[36m[Benchmark] [33mUnorderedSet::search(k*13) k <= MAX_ELE (summary)[0m executed in [32m1031 ms[0m
search(41) = not found
[36m[Benchmark] [33mUnorderedSet::search(41)[0m executed in [32m0 ms[0m
[36m[Benchmark] [33mUnorderedSet::remove(13*k) k <= MAX_ELE[0m executed in [32m1800 ms[0m
search(42) = not found
[36m[Benchmark] [33mUnorderedSet::search(42) after removals[0m executed in [32m0 ms[0m
[34m
=== Benchmark History ===
[0m  0 | [33mUnorderedSet::loadFromFile[0m : [32m805 ms[0m
  1 | [33mUnorderedSet::insert(k*13) k <= MAX_ELE[0m : [32m3146 ms[0m
  2 | [33mUnorderedSet::search(k*13) k <= MAX_ELE (summary)[0m : [32m1031 ms[0m
  3 | [33mUnorderedSet::search(41)[0m : [32m0 ms[0m
  4 | [33mUnorderedSet::remove(13*k) k <= MAX_ELE[0m : [32m1800 ms[0m
  5 | [33mUnorderedSet::search(42) after removals[0m : [32m0 ms[0m

========== std::set<int> ==========
999756 loaded items into std::set
[36m[Benchmark] [33mSet::loadFromFile[0m executed in [32m1293 ms[0m
[36m[Benchmark] [33mSet::insert(k*13) k <= MAX_ELE[0m executed in [32m11266 ms[0m
[-] Test failed
