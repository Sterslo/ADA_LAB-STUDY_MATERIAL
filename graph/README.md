# 📖 Graph Algorithms - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 📚 Table of Contents
1. [Dijkstra's Algorithm](#1-dijkstras-algorithm)
2. [Kruskal's Algorithm](#2-kruskals-algorithm)
3. [Prim's Algorithm](#3-prims-algorithm)
4. [Floyd-Warshall Algorithm](#4-floyd-warshall-algorithm)
5. [Comparison](#comparison-table)

---

## 1. Dijkstra's Algorithm
**File**: `dijkstra.cpp`

### 🎯 Concept
Finds **shortest path from single source** to all other vertices in a **weighted graph with non-negative weights**. Uses greedy approach.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Adjacency Matrix: O(V²)
  - With Min-Heap: O((V+E) log V)
- **Space Complexity**: O(V)
- **Limitation**: **Does NOT work with negative weights**

### 🔄 Algorithm Steps
```
1. Initialize:
   - dist[source] = 0
   - dist[all others] = ∞
   - visited[all] = false

2. Repeat V times:
   a. Pick unvisited vertex u with minimum dist[u]
   b. Mark u as visited
   c. For each neighbor v of u:
      if dist[u] + weight(u,v) < dist[v]:
         dist[v] = dist[u] + weight(u,v)  (Relaxation)
```

### 📝 Example (Dry Run)
```
Graph:
    (0)--4--(1)--8--(2)
     |      / |      |
     8    11  7      2
     |   /    |      |
    (7)--1--(6)--6--(3)
     |       /|      |
     7     2/ |      4
     |    /   4      |
    (8)-4    |      |
             (5)--14-(4)

Source = 0
```

**Step-by-step**:
```
Initial: dist = [0, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞]
         visited = [F, F, F, F, F, F, F, F, F]

Step 1: Pick u=0 (min dist=0)
        Neighbors: 1(4), 7(8)
        Update: dist = [0, 4, ∞, ∞, ∞, ∞, ∞, 8, ∞]
        visited[0] = true

Step 2: Pick u=1 (min dist=4)
        Neighbors: 0(visited), 2(8), 7(11)
        Update: dist = [0, 4, 12, ∞, ∞, ∞, ∞, 8, ∞]
        visited[1] = true

Step 3: Pick u=7 (min dist=8)
        Neighbors: 0(visited), 1(11), 6(1), 8(7)
        Update: dist = [0, 4, 12, ∞, ∞, ∞, 9, 8, 15]
        visited[7] = true

Step 4: Pick u=6 (min dist=9)
        Neighbors: 7(visited), 5(2), 8(4)
        Update: dist = [0, 4, 12, ∞, ∞, 11, 9, 8, 13]
        visited[6] = true

...continue until all vertices processed

Final: dist = [0, 4, 12, 19, 21, 11, 9, 8, 14]
```

### 💡 Key Points
- ✅ **Greedy algorithm** - always picks nearest unvisited vertex
- ✅ Works perfectly for non-negative weights
- ❌ **Fails with negative weights** (use Bellman-Ford instead)
- 🎯 Single-source shortest path
- 📊 Similar to Prim's but for shortest paths

### 🎓 Exam Important
**Why not negative weights?**
- Greedy choice may not be optimal with negative weights
- Already visited nodes might get shorter path later

**Example failing with negative weight**:
```
    1
 (A)---(B)
  |     /
 -2   -3
  |  /
 (C)

Dijkstra picks A→B (cost 1)
But optimal is A→C→B (cost -5)
```

---

## 2. Kruskal's Algorithm
**File**: `kruskals.cpp`

### 🎯 Concept
Finds **Minimum Spanning Tree (MST)** using **edge-centric greedy approach**. Sorts edges by weight and adds them if they don't form cycle.

### 📊 Complexity Analysis
- **Time Complexity**: O(E log E) or O(E log V)
  - Sorting edges: O(E log E)
  - Union-Find operations: O(E α(V)) ≈ O(E)
- **Space Complexity**: O(V + E)
- **Uses**: Disjoint Set Union (DSU) / Union-Find

### 🔄 Algorithm Steps
```
1. Sort all edges in non-decreasing order of weight
2. Initialize Disjoint Set (each vertex is separate set)
3. For each edge (u, v, weight) in sorted order:
   a. If u and v belong to different sets:
      - Add edge to MST
      - Union the sets containing u and v
   b. Else: skip (would create cycle)
4. Stop when MST has (V-1) edges
```

### 🗂️ Disjoint Set Union (DSU)
```cpp
// Operations needed:
- find(x): Find representative of set containing x
- union(x, y): Merge sets containing x and y

// Optimizations:
- Path compression: Make tree flat during find
- Union by rank/size: Attach smaller tree to larger
```

### 📝 Example (Dry Run)
```
Graph:
      10        24
  (0)-----(1)-------(2)
   | \      |       /|
 6 |  5\    |28   /  |18
   |    \   |   /22  |
  (3)----(4)-----(5)-/
      25      12

Edges sorted by weight:
5: (0,4)    12: (4,5)
6: (0,3)    18: (2,5)
10: (0,1)   22: (2,4)
24: (1,2)   25: (3,4)
28: (1,4)
```

**Step-by-step**:
```
Initial: MST = {}, Sets: {0},{1},{2},{3},{4},{5}

Step 1: Edge (0,4) weight=5
        find(0)=0, find(4)=4 → Different sets
        Add to MST, Union(0,4)
        MST = {(0,4)}, Sets: {0,4},{1},{2},{3},{5}

Step 2: Edge (0,3) weight=6
        find(0)=0, find(3)=3 → Different sets
        Add to MST, Union(0,3)
        MST = {(0,4),(0,3)}, Sets: {0,3,4},{1},{2},{5}

Step 3: Edge (0,1) weight=10
        find(0)=0, find(1)=1 → Different sets
        Add to MST, Union(0,1)
        MST = {(0,4),(0,3),(0,1)}, Sets: {0,1,3,4},{2},{5}

Step 4: Edge (4,5) weight=12
        find(4)=0, find(5)=5 → Different sets
        Add to MST, Union(4,5)
        MST = {(0,4),(0,3),(0,1),(4,5)}, Sets: {0,1,3,4,5},{2}

Step 5: Edge (2,5) weight=18
        find(2)=2, find(5)=0 → Different sets
        Add to MST, Union(2,5)
        MST = {(0,4),(0,3),(0,1),(4,5),(2,5)}
        Sets: {0,1,2,3,4,5}

MST complete! (V-1 = 5 edges)
Total weight = 5+6+10+12+18 = 51

Edges (22,24,25,28) rejected as they would form cycles
```

### 💡 Key Points
- ✅ **Edge-centric** greedy approach
- ✅ Works on disconnected graphs (creates forest)
- ✅ Efficient for sparse graphs (fewer edges)
- 🎯 Uses Union-Find data structure
- 📊 Easier to understand than Prim's

### 🎓 Exam Important
**MST Properties**:
- Has exactly V-1 edges
- Connects all vertices with minimum total weight
- No cycles
- May not be unique (if multiple edges have same weight)

---

## 3. Prim's Algorithm
**File**: `prims.cpp`

### 🎯 Concept
Finds **Minimum Spanning Tree (MST)** using **vertex-centric greedy approach**. Grows MST one vertex at a time by adding minimum weight edge.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Adjacency Matrix: O(V²)
  - With Min-Heap: O((V+E) log V)
- **Space Complexity**: O(V²) for matrix, O(V) for heap
- **Better than Kruskal** for dense graphs

### 🔄 Algorithm Steps
```
1. Initialize:
   - Pick any vertex as starting point
   - key[start] = 0, key[others] = ∞
   - parent[all] = -1
   - inMST[all] = false

2. Repeat V times:
   a. Pick vertex u with minimum key[] not in MST
   b. Add u to MST (inMST[u] = true)
   c. For each neighbor v of u not in MST:
      if weight(u,v) < key[v]:
         key[v] = weight(u,v)
         parent[v] = u
```

### 📝 Example (Dry Run)
```
Graph (same as Kruskal example):
      10        24
  (0)-----(1)-------(2)
   | \      |       /|
 6 |  5\    |28   /  |18
   |    \   |   /22  |
  (3)----(4)-----(5)-/
      25      12

Start from vertex 0
```

**Step-by-step**:
```
Initial: key    = [0, ∞, ∞, ∞, ∞, ∞]
         parent = [-1,-1,-1,-1,-1,-1]
         inMST  = [F, F, F, F, F, F]

Step 1: Pick u=0 (min key=0)
        inMST[0] = true
        Update neighbors: 1(10), 3(6), 4(5)
        key    = [0, 10, ∞, 6, 5, ∞]
        parent = [-1, 0,-1, 0, 0,-1]

Step 2: Pick u=4 (min key=5)
        inMST[4] = true
        Update neighbors: 0(already in), 3(25>6,no), 5(12)
        key    = [0, 10, ∞, 6, 5, 12]
        parent = [-1, 0,-1, 0, 0, 4]

Step 3: Pick u=3 (min key=6)
        inMST[3] = true
        Update neighbors: 0(in MST), 4(in MST)
        No updates

Step 4: Pick u=1 (min key=10)
        inMST[1] = true
        Update neighbors: 0(in MST), 2(24), 4(in MST)
        key    = [0, 10, 24, 6, 5, 12]
        parent = [-1, 0, 1, 0, 0, 4]

Step 5: Pick u=5 (min key=12)
        inMST[5] = true
        Update neighbors: 2(18<24), 4(in MST)
        key    = [0, 10, 18, 6, 5, 12]
        parent = [-1, 0, 5, 0, 0, 4]

Step 6: Pick u=2 (min key=18)
        inMST[2] = true
        Complete!

MST Edges (from parent array):
0-1 (10), 0-3 (6), 0-4 (5), 4-5 (12), 5-2 (18)
Total weight = 51
```

### 💡 Key Points
- ✅ **Vertex-centric** greedy approach
- ✅ Similar to Dijkstra's (uses key array)
- ✅ Better for dense graphs
- 🎯 Starts from one vertex and grows MST
- 📊 More intuitive than Kruskal for dense graphs

---

## 4. Floyd-Warshall Algorithm
**File**: `allPairdp.cpp`

### 🎯 Concept
Finds **shortest paths between ALL pairs** of vertices. Uses **Dynamic Programming**. Works with negative weights but detects negative cycles.

### 📊 Complexity Analysis
- **Time Complexity**: O(V³)
- **Space Complexity**: O(V²)
- **Works with**: Negative weights (but not negative cycles)

### 🔄 Algorithm Steps
```
1. Initialize distance matrix:
   - dist[i][i] = 0 (same vertex)
   - dist[i][j] = weight(i,j) if edge exists
   - dist[i][j] = ∞ if no edge

2. For each intermediate vertex k (0 to V-1):
     For each source vertex i:
       For each destination vertex j:
         if dist[i][k] + dist[k][j] < dist[i][j]:
            dist[i][j] = dist[i][k] + dist[k][j]

3. Check for negative cycle:
   if dist[i][i] < 0 for any i → negative cycle exists
```

### 🎯 DP Interpretation
```
dist[i][j] = shortest path from i to j using vertices {0,1,...,k}

Recurrence:
dist[i][j] = min(dist[i][j],                    // don't use k
                  dist[i][k] + dist[k][j])      // use k as intermediate
```

### 📝 Example (Dry Run)
```
Graph:
    (0)--5-→(1)
     |  ↗    ↓
    -2 10    3
     ↓  ↑    |
    (2)--4-→(3)

Initial Distance Matrix:
     0   1   2   3
0 [  0,  5,  ∞,  ∞ ]
1 [  ∞,  0,  3,  ∞ ]
2 [ -2,  ∞,  0,  4 ]
3 [  ∞, 10,  ∞,  0 ]
```

**Iterations**:
```
k=0 (use vertex 0 as intermediate):
- Check all pairs if path through 0 is shorter
- dist[2][1] = min(∞, dist[2][0]+dist[0][1]) = min(∞, -2+5) = 3
     0   1   2   3
0 [  0,  5,  ∞,  ∞ ]
1 [  ∞,  0,  3,  ∞ ]
2 [ -2,  3,  0,  4 ]
3 [  ∞, 10,  ∞,  0 ]

k=1 (use vertex 1 as intermediate):
- dist[0][2] = min(∞, dist[0][1]+dist[1][2]) = min(∞, 5+3) = 8
- dist[0][3] = min(∞, dist[0][1]+dist[1][3]) = ∞
     0   1   2   3
0 [  0,  5,  8,  ∞ ]
1 [  ∞,  0,  3,  ∞ ]
2 [ -2,  3,  6,  4 ]
3 [  ∞, 10, 13,  0 ]

k=2 (use vertex 2 as intermediate):
- dist[0][1] = min(5, dist[0][2]+dist[2][1]) = min(5, 8+3) = 5
- Many updates...
     0   1   2   3
0 [  0,  5,  8, 12 ]
1 [  1,  0,  3,  7 ]
2 [ -2,  3,  0,  4 ]
3 [  8, 10, 13,  0 ]

k=3 (use vertex 3 as intermediate):
- dist[1][0] = min(1, dist[1][3]+dist[3][0]) = min(1, 7+8) = 1
- More updates...

Final Matrix:
     0   1   2   3
0 [  0,  5,  8, 12 ]
1 [  1,  0,  3,  7 ]
2 [ -2,  3,  0,  4 ]
3 [  8, 10, 13,  0 ]
```

### 💡 Key Points
- ✅ **All-pairs shortest path** in single run
- ✅ Works with negative weights
- ✅ Simple DP implementation
- ✅ Can detect negative cycles
- ❌ O(V³) - expensive for large graphs
- 🎯 Best for dense graphs or small V

### 🎓 Exam Important
**Negative Cycle Detection**:
After algorithm completes, if `dist[i][i] < 0` for any i, graph has negative cycle.

**Why?** If shortest path from i to i is negative, we can keep going around that cycle infinitely to get smaller path.

---

## 📊 Comparison Table

| Algorithm | Type | Complexity | Negative Weights? | Use Case |
|-----------|------|------------|------------------|----------|
| **Dijkstra** | Single-source SP | O(V²) or O(ElogV) | ❌ No | Non-negative weights, one source |
| **Bellman-Ford** | Single-source SP | O(VE) | ✅ Yes | Negative weights, one source |
| **Floyd-Warshall** | All-pairs SP | O(V³) | ✅ Yes (no cycles) | All-pairs, dense graph |
| **Kruskal** | MST | O(E log E) | N/A | Sparse graphs, sorted edges |
| **Prim** | MST | O(V²) or O(ElogV) | N/A | Dense graphs |

**SP = Shortest Path, MST = Minimum Spanning Tree**

---

## 🎯 Algorithm Selection Guide

### For Shortest Path:

**Choose Dijkstra when:**
- ✅ Single source to all destinations
- ✅ All weights are non-negative
- ✅ Need fast solution

**Choose Floyd-Warshall when:**
- ✅ Need all-pairs shortest paths
- ✅ Graph is small to medium (V ≤ 400)
- ✅ May have negative weights

**Choose Bellman-Ford when:**
- ✅ Single source with negative weights
- ✅ Need to detect negative cycles

### For Minimum Spanning Tree:

**Choose Kruskal when:**
- ✅ Graph is sparse (E << V²)
- ✅ Edges are already sorted
- ✅ Need simple implementation

**Choose Prim when:**
- ✅ Graph is dense (E ≈ V²)
- ✅ Have efficient min-heap
- ✅ Starting vertex is known

---

## 💭 Common Interview Questions

**Q1**: Why doesn't Dijkstra work with negative weights?  
**A**: Greedy choice may be wrong - a longer path might become shorter through negative edge later.

**Q2**: Difference between Kruskal and Prim?  
**A**: Kruskal is edge-centric (sort edges), Prim is vertex-centric (grow from vertex).

**Q3**: When to use Floyd-Warshall vs running Dijkstra V times?  
**A**: Floyd-Warshall: dense graph or need simplicity. V×Dijkstra: sparse graph, better O(V²E).

**Q4**: Can MST have cycles?  
**A**: No! Tree by definition is acyclic. MST has exactly V-1 edges.

**Q5**: Is MST unique?  
**A**: Not always. If multiple edges have same weight, multiple MSTs possible.

**Q6**: What is Union-Find used for in Kruskal?  
**A**: To detect cycles efficiently - if both endpoints in same set, adding edge creates cycle.

---

## ⚙️ Compilation & Execution

```bash
g++ -std=c++17 -O2 -o dijkstra.exe dijkstra.cpp
g++ -std=c++17 -O2 -o kruskal.exe kruskals.cpp
g++ -std=c++17 -O2 -o prim.exe prims.cpp
g++ -std=c++17 -O2 -o floyd.exe allPairdp.cpp

.\dijkstra.exe
.\kruskal.exe
```

---

## 📚 Key Concepts for Exam

1. **Greedy Algorithms**: Dijkstra, Kruskal, Prim
2. **Dynamic Programming**: Floyd-Warshall
3. **Data Structures**: DSU/Union-Find, Min-Heap, Priority Queue
4. **Graph Representations**: Adjacency Matrix, Adjacency List
5. **Relaxation**: Core concept in shortest path algorithms
6. **Path Reconstruction**: Using parent/predecessor arrays
