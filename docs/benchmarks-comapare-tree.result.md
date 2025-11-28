
MAX_ELE: 10000000
===== RBTree<int> =====
1000000 loaded items into RBTree
[Benchmark] RBTree::loadFromFile executed in 844 ms
[Benchmark] RBTree::insert(k*13) k <= MAX_ELE executed in 3664 ms
RBTree: found 10000000 / 10000000
[Benchmark] RBTree::search(k*13) k <= MAX_ELE executed in 1865 ms
[Benchmark] RBTree::remove(13*k) k <= MAX_ELE executed in 1582 ms

=== Benchmark History ===
  0 | RBTree::loadFromFile : 844 ms
  1 | RBTree::insert(k*13) k <= MAX_ELE : 3664 ms
  2 | RBTree::search(k*13) k <= MAX_ELE : 1865 ms
  3 | RBTree::remove(13*k) k <= MAX_ELE : 1582 ms

===== std::unordered_set<int> =====
975540 loaded items into unordered_set
[Benchmark] UnorderedSet::loadFromFile executed in 803 ms
[Benchmark] UnorderedSet::insert(k*13) k <= MAX_ELE executed in 2725 ms
unordered_set: found 10000000 / 10000000
[Benchmark] UnorderedSet::search(k*13) k <= MAX_ELE executed in 1007 ms
[Benchmark] UnorderedSet::remove(13*k) k <= MAX_ELE executed in 1677 ms

=== Benchmark History ===
  0 | UnorderedSet::loadFromFile : 803 ms
  1 | UnorderedSet::insert(k*13) k <= MAX_ELE : 2725 ms
  2 | UnorderedSet::search(k*13) k <= MAX_ELE : 1007 ms
  3 | UnorderedSet::remove(13*k) k <= MAX_ELE : 1677 ms

===== std::set<int> =====
975540 loaded items into std::set
[Benchmark] Set::loadFromFile executed in 1208 ms
[Benchmark] Set::insert(k*13) k <= MAX_ELE executed in 9736 ms
std::set: found 10000000 / 10000000
[Benchmark] Set::search(k*13) k <= MAX_ELE executed in 6647 ms
[Benchmark] Set::remove(13*k) k <= MAX_ELE executed in 9152 ms

=== Benchmark History ===
  0 | Set::loadFromFile : 1208 ms
  1 | Set::insert(k*13) k <= MAX_ELE : 9736 ms
  2 | Set::search(k*13) k <= MAX_ELE : 6647 ms
  3 | Set::remove(13*k) k <= MAX_ELE : 9152 ms

===== std::map<long int,int> =====
493771 loaded items into std::map
[Benchmark] Map::loadFromFile executed in 1208 ms
[Benchmark] Map::insert(k*13) k <= MAX_ELE executed in 10874 ms
std::map: found 10000000 / 10000000
[Benchmark] Map::search(k*13) k <= MAX_ELE executed in 5883 ms
[Benchmark] Map::remove(13*k) k <= MAX_ELE executed in 9084 ms

=== Benchmark History ===
  0 | Map::loadFromFile : 1208 ms
  1 | Map::insert(k*13) k <= MAX_ELE : 10874 ms
  2 | Map::search(k*13) k <= MAX_ELE : 5883 ms
  3 | Map::remove(13*k) k <= MAX_ELE : 9084 ms

===== BSTree<int> =====
1000000 loaded items into BSTree
[Benchmark] BSTree::loadFromFile executed in 1036 ms
