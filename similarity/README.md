# 📖 Similarity Metrics - Study Notes

**Student Details:**
- Name: Prexit Joshi
- Roll Number: 233118
- Class: CSE 4th Semester, Section 2

---

## 🎯 What are Similarity Metrics?

**Similarity Metrics** measure how alike two objects are.

**Applications**:
- 📝 Document comparison
- 🔍 Search engines
- 📦 Recommendation systems
- 🧠 Machine Learning

---

## 1. Jaccard Similarity
**File**: `jaccard.cpp`

### 🎯 Concept
Measures similarity between **sets** using intersection/union ratio.

**Formula**: 
```
J(A, B) = |A ∩ B| / |A ∪ B|
       = Intersection / Union
```

**Range**: 0 to 1
- 0 = Completely different
- 1 = Identical

### 📊 Complexity
- **Time**: O(n + m) where n=|A|, m=|B|
- **Space**: O(n + m)

### 📝 Example
```
Set A = {1, 2, 3, 4}
Set B = {3, 4, 5, 6}

Intersection (A ∩ B) = {3, 4} → size = 2
Union (A ∪ B) = {1, 2, 3, 4, 5, 6} → size = 6

Jaccard = 2/6 = 0.333
```

### 📝 Text Example
```
Document A: "the cat sat on the mat"
Document B: "the dog sat on the log"

Words A = {the, cat, sat, on, mat}
Words B = {the, dog, sat, on, log}

Intersection = {the, sat, on} → 3
Union = {the, cat, sat, on, mat, dog, log} → 7

Jaccard = 3/7 ≈ 0.429 (42.9% similar)
```

### 💡 Key Points
- ✅ Simple and intuitive
- ✅ Works with **categorical/binary** data
- ✅ Symmetric: J(A,B) = J(B,A)
- ❌ Doesn't consider frequency
- ❌ Ignores order

### 🎓 Properties
```
J(A, A) = 1 (identical)
J(A, ∅) = 0 (no overlap with empty set)
J(∅, ∅) = 0 (undefined, or defined as 0)
```

---

## 2. Cosine Similarity
**File**: `cosinsimilarity.cpp`

### 🎯 Concept
Measures **angle** between two vectors in multi-dimensional space.

**Formula**:
```
cos(θ) = (A · B) / (||A|| × ||B||)

where:
  A · B = dot product = Σ(A[i] × B[i])
  ||A|| = magnitude = √(Σ(A[i]²))
  ||B|| = magnitude = √(Σ(B[i]²))
```

**Range**: -1 to 1 (0 to 1 for positive vectors)
- 1 = Same direction (identical)
- 0 = Orthogonal (independent)
- -1 = Opposite direction

### 📊 Complexity
- **Time**: O(n) where n = vector dimension
- **Space**: O(1)

### 📝 Example 1 (Simple Vectors)
```
A = [1, 2, 3]
B = [2, 4, 6]

Dot product:
A · B = (1×2) + (2×4) + (3×6)
      = 2 + 8 + 18 = 28

Magnitudes:
||A|| = √(1² + 2² + 3²) = √(1+4+9) = √14 ≈ 3.742
||B|| = √(2² + 4² + 6²) = √(4+16+36) = √56 ≈ 7.483

Cosine:
cos(θ) = 28 / (3.742 × 7.483)
         = 28 / 28
         = 1.0

Result: Perfect similarity (B is 2×A)
```

### 📝 Example 2 (Documents)
```
Document A: "the cat sat"
Document B: "the dog sat"

Vocabulary: {the, cat, sat, dog}

Vector A = [1, 1, 1, 0]  (the=1, cat=1, sat=1, dog=0)
Vector B = [1, 0, 1, 1]  (the=1, cat=0, sat=1, dog=1)

Dot product:
A · B = (1×1) + (1×0) + (1×1) + (0×1)
      = 1 + 0 + 1 + 0 = 2

Magnitudes:
||A|| = √(1+1+1+0) = √3 ≈ 1.732
||B|| = √(1+0+1+1) = √3 ≈ 1.732

Cosine:
cos(θ) = 2 / (1.732 × 1.732)
         = 2 / 3
         ≈ 0.667

Result: 66.7% similar
```

### 💡 Key Points
- ✅ **Magnitude-independent** (normalizes vectors)
- ✅ Works with **numerical** data
- ✅ Considers **frequency** (TF-IDF in NLP)
- ✅ Widely used in **text mining**
- ❌ Doesn't capture order

### 🎓 Geometric Interpretation
```
Angle θ between vectors:
θ = arccos(cosine_similarity)

cos(θ) = 1 → θ = 0° (parallel)
cos(θ) = 0 → θ = 90° (perpendicular)
cos(θ) = -1 → θ = 180° (opposite)
```

---

## 📊 Comparison

| Metric | Type | Range | Considers Frequency? | Use Case |
|--------|------|-------|---------------------|----------|
| **Jaccard** | Set-based | [0, 1] | ❌ No | Categorical data, presence/absence |
| **Cosine** | Vector-based | [-1, 1] | ✅ Yes | Numerical data, text (TF-IDF) |

---

## 🎯 When to Use Which?

### Jaccard Similarity:
- ✅ Binary/categorical data
- ✅ Presence/absence matters
- ✅ Small sets
- 📝 Example: "Does user like action movies?"

### Cosine Similarity:
- ✅ Numerical vectors
- ✅ Frequency/magnitude matters
- ✅ High-dimensional data
- 📝 Example: "How similar are these documents?"

---

## 📝 Real-World Example

**Problem**: Find similar movies

### Approach 1: Jaccard (Genres)
```
Movie A: {Action, Sci-Fi, Thriller}
Movie B: {Action, Drama}
Movie C: {Action, Sci-Fi}

J(A,B) = 1/4 = 0.25
J(A,C) = 2/3 = 0.67 → More similar!
```

### Approach 2: Cosine (Ratings)
```
User ratings (User1, User2, User3):
Movie A: [5, 4, 3]
Movie B: [4, 3, 2]
Movie C: [5, 5, 3]

cos(A,B) = 0.99 (very similar)
cos(A,C) = 0.98 (very similar)
```

---

## 💭 Interview Questions

**Q1**: Difference between Jaccard and Cosine?  
**A**: Jaccard for sets (presence), Cosine for vectors (magnitude).

**Q2**: Why normalize in cosine similarity?  
**A**: To measure angle, not magnitude. "good good good" vs "good" have different lengths but similar meaning.

**Q3**: Can cosine be negative?  
**A**: Yes, for any vectors. But for text (positive vectors), range is [0,1].

**Q4**: Which is faster?  
**A**: Both O(n), but Jaccard uses set operations, Cosine uses arithmetic.

---

## ⚙️ Compilation

```bash
g++ -std=c++17 -O2 -o jaccard.exe jaccard.cpp
g++ -std=c++17 -O2 -o cosine.exe cosinsimilarity.cpp

.\jaccard.exe
.\cosine.exe
```

---

## 📚 Other Similarity Metrics

- **Euclidean Distance**: Straight-line distance
- **Manhattan Distance**: Grid-based distance
- **Hamming Distance**: Bit differences
- **Pearson Correlation**: Linear relationship
- **Dice Coefficient**: Similar to Jaccard
- **Levenshtein Distance**: String edit distance
