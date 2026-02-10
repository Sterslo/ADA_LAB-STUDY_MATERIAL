# ADA Lab - Complete Study Material

**Student Details:**
- **Name**: Prexit Joshi
- **Roll Number**: 233118
- **Class**: CSE 4th Semester, Section 2

---

##Quick Start Guide

**For Exam Preparation:**
1. Open category folder (e.g., `sorting/`)
2. Read `README.md` for detailed theory with examples
3. Study the `.cpp` implementation
4. Compile and run to see output
5. Practice dry runs on paper

**Each category README contains:**
- Detailed algorithm explanations
- Complexity analysis with proofs
- Step-by-step dry run examples
- Key points for exams
- Common interview questions

---

## Course Overview

Complete implementation of **Analysis and Design of Algorithms (ADA)** lab programs with **comprehensive study notes** for each algorithm.

**Total Programs**: 25  
**Implementation**: Modern C++17  
**Categories**: 9 algorithmic domains  
**Study Material**: 10 detailed README files with examples

---

## 📂 Folder Structure & Programs

### 1. **Sorting Algorithms** (6 programs)
**Location**: `sorting/`

| Program | Algorithm | Complexity | Type |
|---------|-----------|------------|------|
| bubblesort.cpp | Bubble Sort | O(n²) | Comparison |
| selectionsort.cpp | Selection Sort | O(n²) | Comparison |
| insertionsort.cpp | Insertion Sort | O(n²) | Comparison |
| mergeSort.cpp | Merge Sort | O(n log n) | Divide & Conquer |
| quicksort.cpp | Quick Sort (Recursive) | O(n log n) | Divide & Conquer |
| iterativequicksort.cpp | Quick Sort (Iterative) | O(n log n) | Divide & Conquer |

---

### 2. **Searching Algorithms** (3 programs)
**Location**: `searching/`

| Program | Algorithm | Complexity | Approach |
|---------|-----------|------------|----------|
| binarysearch.cpp | Binary Search | O(log n) | Divide & Conquer |
| peakelement.cpp | Peak Finding (1D) | O(log n) | Binary Search |
| peakelement2d.cpp | Peak Finding (2D) | O(n log m) | Binary Search |

---

### 3. **Divide and Conquer** (1 program)
**Location**: `divide-conquer/`

| Program | Algorithm | Complexity | Purpose |
|---------|-----------|------------|---------|
| maxmin.cpp | Max-Min Finding | O(n) | Find max and min efficiently |

---

### 4. **Graph Algorithms** (4 programs)
**Location**: `graph/`

| Program | Algorithm | Complexity | Problem Type |
|---------|-----------|------------|--------------|
| dijkstra.cpp | Dijkstra's Algorithm | O(V²) | Single-source shortest path |
| kruskals.cpp | Kruskal's Algorithm | O(E log E) | Minimum Spanning Tree |
| prims.cpp | Prim's Algorithm | O(V²) | Minimum Spanning Tree |
| allPairdp.cpp | Floyd-Warshall | O(V³) | All-pairs shortest path |

---

### 5. **Dynamic Programming** (4 programs)
**Location**: `dynamic-programming/`

| Program | Algorithm | Complexity | Problem Type |
|---------|-----------|------------|--------------|
| 0-1knapusingdptable.cpp | 0-1 Knapsack (Table) | O(nW) | Optimization |
| 0-1Knapsackusingset.cpp | 0-1 Knapsack (Set) | O(nW) | Optimization |
| MCM.cpp | Matrix Chain Multiplication | O(n³) | Optimization |
| MGP.cpp | Multistage Graph | O(V+E) | Shortest Path |

---

### 6. **Greedy Algorithms** (2 programs)
**Location**: `greedy/`

| Program | Algorithm | Complexity | Problem Type |
|---------|-----------|------------|--------------|
| knapsack.cpp | Fractional Knapsack | O(n log n) | Optimization |
| activitysel.cpp | Activity Selection | O(n log n) | Scheduling |

---

### 7. **Backtracking** (1 program)
**Location**: `backtracking/`

| Program | Algorithm | Complexity | Problem Type |
|---------|-----------|------------|--------------|
| N-queens.cpp | N-Queens Problem | O(N!) | Constraint Satisfaction |

---

### 8. **Advanced Algorithms** (2 programs)
**Location**: `advanced/`

| Program | Algorithm | Complexity | Purpose |
|---------|-----------|------------|---------|
| strassen.cpp | Strassen's Matrix Multiplication | O(n^2.807) | Fast matrix multiplication |
| magicsquare.cpp | Magic Square Generation | O(n²) | Puzzle generation |

---

### 9. **Similarity Metrics** (2 programs)
**Location**: `similarity/`

| Program | Algorithm | Complexity | Use Case |
|---------|-----------|------------|----------|
| jaccard.cpp | Jaccard Similarity | O(n) | Set similarity |
| cosinsimilarity.cpp | Cosine Similarity | O(n) | Vector similarity |

---

## 🔧 Compilation Instructions

### Compile Individual Program
```bash
g++ -std=c++17 -O2 -o program.exe <folder>/<filename>.cpp
```

### Examples
```bash
# Sorting algorithm
g++ -std=c++17 -O2 -o quicksort.exe sorting/quicksort.cpp

# Graph algorithm
g++ -std=c++17 -O2 -o dijkstra.exe graph/dijkstra.cpp

# Dynamic programming
g++ -std=c++17 -O2 -o knapsack.exe dynamic-programming/0-1knapusingdptable.cpp
```

### Run Program
```bash
.\program.exe
```

---

## 📊 Complexity Summary

| Category | Best Case | Average Case | Worst Case |
|----------|-----------|--------------|------------|
| **Simple Sorting** | O(n) | O(n²) | O(n²) |
| **Advanced Sorting** | O(n log n) | O(n log n) | O(n²) |
| **Searching** | O(1) | O(log n) | O(n) |
| **Graph (MST)** | O(E log E) | O(E log V) | O(V²) |
| **Graph (Shortest Path)** | O(V²) | O(V²) | O(V³) |
| **Dynamic Programming** | O(n) | O(n²) - O(n³) | O(2^n) → O(n²) |
| **Greedy** | O(n) | O(n log n) | O(n log n) |
| **Backtracking** | O(N!) | O(N!) | O(N!) |

---

## 🎯 Key Concepts Covered

### Algorithm Design Paradigms
- ✅ Divide and Conquer (Merge Sort, Quick Sort, Binary Search, Strassen's)
- ✅ Dynamic Programming (Knapsack, MCM, Multistage Graph)
- ✅ Greedy Algorithms (Fractional Knapsack, Activity Selection, MST)
- ✅ Backtracking (N-Queens)

### Problem Types
- ✅ Sorting and Searching
- ✅ Graph Algorithms (Shortest Path, MST)
- ✅ Optimization Problems
- ✅ Matrix Operations
- ✅ Similarity Measures

---

## 📝 Implementation Features

All programs are implemented with:
- **Modern C++17** syntax
- **Vector-based** data structures (no raw arrays)
- **Professional formatting** and naming conventions
- **Comprehensive documentation** with complexity analysis
- **Test cases** with sample inputs/outputs
- **Performance timing** where applicable

---

## 📖 References

Each subfolder contains its own `README.md` with detailed explanations of programs in that category.

---

**Submitted By**: Prexit Joshi (233118)  
**Course**: CSE 4th Semester, Section 2  
**Subject**: Analysis and Design of Algorithms Lab
