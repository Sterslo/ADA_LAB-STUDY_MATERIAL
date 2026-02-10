# 📖 Advanced Algorithms - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 1. Strassen's Matrix Multiplication
**File**: `strassen.cpp`

### 🎯 Concept
Faster matrix multiplication using **7 recursive multiplications** instead of 8.

### 📊 Complexity
- **Standard**: O(n³) - 8 multiplications
- **Strassen**: O(n^2.807) - 7 multiplications
- **Trade-off**: More additions but fewer multiplications

### 🔄 Standard Matrix Multiplication
For C = A × B (2×2 matrices):
```
C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0]
C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1]
C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0]
C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1]

Total: 8 multiplications, 4 additions
```

### ✨ Strassen's Method
```
Divide matrices into 4 submatrices:
A = [A11 A12]    B = [B11 B12]
    [A21 A22]        [B21 B22]

Compute 7 products:
P1 = A11 × (B12 - B22)
P2 = (A11 + A12) × B22
P3 = (A21 + A22) × B11
P4 = A22 × (B21 - B11)
P5 = (A11 + A22) × (B11 + B22)
P6 = (A12 - A22) × (B21 + B22)
P7 = (A11 - A21) × (B11 + B12)

Result:
C11 = P5 + P4 - P2 + P6
C12 = P1 + P2
C21 = P3 + P4
C22 = P5 + P1 - P3 - P7

Total: 7 multiplications, 18 additions/subtractions
```

### 📝 Example (2×2)
```
A = [1 2]    B = [5 6]
    [3 4]        [7 8]

P1 = 1 × (6-8) = 1 × (-2) = -2
P2 = (1+2) × 8 = 3 × 8 = 24
P3 = (3+4) × 5 = 7 × 5 = 35
P4 = 4 × (7-5) = 4 × 2 = 8
P5 = (1+4) × (5+8) = 5 × 13 = 65
P6 = (2-4) × (7+8) = (-2) × 15 = -30
P7 = (1-3) × (5+6) = (-2) × 11 = -22

C11 = 65+8-24+(-30) = 19
C12 = -2+24 = 22
C21 = 35+8 = 43
C22 = 65+(-2)-35-(-22) = 50

C = [19 22]
    [43 50] ✓

Verify standard:
1×5+2×7=19 ✓, 1×6+2×8=22 ✓
3×5+4×7=43 ✓, 3×6+4×8=50 ✓
```

### 💡 Key Points
- ✅ Asymptotically faster: O(n^2.807) vs O(n³)
- ✅ Significant for large matrices
- ❌ More complex, numerical stability issues
- 🎯 Practical for n > 100-1000

### 🎓 Why 7 Multiplications?
**Recurrence**: T(n) = 7T(n/2) + O(n²)

Using Master Theorem:
- a=7, b=2, f(n)=O(n²)
- log_b(a) = log_2(7) ≈ 2.807
- Since 2 < 2.807: T(n) = O(n^2.807)

---

## 2. Magic Square
**File**: `magicsquare.cpp`

### 🎯 Concept
Generate n×n square where all rows, columns, and diagonals sum to same value.

**Magic Constant**: Sum = n(n²+1)/2

### 📊 Complexity
- **Time**: O(n²)
- **Space**: O(n²)
- **Method**: Siamese method (for odd n)

### 🔄 Siamese Method (Odd n)
```
1. Start at middle of top row
2. Place 1
3. For numbers 2 to n²:
   a. Move one up and one right
   b. If out of bounds:
      - Wrap around (row: n-1, col: (col+1)%n)
   c. If cell occupied:
      - Move one down from previous position
   d. Place number
```

### 📝 Example (n=3)
```
Start: Middle of top row (row=0, col=1)

Step 1: Place 1 at (0,1)
. 1 .
. . .
. . .

Step 2: Up-right from (0,1) → (-1,2) → wrap → (2,2)
        Place 2
. 1 .
. . .
. . 2

Step 3: Up-right from (2,2) → (1,3) → wrap col → (1,0)
        Place 3
. 1 .
3 . .
. . 2

Step 4: Up-right from (1,0) → (0,-1) → wrap → (0,2)
        Occupied by 2!
        Go down from (1,0) → (2,0)
        Place 4
. 1 .
3 . .
4 . 2

Continue...

Final:
2 7 6
9 5 1
4 3 8

Magic sum: 15 (3×(9+1)/2 = 15)
All rows: 2+7+6=15, 9+5+1=15, 4+3+8=15 ✓
All cols: 2+9+4=15, 7+5+3=15, 6+1+8=15 ✓
Diagonals: 2+5+8=15, 6+5+4=15 ✓
```

### 💡 Properties
- ✅ Works for odd n only (Siamese method)
- ✅ Unique pattern
- 🎯 Even n requires different methods
- 📊 Ancient puzzle with mathematical beauty

### 🎓 For n=5
```
Magic Constant = 5(25+1)/2 = 65

17 24  1  8 15
23  5  7 14 16
 4  6 13 20 22
10 12 19 21  3
11 18 25  2  9

All rows, cols, diagonals = 65
```

---

## 📊 Comparison

| Algorithm | Type | Complexity | Application |
|-----------|------|------------|-------------|
| **Strassen** | Divide & Conquer | O(n^2.807) | Large matrix multiplication |
| **Magic Square** | Pattern-based | O(n²) | Puzzle generation |

---

## 💭 Interview Questions

**Q1**: Why is Strassen faster?  
**A**: 7 multiplications instead of 8 → O(n^2.807) vs O(n³)

**Q2**: Is Strassen always better?  
**A**: No, only for large matrices (n>1000). Overhead for small n.

**Q3**: How to generate even-order magic squares?  
**A**: Different methods: Doubly Even, Singly Even (more complex)

---

## ⚙️ Compilation

```bash
g++ -std=c++17 -O2 -o strassen.exe strassen.cpp
g++ -std=c++17 -O2 -o magic.exe magicsquare.cpp

.\strassen.exe
.\magic.exe
```

---

## 📚 Related Topics
- **Coppersmith-Winograd**: O(n^2.376) - theoretical best
- **Karatsuba**: Fast integer multiplication
- **FFT**: Fast polynomial multiplication
