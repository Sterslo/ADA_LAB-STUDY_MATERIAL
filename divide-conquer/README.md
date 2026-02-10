# 📖 Divide and Conquer - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 🎯 Divide & Conquer = DIVIDE → CONQUER → COMBINE

### Three Steps:
1. **DIVIDE**: Break into smaller subproblems
2. **CONQUER**: Solve recursively
3. **COMBINE**: Merge solutions

---

## Max-Min Finding
**File**: `maxmin.cpp`

### 🎯 Problem
Find both max and min with **minimum comparisons**.

### 📊 Complexity
- **Time**: O(n)
- **Comparisons**: 
  - Naive: 2n-2
  - D&C: **3n/2-2** ✓ 25% better!

### 🔄 Algorithm
```
maxmin(arr, low, high):
    if only 1 element:
        return (element, element)
    
    if only 2 elements:
        return (max, min)
    
    mid = (low + high) / 2
    (max1, min1) = maxmin(arr, low, mid)
    (max2, min2) = maxmin(arr, mid+1, high)
    
    // Combine
    max = max(max1, max2)  // 1 comparison
    min = min(min1, min2)  // 1 comparison
    
    return (max, min)
```

### 📝 Example
**Input**: [70, 250, 50, 80, 140, 12, 14]

```
Divide:
     [70,250,50,80,140,12,14]
      /                     \
  [70,250,50,80]        [140,12,14]
   /        \             /      \
[70,250]  [50,80]    [140,12]  [14]

Conquer & Combine:
[70,250]: max=250, min=70 (1 cmp)
[50,80]: max=80, min=50 (1 cmp)
[140,12]: max=140, min=12 (1 cmp)

[70,250,50,80]: max=250, min=50 (2 cmps)
[140,12,14]: max=140, min=12 (2 cmps)

Final: max=250, min=12 (2 cmps)

Total: 8 comparisons for n=7
Formula: 3(7)/2-2 = 8.5-2 ≈ 8 ✓
```

### 💡 Why Better?
Pairs compared first → winners compete for max, losers for min

---

## 📊 Master Theorem

**T(n) = aT(n/b) + f(n)**

| Algorithm | Recurrence | Result |
|-----------|------------|--------|
| Binary Search | T(n)=T(n/2)+O(1) | O(log n) |
| Merge Sort | T(n)=2T(n/2)+O(n) | O(n log n) |
| Max-Min | T(n)=2T(n/2)+O(1) | O(n) |

---

## ⚙️ Compilation

```bash
g++ -std=c++17 -O2 -o maxmin.exe maxmin.cpp
.\maxmin.exe
```

---

## 📚 Famous D&C Algorithms
- Merge Sort, Quick Sort
- Binary Search
- Strassen's Matrix Multiplication
- FFT, Karatsuba
