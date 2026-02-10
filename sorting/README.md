# 📖 Sorting Algorithms - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 📚 Table of Contents
1. [Bubble Sort](#1-bubble-sort)
2. [Selection Sort](#2-selection-sort)
3. [Insertion Sort](#3-insertion-sort)
4. [Merge Sort](#4-merge-sort)
5. [Quick Sort](#5-quick-sort)
6. [Comparison Table](#comparison-table)

---

## 1. Bubble Sort
**File**: `bubblesort.cpp`

### 🎯 Concept
Repeatedly compares adjacent elements and swaps them if they're in wrong order. The largest element "bubbles up" to the end in each pass.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(n) - when array is already sorted
  - Average Case: O(n²)
  - Worst Case: O(n²) - when array is reverse sorted
- **Space Complexity**: O(1) - in-place sorting
- **Stable**: Yes (maintains relative order of equal elements)

### 🔄 Algorithm Steps
```
1. Start from the first element
2. Compare current element with next element
3. If current > next, swap them
4. Move to next pair
5. Repeat until end of array
6. Repeat entire process (n-1) times
```

### 📝 Example (Dry Run)
**Input**: [64, 34, 25, 12, 22, 11, 90]

**Pass 1**: [34, 25, 12, 22, 11, 64, 90] → 90 reaches end  
**Pass 2**: [25, 12, 22, 11, 34, 64, 90] → 64 reaches position  
**Pass 3**: [12, 22, 11, 25, 34, 64, 90] → 34 reaches position  
**Pass 4**: [12, 11, 22, 25, 34, 64, 90] → 25 reaches position  
**Pass 5**: [11, 12, 22, 25, 34, 64, 90] → Sorted!

### 💡 Key Points
- ✅ Simple to understand and implement
- ✅ Works well for small datasets
- ❌ Very inefficient for large datasets
- ❌ Too many comparisons and swaps

### ⚡ Optimization
Add a flag to check if any swap happened in a pass. If no swap, array is sorted → exit early.

---

## 2. Selection Sort
**File**: `selectionsort.cpp`

### 🎯 Concept
Divides array into sorted and unsorted parts. Repeatedly finds minimum element from unsorted part and places it at beginning of unsorted part.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(n²)
  - Average Case: O(n²)
  - Worst Case: O(n²)
- **Space Complexity**: O(1)
- **Stable**: No (can be made stable with modifications)

### 🔄 Algorithm Steps
```
1. Set first position as minimum
2. Scan entire array to find actual minimum
3. Swap minimum with first position
4. Move to next position
5. Repeat for remaining unsorted part
```

### 📝 Example (Dry Run)
**Input**: [64, 25, 12, 22, 11]

```
Step 1: [11, 25, 12, 22, 64] → found min=11, swapped with 64
Step 2: [11, 12, 25, 22, 64] → found min=12, swapped with 25
Step 3: [11, 12, 22, 25, 64] → found min=22, swapped with 25
Step 4: [11, 12, 22, 25, 64] → found min=25, already in place
```

### 💡 Key Points
- ✅ Minimizes number of swaps (maximum n-1 swaps)
- ✅ Works well when write operation is costly
- ❌ Always O(n²) - no best case optimization
- ❌ Not stable by default

---

## 3. Insertion Sort
**File**: `insertionsort.cpp`

### 🎯 Concept
Builds final sorted array one item at a time. Picks element and inserts it at correct position in sorted part (like sorting playing cards).

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(n) - when array is already sorted
  - Average Case: O(n²)
  - Worst Case: O(n²) - when array is reverse sorted
- **Space Complexity**: O(1)
- **Stable**: Yes

### 🔄 Algorithm Steps
```
1. Start from second element (first is already "sorted")
2. Store current element as key
3. Compare key with elements in sorted part (left side)
4. Shift all larger elements one position right
5. Insert key at correct position
6. Repeat for all elements
```

### 📝 Example (Dry Run)
**Input**: [12, 11, 13, 5, 6]

```
Initially: [12 | 11, 13, 5, 6]  (12 is sorted part)
Step 1:    [11, 12 | 13, 5, 6]  (insert 11)
Step 2:    [11, 12, 13 | 5, 6]  (insert 13)
Step 3:    [5, 11, 12, 13 | 6]  (insert 5)
Step 4:    [5, 6, 11, 12, 13]   (insert 6)
```

### 💡 Key Points
- ✅ **Best for nearly sorted data** - O(n) performance
- ✅ Adaptive - efficient for small datasets
- ✅ Stable and in-place
- ✅ Online algorithm - can sort data as it arrives
- ❌ Inefficient for large datasets

### 🎓 Exam Tip
Remember: "Like sorting playing cards in your hand!"

---

## 4. Merge Sort
**File**: `mergeSort.cpp`

### 🎯 Concept
**Divide and Conquer** algorithm. Divides array into halves recursively until single elements, then merges them back in sorted order.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- **Space Complexity**: O(n) - requires extra space for merging
- **Stable**: Yes

### 🔄 Algorithm Steps
```
DIVIDE PHASE:
1. Find middle point: mid = (left + right) / 2
2. Recursively divide left half: mergeSort(arr, left, mid)
3. Recursively divide right half: mergeSort(arr, mid+1, right)

CONQUER PHASE:
4. Merge both sorted halves
```

### 📝 Example (Dry Run)
**Input**: [38, 27, 43, 3, 9, 82, 10]

```
                    [38, 27, 43, 3, 9, 82, 10]
                   /                           \
         [38, 27, 43, 3]                    [9, 82, 10]
         /            \                      /         \
    [38, 27]        [43, 3]            [9, 82]        [10]
    /     \         /     \            /     \
  [38]   [27]    [43]   [3]         [9]    [82]

MERGING:
  [27, 38]        [3, 43]            [9, 82]
         \            /                      \
       [3, 27, 38, 43]                  [9, 10, 82]
                    \                      /
                [3, 9, 10, 27, 38, 43, 82]
```

### 💡 Key Points
- ✅ **Guaranteed O(n log n)** - best worst-case time complexity
- ✅ Stable sorting
- ✅ Excellent for **linked lists** (no random access needed)
- ✅ Used in **external sorting** (large files)
- ❌ Requires O(n) extra space
- ❌ Not in-place

### 🎓 Exam Important
**Recurrence Relation**: T(n) = 2T(n/2) + O(n)  
**Solution**: T(n) = O(n log n) using Master Theorem

---

## 5. Quick Sort
**Files**: `quicksort.cpp` (Recursive), `iterativequicksort.cpp` (Iterative)

### 🎯 Concept
**Divide and Conquer** algorithm. Picks a pivot element and partitions array so that elements smaller than pivot are on left, greater on right. Recursively sorts both parts.

### 📊 Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(n log n) - when pivot divides array evenly
  - Average Case: O(n log n)
  - Worst Case: O(n²) - when array is already sorted and pivot is first/last element
- **Space Complexity**: 
  - Recursive: O(log n) - recursion stack
  - Iterative: O(log n) - explicit stack
- **Stable**: No

### 🔄 Algorithm Steps
```
PARTITION:
1. Choose pivot (usually last element)
2. Place pivot at correct position
3. All smaller elements to left of pivot
4. All greater elements to right of pivot

RECURSION:
5. Recursively sort left subarray
6. Recursively sort right subarray
```

### 📝 Example (Dry Run) - Lomuto Partition
**Input**: [10, 80, 30, 90, 40, 50, 70] | Pivot = 70

```
Initial:  [10, 80, 30, 90, 40, 50, 70]  pivot=70, i=-1

j=0: arr[0]=10 < 70 → i=0, swap(10,10) → [10, 80, 30, 90, 40, 50, 70]
j=1: arr[1]=80 > 70 → no swap           → [10, 80, 30, 90, 40, 50, 70]
j=2: arr[2]=30 < 70 → i=1, swap(80,30) → [10, 30, 80, 90, 40, 50, 70]
j=3: arr[3]=90 > 70 → no swap           → [10, 30, 80, 90, 40, 50, 70]
j=4: arr[4]=40 < 70 → i=2, swap(80,40) → [10, 30, 40, 90, 80, 50, 70]
j=5: arr[5]=50 < 70 → i=3, swap(90,50) → [10, 30, 40, 50, 80, 90, 70]

Final swap: swap(80, 70)                → [10, 30, 40, 50, 70, 90, 80]
                                            Pivot at correct position!

Now recursively sort: [10, 30, 40, 50] and [90, 80]
```

### 💡 Key Points
- ✅ **Fastest in practice** - excellent cache performance
- ✅ In-place sorting (O(log n) stack space only)
- ✅ Preferred for **arrays** (Merge sort for linked lists)
- ❌ Unstable
- ❌ O(n²) worst case (can be avoided with random pivot)

### ⚡ Pivot Selection Strategies
1. **First element** - Simple but worst case for sorted arrays
2. **Last element** - Most common (used in our code)
3. **Middle element** - Better for partially sorted
4. **Random element** - Avoids worst case
5. **Median-of-three** - Best in practice

### 🎓 Exam Important
**Recurrence Relation**:
- Best/Average: T(n) = 2T(n/2) + O(n) → O(n log n)
- Worst: T(n) = T(n-1) + O(n) → O(n²)

---

## 📊 Comparison Table

| Algorithm | Best | Average | Worst | Space | Stable | In-Place | Best Use Case |
|-----------|------|---------|-------|-------|--------|----------|---------------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes | Small/Nearly sorted |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ No | ✅ Yes | Minimize swaps |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes | Nearly sorted data |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ Yes | ❌ No | Linked lists, large data |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ No | ✅ Yes | General purpose, arrays |

---

## 🎯 Quick Decision Guide

**Choose Bubble Sort when:**
- 🎓 Learning/teaching sorting concepts
- 📊 Array is nearly sorted
- 🔢 Very small dataset (n < 10)

**Choose Selection Sort when:**
- 💾 Memory writes are expensive
- 🔢 Small dataset with minimum swaps needed

**Choose Insertion Sort when:**
- ⚡ Data is nearly sorted or arrives online
- 🔢 Small dataset (n < 50)
- 📦 Need stable sort with O(1) space

**Choose Merge Sort when:**
- 🔗 Sorting linked lists
- ✅ Need guaranteed O(n log n) performance
- 💼 Stable sort is required
- 📂 External sorting (large files)

**Choose Quick Sort when:**
- 🏆 General purpose sorting
- 🎯 Average case performance is priority
- 💨 Cache-friendly sorting needed
- 📦 Memory is limited (in-place sorting)

---

## 💭 Common Interview Questions

**Q1**: Why is Quick Sort faster than Merge Sort in practice despite same O(n log n) complexity?  
**A**: Quick Sort has better cache locality (in-place) and fewer data movements.

**Q2**: When does Quick Sort become O(n²)?  
**A**: When pivot selection is poor (sorted array with first/last pivot) or when all elements are equal.

**Q3**: How to make Quick Sort stable?  
**A**: Use extra space to maintain order of equal elements (defeats purpose of Quick Sort).

**Q4**: Why is Merge Sort preferred for linked lists?  
**A**: No random access needed, and merging linked lists doesn't require extra space.

**Q5**: Which sorting algorithm is best for nearly sorted data?  
**A**: Insertion Sort - runs in O(n) time for nearly sorted data.

---

## ⚙️ Compilation & Execution

```bash
# Compile any sorting program
g++ -std=c++17 -O2 -o bubble.exe bubblesort.cpp
g++ -std=c++17 -O2 -o quick.exe quicksort.cpp

# Run
.\bubble.exe
.\quick.exe
```

---

## 📚 Further Reading
- Master Theorem for solving recurrences
- Randomized Quick Sort to avoid O(n²)
- Hybrid sorting (IntroSort = Quick + Heap + Insertion)
- Counting Sort, Radix Sort for special cases

---

**Remember**: No single sorting algorithm is best for all scenarios. Choose based on:
- Dataset size
- Data characteristics (sorted, random, duplicates)
- Memory constraints
- Stability requirements
- Time constraints
