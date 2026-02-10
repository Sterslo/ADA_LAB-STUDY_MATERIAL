# 📖 Dynamic Programming - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 📚 Table of Contents
1. [0-1 Knapsack (DP Table)](#1-0-1-knapsack-dp-table)
2. [0-1 Knapsack (Set-based)](#2-0-1-knapsack-set-based)
3. [Matrix Chain Multiplication](#3-matrix-chain-multiplication)
4. [Multistage Graph](#4-multistage-graph)
5. [DP Fundamentals](#dp-fundamentals)

---

## 🎯 What is Dynamic Programming?

**Dynamic Programming** = Recursion + Memoization (storing results)

### Key Characteristics:
1. **Optimal Substructure**: Optimal solution contains optimal solutions to subproblems
2. **Overlapping Subproblems**: Same subproblems are solved multiple times

### DP Approaches:
- **Top-Down (Memoization)**: Recursion + caching results
- **Bottom-Up (Tabulation)**: Build table iteratively from base cases

---

## 1. 0-1 Knapsack (DP Table)
**File**: `0-1knapusingdptable.cpp`

### 🎯 Problem Statement
Given:
- `n` items, each with weight `w[i]` and value `v[i]`
- Knapsack capacity `W`

Find: **Maximum value** that can be obtained without exceeding capacity

**Constraint**: Each item can be taken 0 or 1 time (cannot break items)

### 📊 Complexity Analysis
- **Time Complexity**: O(n × W)
- **Space Complexity**: O(n × W) for table
- **Pseudo-polynomial**: Depends on W (not polynomial in input size)

### 🔄 DP Table Definition
```
dp[i][w] = maximum value using first i items with capacity w

Base Cases:
- dp[0][w] = 0 (no items, value = 0)
- dp[i][0] = 0 (capacity = 0, value = 0)

Recurrence:
dp[i][w] = max(
    dp[i-1][w],              // don't include item i
    v[i] + dp[i-1][w-w[i]]   // include item i (if w[i] <= w)
)
```

### 📝 Example (Dry Run)
```
Items:
Item  Weight  Value
 1      2       3
 2      3       4
 3      4       5
 4      5       6

Capacity W = 5
```

**Building DP Table**:
```
      w=0  w=1  w=2  w=3  w=4  w=5
i=0    0    0    0    0    0    0   (no items)
i=1    0    0    3    3    3    3   (item1: w=2,v=3)
i=2    0    0    3    4    4    7   (item2: w=3,v=4)
i=3    0    0    3    4    5    7   (item3: w=4,v=5)
i=4    0    0    3    4    5    7   (item4: w=5,v=6)

Explanation of key cells:
dp[2][5]: capacity=5 with items 1,2
  - Don't take item2: dp[1][5] = 3
  - Take item2: v[2] + dp[1][5-3] = 4 + dp[1][2] = 4 + 3 = 7
  - max(3, 7) = 7 ✓

dp[3][4]: capacity=4 with items 1,2,3
  - Don't take item3: dp[2][4] = 4
  - Take item3: v[3] + dp[2][4-4] = 5 + dp[2][0] = 5 + 0 = 5
  - max(4, 5) = 5 ✓

Answer: dp[4][5] = 7
```

### 🔍 Backtracking (Finding Items)
```
Start from dp[n][W]
While i > 0 and w > 0:
  if dp[i][w] != dp[i-1][w]:
    Item i is included
    w = w - weight[i]
  i = i - 1

Items included: 1 and 2 (weights: 2+3=5, values: 3+4=7)
```

### 💡 Key Points
- ✅ Guarantees optimal solution
- ✅ Classic DP problem - memorize pattern
- ⚠️ Pseudo-polynomial time (not true polynomial)
- 📊 Space can be optimized to O(W) using 1D array

### 🎓 Exam Important
**Why not Greedy?**
```
Greedy (value/weight ratio):
Item1: 3/2 = 1.5
Item2: 4/3 = 1.33
Item3: 5/4 = 1.25
Item4: 6/5 = 1.2

Greedy picks Item1 (w=2,v=3) then Item2 (w=3,v=4) = total 7 ✓ (works here)

Counter-example where greedy fails:
Items: {(1,1), (3,4), (4,5)}  Capacity=4
Greedy: (1,1)+(3,4) = value 5
Optimal: (4,5) = value 5 (same)
Actually greedy can fail: {(2,1), (2,1), (2,1)}  Capacity=4
Greedy picks any 2 = value 2, optimal is value 2 (works)

Better counter: {(10,60), (20,100), (30,120)}  Capacity=50
Greedy (v/w): picks 10,20 = value 160
Optimal: 20,30 = value 220 ✗ Greedy fails!
```

---

## 2. 0-1 Knapsack (Set-based)
**File**: `0-1Knapsackusingset.cpp`

### 🎯 Concept
Alternative approach using **set representation** of possible values at each weight.

### 📊 Complexity Analysis
- **Time Complexity**: O(n × W)
- **Space Complexity**: O(W)
- **Advantage**: May be more efficient if many weights have same maximum value

### 🔄 Algorithm
```
1. For each item i:
     For each weight w from W down to weight[i]:
       if w >= weight[i]:
         value[w] = max(value[w], value[w-weight[i]] + val[i])

2. Answer: value[W]
```

### 💡 Key Points
- ✅ Same principle as table approach
- ✅ More space-efficient (1D array)
- 📊 Easier to code in exams
- 🎯 Reverse iteration avoids overwriting needed values

---

## 3. Matrix Chain Multiplication
**File**: `MCM.cpp`

### 🎯 Problem Statement
Given chain of matrices: A₁ × A₂ × A₃ × ... × Aₙ

Find: **Minimum number of scalar multiplications** needed to compute product

**Key**: Matrix multiplication is associative  
- (A × B) × C ≠ A × (B × C) in value
- But *cost* of computation differs!

### 📊 Complexity Analysis
- **Time Complexity**: O(n³)
- **Space Complexity**: O(n²)

### 🔄 DP Table Definition
```
Matrix dimensions: p[0] × p[1], p[1] × p[2], ..., p[n-1] × p[n]
(n matrices, n+1 dimensions)

dp[i][j] = minimum scalar multiplications to compute Aᵢ × Aᵢ₊₁ × ... × Aⱼ

Base Case:
dp[i][i] = 0 (single matrix, no multiplication)

Recurrence:
dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])
           for k = i to j-1

Cost of merging two subchains at k:
- Left part: dp[i][k]
- Right part: dp[k+1][j]  
- Merge cost: p[i-1] * p[k] * p[j]
```

### 📝 Example (Dry Run)
```
Matrices: A₁(10×20) × A₂(20×30) × A₃(30×40) × A₄(40×30)
Dimensions array: p = [10, 20, 30, 40, 30]
n = 4 matrices
```

**DP Table Building**:
```
Length 1 (single matrices):
dp[1][1] = 0, dp[2][2] = 0, dp[3][3] = 0, dp[4][4] = 0

Length 2 (2 consecutive matrices):
dp[1][2]: A₁ × A₂
  Only split at k=1: 0 + 0 + (10×20×30) = 6000

dp[2][3]: A₂ × A₃
  Only split at k=2: 0 + 0 + (20×30×40) = 24000

dp[3][4]: A₃ × A₄
  Only split at k=3: 0 + 0 + (30×40×30) = 36000

Length 3 (3 consecutive matrices):
dp[1][3]: A₁ × A₂ × A₃
  Split at k=1: dp[1][1] + dp[2][3] + (10×20×40) = 0 + 24000 + 8000 = 32000
  Split at k=2: dp[1][2] + dp[3][3] + (10×30×40) = 6000 + 0 + 12000 = 18000 ✓
  min = 18000

dp[2][4]: A₂ × A₃ × A₄
  Split at k=2: dp[2][2] + dp[3][4] + (20×30×30) = 0 + 36000 + 18000 = 54000
  Split at k=3: dp[2][3] + dp[4][4] + (20×40×30) = 24000 + 0 + 24000 = 48000 ✓
  min = 48000

Length 4 (all matrices):
dp[1][4]: A₁ × A₂ × A₃ × A₄
  Split at k=1: dp[1][1] + dp[2][4] + (10×20×30) = 0 + 48000 + 6000 = 54000
  Split at k=2: dp[1][2] + dp[3][4] + (10×30×30) = 6000 + 36000 + 9000 = 51000
  Split at k=3: dp[1][3] + dp[4][4] + (10×40×30) = 18000 + 0 + 12000 = 30000 ✓
  min = 30000

Answer: 30000 scalar multiplications
Optimal parenthesization: ((A₁ × A₂ × A₃) × A₄)
```

### 🔍 Reconstructing Parenthesization
```
Use split[i][j] to store optimal k for each subproblem
Recursively print: 
  print(i, split[i][j])
  print(split[i][j]+1, j)
```

### 💡 Key Points
- ✅ Classic DP - interval DP pattern
- ✅ Order of multiplication DOES NOT change result, only cost
- 🎯 Optimal substructure: optimal split contains optimal subsolutions
- 📊 Build table diagonally (increasing length)

### 🎓 Exam Tip
**Remember**: Matrix (p×q) × (q×r) requires p×q×r scalar multiplications
Cost depends on parenthesization, not associativity property.

---

## 4. Multistage Graph
**File**: `MGP.cpp`

### 🎯 Problem Statement
**Multistage Graph**: Directed, weighted graph divided into k stages
- Stage 1: Source vertex
- Stage k: Destination vertex
- Edges only go from stage i to stage i+1

Find: **Shortest path from source to destination**

### 📊 Complexity Analysis
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)
- **Better than**: Dijkstra for this special structure

### 🔄 DP Formulation
```
cost[i] = minimum cost to reach destination from vertex i

Base Case:
cost[destination] = 0

Recurrence (backward):
cost[i] = min(weight(i,j) + cost[j]) for all edges (i,j)

OR Forward:
cost[i] = minimum cost to reach i from source
cost[i] = min(cost[j] + weight(j,i)) for all edges (j,i)
```

### 📝 Example (Dry Run)
```
Graph (4 stages):
Stage 1   Stage 2   Stage 3   Stage 4
  (1)-----2----→(2)----3----→(5)----2----→(7)
    \           / \           /            
     1        4    2        3             
      \     /       \     /              
       →(3)----2----→(6)----1----→(7)
          \                /
           -----5----→(4)
                       
Source = 1, Destination = 7
```

**Backward DP**:
```
Stage 4: cost[7] = 0 (destination)

Stage 3:
cost[5] = 0 + 2 = 2 (only edge to 7)
cost[6] = 0 + 1 = 1

Stage 2:
cost[2] = min(3+2, 2+1) = min(5, 3) = 3
cost[3] = min(2+1) = 3

Stage 1:
cost[1] = min(2+3, 1+3) = min(5, 4) = 4

Shortest path cost = 4
Path: 1 → 3 → 6 → 7 (costs: 1+2+1 = 4)
```

### 💡 Key Points
- ✅ Specialized DP for staged graphs
- ✅ More efficient than general shortest path
- 🎯 Used in resource allocation, project scheduling
- 📊 Can work forward or backward

---

## 📊 DP Fundamentals

### When to Use DP?

**Checklist**:
1. ✅ Problem asks for optimal value (max/min)
2. ✅ Can break into smaller subproblems
3. ✅ Subproblems overlap (same problems solved multiple times)
4. ✅ Has optimal substructure

### DP Steps:

**Step 1: Define State**
- What does dp[i] or dp[i][j] represent?

**Step 2: Find Recurrence**
- How does dp[i] relate to smaller subproblems?

**Step 3: Base Cases**
- What are the smallest subproblems with known answers?

**Step 4: Order of Computation**
- Bottom-up: Build from base cases
- Top-down: Recursion with memoization

**Step 5: Extract Answer**
- Where is the final answer stored?

### Common DP Patterns:

1. **Linear DP**: dp[i] depends on dp[i-1], dp[i-2], ...
   - Examples: Fibonacci, Climbing Stairs

2. **2D DP**: dp[i][j] depends on previous rows/columns
   - Examples: Knapsack, Edit Distance, LCS

3. **Interval DP**: dp[i][j] for range [i, j]
   - Examples: Matrix Chain Multiplication, Palindrome Partitioning

4. **State Machine DP**: Different states at each position
   - Examples: Stock Buy/Sell, House Robber

---

## 📊 Comparison Table

| Problem | Type | Time | Space | Key Technique |
|---------|------|------|-------|---------------|
| **0-1 Knapsack** | 2D DP | O(nW) | O(nW) or O(W) | Choice: take or skip |
| **MCM** | Interval DP | O(n³) | O(n²) | Try all split points |
| **Multistage Graph** | Graph DP | O(V+E) | O(V) | Stage-by-stage optimization |
| **LCS** | 2D DP | O(mn) | O(mn) or O(min(m,n)) | Match or skip characters |

---

## 💭 Common Interview Questions

**Q1**: Difference between DP and Greedy?  
**A**: 
- Greedy: Makes locally optimal choice at each step (may not be globally optimal)
- DP: Explores all possibilities, guarantees global optimum

**Q2**: When does Greedy work instead of DP?  
**A**: When problem has **greedy choice property** - local optimum leads to global optimum
- Example: Fractional Knapsack (greedy works), 0-1 Knapsack (DP needed)

**Q3**: Difference between Memoization and Tabulation?  
**A**: 
- Memoization: Top-down, recursion + cache (solve on demand)
- Tabulation: Bottom-up, iterative (solve all subproblems)

**Q4**: How to optimize space in DP?  
**A**: 
- If dp[i] only depends on dp[i-1], use two variables instead of array
- If dp[i][j] only needs previous row, use 2 rows instead of full table

**Q5**: Is Knapsack DP polynomial time?  
**A**: **Pseudo-polynomial** - depends on W (value), not input size. True complexity is O(n × 2^(bits in W))

---

## 🎯 Exam Strategy

### Must Remember:

1. **0-1 Knapsack Recurrence**:
   ```
   dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w-weight[i]])
   ```

2. **MCM Recurrence**:
   ```
   dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])
   ```

3. **Table Filling Order**:
   - Knapsack: Row by row (or column by column)
   - MCM: By increasing length (diagonal by diagonal)

4. **Space Optimization**:
   - 2D → 1D when current row only needs previous row
   - Reverse iteration to avoid overwriting

---

## ⚙️ Compilation & Execution

```bash
g++ -std=c++17 -O2 -o knap01.exe 0-1knapusingdptable.cpp
g++ -std=c++17 -O2 -o mcm.exe MCM.cpp
g++ -std=c++17 -O2 -o mgp.exe MGP.cpp

.\knap01.exe
.\mcm.exe
```

---

## 📚 Related Topics

- **Longest Common Subsequence (LCS)**
- **Edit Distance**
- **Longest Increasing Subsequence (LIS)**
- **Coin Change Problem**
- **Subset Sum Problem**
- **Partition Problem**
- **Rod Cutting Problem**

---

**Pro Tip for Exams**: Practice drawing DP tables by hand. Visualizing helps understand state transitions!
