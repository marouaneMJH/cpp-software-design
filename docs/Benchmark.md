
| Implementation            | Median Time (s) | Speedup vs Linked List | Throughput (ops/s) |
| ------------------------- | :-------------: | :--------------------: | :----------------: |
| **Vector (STL, reserve)** |     **2.7**     |        **×4.6**        |   **≈ 18.5 M/s**   |
| **Dynamic Array**         |     **3.2**     |        **×3.9**        |   **≈ 15.6 M/s**   |
| **Linked List**           |     **12.5**    |        **×1.0**        |    **≈ 4.0 M/s**   |



Vector (STL, reserve) → fastest and most efficient.

Dynamic Array → close performance, slightly slower.

Linked List → far slower due to per-node allocations and poor cache locality.


![alt text](StackPushBenchmark.png)

Executive summary (median real time, 10 trials, 50M pushes/run)

Vector (STL, reserve): ~2.7 s → fastest

Dynamic array (custom): ~3.2 s (≈ 18% slower than fastest)

Linked list: ~12.5 s (≈ 4.6× slower than fastest)