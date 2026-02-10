# 📖 Backtracking - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 🎯 Backtracking = Try → If fails → Undo → Try next

### Template:
```cpp
void backtrack(state) {
    if (is_solution(state)) {
        save_solution();
        return;
    }
    for (each choice) {
        if (is_valid(choice)) {
            make_choice();      // Try
            backtrack();        // Recurse
            undo_choice();      // Backtrack
        }
    }
}
```

---

## N-Queens Problem
**File**: `N-queens.cpp`

### 🎯 Problem
Place N queens on N×N board so none attack each other.

### 📊 Complexity
- **Time**: O(N!) with pruning
- **Solutions**: N=4→2, N=8→92

### 🛡️ Safety Check
For position (row, col):
1. No queen in same column
2. No queen in left diagonal (↖)
3. No queen in right diagonal (↗)

### 📝 N=4 Example
```
Solution 1:        Solution 2:
. Q . .            . . Q .
Q . . .            . . . Q
. . . Q            . Q . .
. . Q .            Q . . .
```

### 💡 Algorithm
1. Place one queen per row (avoids row conflicts)
2. Try each column in current row
3. If safe → place queen → solve next row
4. If all rows done → solution found!
5. Backtrack if no valid column

---

## 🎓 Exam Tips

**Memorize**:
- Backtracking pattern
- N-Queens safety check
- Time complexity: O(N!)

---

## ⚙️ Compilation

```bash
g++ -std=c++17 -O2 -o nqueens.exe N-queens.cpp
.\nqueens.exe
```

---

## 📚 Other Backtracking Problems
- Sudoku Solver
- Graph Coloring
- Hamiltonian Path
- Subset Sum
