# ADA Lab - Complete Study Guide

**Student**: Prexit Joshi (233118) | CSE 4th Sem, Section 2

---

##  How to Use This Repository for Exam Preparation

###  Study Order (Recommended):

1. **Start with Basics** :
   - [searching/README.md](searching/README.md) - Binary Search, Peak Finding
   - [divide-conquer/README.md](divide-conquer/README.md) - Max-Min
   - [sorting/README.md](sorting/README.md) - All sorting algorithms

2. **Build Foundation** :
   - [greedy/README.md](greedy/README.md) - Knapsack, Activity Selection
   - [graph/README.md](graph/README.md) - Dijkstra, MST algorithms

3. **Master Complex Topics** :
   - [dynamic-programming/README.md](dynamic-programming/README.md) - DP problems
   - [backtracking/README.md](backtracking/README.md) - N-Queens

4. **Specialized Algorithms** :
   - [advanced/README.md](advanced/README.md) - Strassen, Magic Square
   - [similarity/README.md](similarity/README.md) - Jaccard, Cosine

---

## What's in Each README?

Each category folder has a detailed `README.md` with:

### Theory & Concepts
- Clear explanations of how algorithms work
- When to use which algorithm
- Design patterns and paradigms

### Complexity Analysis
- Time complexity with derivations
- Space complexity
- Best/Average/Worst case scenarios
- Recurrence relations and Master Theorem

### Detailed Examples
- Step-by-step dry runs
- Visual representations (ASCII art)
- Multiple examples for clarity

### Exam Preparation
- Key points to remember
- Common mistakes to avoid
- Interview questions with answers
- Comparison tables

### Implementation
- Modern C++17 code
- Well-commented
- Ready to compile and run

---

## Category-wise Content Summary

### 1. Sorting (6 algorithms)
**File**: [sorting/README.md](sorting/README.md)

**Covers**:
- Bubble Sort - O with optimization
- Selection Sort - Minimum swaps
- Insertion Sort - Best for nearly sorted
- Merge Sort - Guaranteed O(n log n)
- Quick Sort - Fastest in practice
- Comparison table & decision guide

**Study Time**: 2-3 hours

---

### 2. Searching (3 algorithms)
**File**: [searching/README.md](searching/README.md)

**Covers**:
- Binary Search - O(log n) with overflow prevention
- Peak Finding 1D - Finding local maximum
- Peak Finding 2D - Matrix peak element
- Mathematical analysis of comparisons

**Study Time**: 1-2 hours

**Exam Weight**: (High)

---

### 3. \ud83c\udf33 Divide and Conquer (1 algorithm)
**File**: [divide-conquer/README.md](divide-conquer/README.md)

**Covers**:
- Max-Min Finding - 3n/2-2 comparisons
- D&C design pattern
- Master Theorem applications
- Comparison count analysis

**Study Time**: 1 hour

**Exam Weight**: (Medium)

---

### 4. Graph Algorithms (4 algorithms)
**File**: [graph/README.md](graph/README.md)

**Covers**:
- Dijkstra's Algorithm - Single-source shortest path
- Kruskal's Algorithm - MST with DSU
- Prim's Algorithm - MST vertex-centric
- Floyd-Warshall - All-pairs shortest path
- Graph representations
- When to use which algorithm

**Study Time**: 3-4 hours

**Exam Weight**: (Very High)

---

### 5. Dynamic Programming (4 problems)
**File**: [dynamic-programming/README.md](dynamic-programming/README.md)

**Covers**:
- 0-1 Knapsack - Classic DP problem
- Matrix Chain Multiplication - Interval DP
- Multistage Graph - Graph DP
- DP fundamentals and patterns
- Memoization vs Tabulation

**Study Time**: 4-5 hours (Most Complex!)

**Exam Weight**: (Very High)

---

### 6. Greedy Algorithms (2 problems)
**File**: [greedy/README.md](greedy/README.md)

**Covers**:
- Fractional Knapsack - Sort by ratio
- Activity Selection - Sort by finish time
- Greedy vs DP comparison
- Proof of correctness

**Study Time**: 1-2 hours

**Exam Weight**: (High)

---

### 7. Backtracking (1 problem)
**File**: [backtracking/README.md](backtracking/README.md)

**Covers**:
- N-Queens Problem - Classic backtracking
- Backtracking template
- Constraint satisfaction
- Pruning techniques

**Study Time**: 2 hours

**Exam Weight**: (High)

---

### 8. Advanced Algorithms (2 algorithms)
**File**: [advanced/README.md](advanced/README.md)

**Covers**:
- Strassen's Matrix Multiplication - O(n^2.807)
- Magic Square Generation - Siamese method
- Advanced D&C techniques

**Study Time**: 1-2 hours

**Exam Weight**: (Medium)

---

### 9.  Similarity Metrics (2 metrics)
**File**: [similarity/README.md](similarity/README.md)

**Covers**:
- Jaccard Similarity - Set-based
- Cosine Similarity - Vector-based
- Real-world applications
- When to use which metric

**Study Time**: 1 hour

**Exam Weight**: (Low-Medium)

---

## Exam Preparation Timeline

### 1 Week Before Exam:

**Day 1-2**: Sorting + Searching (Foundation)
- Complete [sorting/README.md](sorting/README.md)
- Complete [searching/README.md](searching/README.md)
- Practice dry runs on paper

**Day 3-4**: Graph Algorithms (Most Important!)
- Complete [graph/README.md](graph/README.md)
- Memorize Dijkstra, Kruskal, Prim
- Practice drawing graphs

**Day 5-6**: Dynamic Programming (Hardest!)
- Complete [dynamic-programming/README.md](dynamic-programming/README.md)
- Focus on 0-1 Knapsack and MCM
- Draw DP tables

**Day 7**: Revision
- Greedy ([greedy/README.md](greedy/README.md))
- Backtracking ([backtracking/README.md](backtracking/README.md))
- Quick review of all

### 1 Day Before Exam:

1. **Quick revision of key algorithms** (3 hours)
2. **Practice complexity analysis** (1 hour)
3. **Memorize important formulas** (1 hour)
4. **Sleep well!** 

---

## Must-Know for Exam

### Algorithms to Memorize:

1. **Binary Search** - Most basic, must know perfectly
2. **Merge Sort** - Complete working
3. **Quick Sort** - Partition logic
4. **Dijkstra** - Single-source shortest path
5. **Kruskal** - MST with DSU
6. **0-1 Knapsack** - DP table filling
7. **MCM** - Recurrence relation
8. **N-Queens** - Backtracking pattern

### Complexity Analysis Must-Know:

- **Master Theorem** - All three cases
- **Recurrence Relations** - How to solve
- **Big-O - Definitions
- **Best/Average/Worst** - For each sorting algorithm

### Comparison Questions:

Prepare comparisons between:
- Bubble vs Insertion vs Selection
- Merge Sort vs Quick Sort
- Dijkstra vs Floyd-Warshall
- Kruskal vs Prim
- Greedy vs DP
- 0-1 vs Fractional Knapsack
- Backtracking vs Brute Force

---

## How to Compile and Run

### Single Program:
```bash
g++ -std=c++17 -O2 -o output.exe folder/program.cpp
.\\output.exe
```

### Examples:
```bash
# Sorting
g++ -std=c++17 -O2 -o quick.exe sorting/quicksort.cpp
.\\quick.exe

# Graph
g++ -std=c++17 -O2 -o dijkstra.exe graph/dijkstra.cpp
.\\dijkstra.exe

# DP
g++ -std=c++17 -O2 -o knapsack.exe dynamic-programming/0-1knapusingdptable.cpp
.\\knapsack.exe
```

---

## Exam Strategy

### Theory Questions:

1. **Read question carefully** - Note keywords (best case, worst case, etc.)
2. **State time complexity first** - Shows you know the answer
3. **Draw diagrams** - Visual representations earn marks
4. **Show all steps** - Partial marks for method
5. **Write recurrence relation** - For recursive algorithms

### Coding Questions:

1. **Write algorithm in pseudocode first** - Shows understanding
2. **Mention complexity** - Time and space
3. **Handle edge cases** - Empty array, single element
4. **Use proper variable names** - Shows clarity
5. **Add comments** - Explain key steps

### Dry Run Questions:

1. **Make a table** - Organized presentation
2. **Show each iteration** - Step-by-step
3. **Circle/highlight changes** - Visual clarity
4. **Count comparisons/swaps** - If asked
5. **Verify final answer** - Check correctness

---

## Common Mistakes to Avoid

1. Forgetting base cases in recursion
2. Integer overflow in mid calculation (use `low + (high-low)/2`)
3. Mixing up Kruskal (edge-centric) and Prim (vertex-centric)
4. Thinking greedy works for 0-1 Knapsack (it doesn't!)
5. Forgetting to backtrack in N-Queens
6. Wrong order in DP table filling
7. Negative weights with Dijkstra (use Floyd-Warshall)

---

## \ud83d\udcda Additional Resources

### For Deep Dive:
1. CLRS (Cormen) - The bible of algorithms
2. Sedgewick - Algorithms in C++
3. GeeksforGeeks - Practice problems
4. LeetCode - Interview preparation

### Quick Revision:
1. Complexity cheat sheets in each README
2. Comparison tables in each README
3. This study guide!

---

## Self-Assessment Checklist

Before exam, can you:

### Sorting:
- [ ] Explain why Quick Sort is O(n\u00b2) worst case
- [ ] Draw Merge Sort recursion tree
- [ ] Dry run Bubble Sort with optimization
- [ ] Compare all 6 sorting algorithms

### Searching:
- [ ] Write Binary Search without bugs
- [ ] Explain peak finding logic
- [ ] Calculate number of comparisons

### Graph:
- [ ] Trace Dijkstra's algorithm on paper
- [ ] Explain DSU in Kruskal
- [ ] When to use which algorithm
- [ ] Floyd-Warshall DP table filling

### DP:
- [ ] Fill 0-1 Knapsack DP table
- [ ] Write MCM recurrence relation
- [ ] Backtrack to find items selected
- [ ] Explain optimal substructure

### Greedy:
- [ ] Prove fractional knapsack greedy works
- [ ] Why sort by finish time in activity selection
- [ ] When does greedy fail

### Backtracking:
- [ ] Explain N-Queens safety check
- [ ] Write backtracking template
- [ ] Calculate time complexity

---

## Final Tips

1. **Practice on paper** - Exams are written, not coded
2. **Time management** - Don't spend too long on one question
3. **Attempt all questions** - Partial marks count
4. **Revise one day before** - Don't learn new things last minute
5. **Stay calm** - You've got this! 
---

## Need Help?

**Stuck on a concept?**
1. Read the relevant README again
2. Run the program and observe output
3. Draw diagrams on paper
4. Try explaining to someone else

---

**Good luck with your exam preparation! **

**Remember**: Consistent practice > Last-minute cramming

---

*Study smart, not just hard!*  
Prexit Joshi (233118)
