# 📖 Greedy Algorithms - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 🎯 What is Greedy Algorithm?

**Greedy** = Make locally optimal choice at each step → Hope for global optimum

### Key Properties:
1. **Greedy Choice Property**: Local optimum → Global optimum
2. **Optimal Substructure**: Optimal solution contains optimal subsolutions

**When to use?** Problem must have greedy choice property (prove it!)

---

## 1. Fractional Knapsack
**File**: `knapsack.cpp`

### 🎯 Problem
Items can be **broken**. Maximize value in knapsack.

### 📊 Complexity
- **Time**: O(n log n) - sorting
- **Strategy**: Sort by value/weight ratio

### 📝 Example
```
Items: (w=10,v=60), (w=20,v=100), (w=30,v=120)
Capacity = 50

Ratios: 6.0, 5.0, 4.0 (sorted)

Take: Item1(100%) + Item2(100%) + Item3(66.67%)
= 60 + 100 + 80 = 240
```

### 💡 Key Points
- ✅ Greedy **works optimally** here
- ❌ Doesn't work for 0-1 knapsack

---

## 2. Activity Selection
**File**: `activitysel.cpp`

### 🎯 Problem
Maximize **non-overlapping** activities.

### 📊 Complexity
- **Time**: O(n log n)
- **Strategy**: Sort by **finish time**

### 📝 Example
```
Activities (start, finish):
(1,4), (3,5), (0,6), (5,7), (8,9), (5,9)

Sort by finish:
(1,4), (3,5), (0,6), (5,7), (5,9), (8,9)

Select:
1. (1,4) - finish=4
2. (5,7) - start≥4, finish=7
3. (8,9) - start≥7, finish=9

Max=3 activities
```

### 💡 Why Finish Time?
Earliest finish → Maximum room for future activities

---

## 📊 Greedy vs DP

| Aspect | Greedy | DP |
|--------|--------|----|
| **Choice** | One best choice | All choices |
| **Speed** | Fast | Slower |
| **Correctness** | Not always | Always |
| **Example Works** | Fractional Knapsack | 0-1 Knapsack |

---

## ⚙️ Compilation

```bash
g++ -std=c++17 -O2 -o fracknap.exe knapsack.cpp
g++ -std=c++17 -O2 -o activity.exe activitysel.cpp
```
