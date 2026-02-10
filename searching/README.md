# 📖 Searching Algorithms - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 📚 Table of Contents
1. [Binary Search](#1-binary-search)
2. [Peak Element (1D)](#2-peak-element-1d)
3. [Peak Element (2D)](#3-peak-element-2d)
4. [Comparison Table](#comparison-table)

---

## 1. Binary Search
**File**: `binarysearch.cpp`

### 🎯 Concept
Efficient search algorithm for **sorted arrays**. Repeatedly divides search interval in half. Compares target with middle element and eliminates half of remaining elements.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(1) - element at middle
  - Average Case: O(log n)
  - Worst Case: O(log n)
- **Space Complexity**: 
  - Recursive: O(log n) - recursion stack
  - Iterative: O(1)
- **Prerequisite**: Array must be **sorted**

### 🔄 Algorithm Steps
```
1. Find middle element: mid = low + (high - low) / 2
2. If target == arr[mid], element found!
3. If target < arr[mid], search in left half (high = mid - 1)
4. If target > arr[mid], search in right half (low = mid + 1)
5. Repeat until element found or search space exhausted
```

### 📝 Example (Dry Run)
**Input**: [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]  
**Target**: 23

```
Iteration 1:
Array: [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]
       low=0           mid=5            high=10
       arr[mid] = 23 == target → FOUND at index 5!
```

**Target**: 45

```
Iteration 1:
[2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]
 low=0         mid=5              high=10
arr[mid]=23 < 45 → search right half

Iteration 2:
                [38, 45, 56, 67, 78]
                low=6  mid=8   high=10
arr[mid]=56 > 45 → search left half

Iteration 3:
                [38, 45]
                low=6, mid=7, high=7
arr[mid]=45 == target → FOUND at index 7!
```

### 💡 Key Points
- ✅ **Very efficient** - O(log n) is extremely fast
- ✅ Works on sorted data only
- ⚠️ **Integer overflow issue**: Use `mid = low + (high - low) / 2` instead of `mid = (low + high) / 2`
- 📊 Reduces search space by half each time

### 🎓 Exam Important
**Recurrence Relation**: T(n) = T(n/2) + O(1)  
**Solution**: T(n) = O(log n)

**Maximum comparisons**: ⌈log₂(n+1)⌉

**Example**: For n=1000 elements:
- Linear Search: Up to 1000 comparisons
- Binary Search: Maximum 10 comparisons (log₂1000 ≈ 10)

### ⚡ Variations
1. **Find first occurrence** of element in array with duplicates
2. **Find last occurrence** of element
3. **Count occurrences** = last_index - first_index + 1
4. **Search in rotated sorted array**
5. **Find square root** using binary search

---

## 2. Peak Element (1D)
**File**: `peakelement.cpp`

### 🎯 Concept
A **peak element** is an element that is **greater than or equal to its neighbors**. For corner elements, consider only one neighbor.

**Definition**:
- For arr[i]: It's a peak if arr[i-1] ≤ arr[i] ≥ arr[i+1]
- For arr[0]: Peak if arr[0] ≥ arr[1]
- For arr[n-1]: Peak if arr[n-2] ≤ arr[n-1]

### 📊 Complexity Analysis
- **Time Complexity**: O(log n) using binary search
- **Space Complexity**: O(1)
- **Key Insight**: Array always has at least one peak

### 🔄 Algorithm Steps
```
1. If array has one element → it's a peak
2. Check first element: if arr[0] ≥ arr[1] → peak at 0
3. Check last element: if arr[n-1] ≥ arr[n-2] → peak at n-1
4. For middle elements, use binary search:
   - Calculate mid
   - If arr[mid-1] ≤ arr[mid] ≥ arr[mid+1] → peak found
   - If arr[mid] < arr[mid+1] → peak exists in right half
   - Else → peak exists in left half
```

### 📝 Example (Dry Run)
**Input**: [5, 10, 20, 15, 7, 3, 2]

```
Initial: [5, 10, 20, 15, 7, 3, 2]

Step 1: mid = 3, arr[3] = 15
        arr[2]=20, arr[3]=15, arr[4]=7
        arr[3] is NOT peak (20 > 15)
        arr[mid] < arr[mid-1] → go left

Step 2: Search [5, 10, 20]
        mid = 1, arr[1] = 10
        arr[0]=5, arr[1]=10, arr[2]=20
        arr[1] is NOT peak (20 > 10)
        arr[mid] < arr[mid+1] → go right

Step 3: Search [20]
        mid = 2, arr[2] = 20
        arr[1]=10, arr[2]=20, arr[3]=15
        10 < 20 > 15 → PEAK FOUND at index 2!
```

**Another Example**: [1, 3, 20, 4, 1, 0]

```
Multiple peaks possible: 20 is one peak
Binary search will find ONE peak (not necessarily the largest)
```

### 💡 Key Points
- ✅ **Multiple peaks possible** - algorithm finds any one
- ✅ **Always at least one peak exists** in any array
- ✅ Efficient O(log n) solution using binary search
- 📊 Linear scan is O(n) - binary search is optimization

### 🎓 Exam Questions
**Q**: What if all elements are equal?  
**A**: All elements are peaks (return any index)

**Q**: Can we find the maximum element?  
**A**: Not guaranteed - peak finding ≠ maximum finding

**Q**: Ascending array [1,2,3,4,5]?  
**A**: Last element (5) is the peak

**Q**: Descending array [5,4,3,2,1]?  
**A**: First element (5) is the peak

---

## 3. Peak Element (2D)
**File**: `peakelement2d.cpp`

### 🎯 Concept
Find an element in 2D matrix that is **greater than or equal to all its neighbors** (up, down, left, right).

**Definition**: For matrix[i][j], it's a peak if:
```
matrix[i][j] ≥ matrix[i-1][j]  (up)
matrix[i][j] ≥ matrix[i+1][j]  (down)
matrix[i][j] ≥ matrix[i][j-1]  (left)
matrix[i][j] ≥ matrix[i][j+1]  (right)
```

### 📊 Complexity Analysis
- **Time Complexity**: O(n log m) where n=rows, m=columns
  - Binary search on columns: O(log m)
  - Find max in column: O(n)
- **Space Complexity**: O(1)

### 🔄 Algorithm Steps
```
1. Apply binary search on columns (mid_col)
2. Find maximum element in mid_col → let's call it max_element at row i
3. Check neighbors of matrix[i][mid_col]:
   - If max_element ≥ left neighbor AND ≥ right neighbor → PEAK FOUND
   - If left neighbor > max_element → search left columns
   - If right neighbor > max_element → search right columns
4. Repeat until peak found
```

### 📝 Example (Dry Run)
**Input**:
```
Matrix:
10  20  15
21  30  14
7   16  32
```

```
Step 1: mid_col = 1 (middle column)
        Column 1: [20, 30, 16]
        Max in column 1: 30 at row=1

Step 2: Check neighbors of matrix[1][1]=30
        Left:  matrix[1][0] = 21
        Right: matrix[1][2] = 14
        Up:    matrix[0][1] = 20
        Down:  matrix[2][1] = 16
        
        30 > 21, 30 > 14, 30 > 20, 30 > 16
        → PEAK FOUND at (1, 1)!
```

**Another Example**:
```
Matrix:
10  8   10  10
14  13  12  11
15  9   11  21
16  17  19  20
```

```
Step 1: mid_col = 1
        Column: [8, 13, 9, 17]
        Max: 17 at row=3

Step 2: Check matrix[3][1] = 17
        Left:  matrix[3][0] = 16
        Right: matrix[3][2] = 19
        17 < 19 → search right columns

Step 3: mid_col = 3 (rightmost)
        Column: [10, 11, 21, 20]
        Max: 21 at row=2

Step 4: Check matrix[2][3] = 21
        Left:  matrix[2][2] = 11
        Up:    matrix[1][3] = 11
        Down:  matrix[3][3] = 20
        21 > 11, 21 > 11, 21 > 20
        → PEAK FOUND at (2, 3)!
```

### 💡 Key Points
- ✅ Efficient divide-and-conquer approach
- ✅ Binary search on one dimension, linear search on other
- 📊 Better than O(nm) brute force approach
- ⚠️ Finds ONE peak, not necessarily the global maximum

### 🎓 Exam Important
**Q**: Can we do O(log n * log m)?  
**A**: Theoretically possible but complex - not usually expected in exams

**Q**: What about boundary elements?  
**A**: Consider out-of-bounds neighbors as -infinity

---

## 📊 Comparison Table

| Algorithm | Time Complexity | Space | Prerequisite | Application |
|-----------|----------------|-------|--------------|-------------|
| **Binary Search** | O(log n) | O(1) iterative, O(log n) recursive | Sorted array | Search in sorted data |
| **Peak 1D** | O(log n) | O(1) | None | Find local maximum in 1D |
| **Peak 2D** | O(n log m) | O(1) | None | Find local maximum in 2D |
| **Linear Search** | O(n) | O(1) | None | Search in unsorted data |

---

## 🎯 When to Use Which?

### Binary Search
- ✅ Data is sorted
- ✅ Need fast search (O(log n))
- ✅ Static data or infrequent updates
- ❌ Don't use if data is unsorted (sort first = O(n log n))

### Peak Finding
- ✅ Find local maximum quickly
- ✅ Don't need global maximum
- ✅ Optimization problems
- ✅ Signal processing applications

---

## 💭 Common Interview Questions

**Q1**: Why use `mid = low + (high-low)/2` instead of `mid = (low+high)/2`?  
**A**: To avoid integer overflow when low and high are large numbers.

**Q2**: Binary search on unsorted array?  
**A**: Won't work correctly! Must sort first.

**Q3**: Can binary search find all occurrences?  
**A**: Need to modify: find first occurrence, find last occurrence, count = last - first + 1.

**Q4**: Time complexity to find peak using linear scan?  
**A**: O(n) for 1D, O(nm) for 2D - binary search is optimization.

**Q5**: Can array have no peaks?  
**A**: No! Every array has at least one peak (corner elements are candidates).

**Q6**: Binary search in rotated sorted array?  
**A**: Modified binary search - check which half is sorted, then decide which half to search.

---

## 🧮 Mathematical Analysis

### Binary Search - Number of Comparisons
For array of size n:
- **Maximum comparisons** = ⌈log₂(n+1)⌉
- **Average comparisons** ≈ log₂(n) - 1

**Examples**:
- n = 16 → max 5 comparisons
- n = 1024 → max 11 comparisons
- n = 1,000,000 → max 20 comparisons

### Search Space Reduction
```
Initial: n elements
After 1 comparison: n/2 elements
After 2 comparisons: n/4 elements
After k comparisons: n/(2^k) elements

When n/(2^k) = 1 → k = log₂(n)
```

---

## ⚙️ Compilation & Execution

```bash
# Compile
g++ -std=c++17 -O2 -o binsearch.exe binarysearch.cpp
g++ -std=c++17 -O2 -o peak1d.exe peakelement.cpp
g++ -std=c++17 -O2 -o peak2d.exe peakelement2d.cpp

# Run
.\binsearch.exe
.\peak1d.exe
.\peak2d.exe
```

---

## 🎓 Exam Tips

1. **Binary Search Template**: Memorize the iterative version (easier to write in exam)
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

2. **Remember**: Binary search needs SORTED data
3. **Peak finding**: Always exists, binary search finds one (not necessarily max)
4. **Time complexity**: Master the recurrence relation derivations

---

## 📚 Practice Problems

1. Find first and last occurrence of element in sorted array
2. Count number of occurrences in sorted array
3. Search in rotated sorted array
4. Find minimum in rotated sorted array
5. Search in 2D sorted matrix
6. Find square root using binary search
7. Aggressive cows problem (binary search on answer)
8. Book allocation problem
