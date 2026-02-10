/**
 * Strassen's Matrix Multiplication Algorithm
 * Time Complexity: O(n^2.807) better than standard O(n^3)
 * Space Complexity: O(n^2)
 * Works for matrices with size as power of 2
 */

#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

/**
 * Add two matrices
 * @param A First matrix
 * @param B Second matrix
 * @param size Matrix size
 * @return Resultant matrix A + B
 */
Matrix addMatrices(const Matrix& A, const Matrix& B, int size) {
    Matrix result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

/**
 * Subtract two matrices
 * @param A First matrix
 * @param B Second matrix
 * @param size Matrix size
 * @return Resultant matrix A - B
 */
Matrix subtractMatrices(const Matrix& A, const Matrix& B, int size) {
    Matrix result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

/**
 * Strassen's algorithm for matrix multiplication
 * @param A First matrix
 * @param B Second matrix
 * @param size Matrix size (must be power of 2)
 * @return Resultant matrix A * B
 */
Matrix strassenMultiply(Matrix A, Matrix B, int size) {
    // Base case: 1x1 matrix
    if (size == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = size / 2;
    
    // Divide matrices into quadrants
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute Strassen's 7 multiplications
    Matrix P1 = strassenMultiply(A11, subtractMatrices(B12, B22, newSize), newSize);
    Matrix P2 = strassenMultiply(addMatrices(A11, A12, newSize), B22, newSize);
    Matrix P3 = strassenMultiply(addMatrices(A21, A22, newSize), B11, newSize);
    Matrix P4 = strassenMultiply(A22, subtractMatrices(B21, B11, newSize), newSize);
    Matrix P5 = strassenMultiply(addMatrices(A11, A22, newSize), addMatrices(B11, B22, newSize), newSize);
    Matrix P6 = strassenMultiply(subtractMatrices(A12, A22, newSize), addMatrices(B21, B22, newSize), newSize);
    Matrix P7 = strassenMultiply(subtractMatrices(A11, A21, newSize), addMatrices(B11, B12, newSize), newSize);

    // Compute resultant quadrants
    Matrix C11 = addMatrices(subtractMatrices(addMatrices(P5, P4, newSize), P2, newSize), P6, newSize);
    Matrix C12 = addMatrices(P1, P2, newSize);
    Matrix C21 = addMatrices(P3, P4, newSize);
    Matrix C22 = subtractMatrices(subtractMatrices(addMatrices(P5, P1, newSize), P3, newSize), P7, newSize);

    // Combine quadrants into result matrix
    Matrix C(size, vector<int>(size, 0));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

/**
 * Print matrix
 * @param M Matrix to print
 */
void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    int size = 4; // Matrix size (must be power of 2)
    
    Matrix A = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };
    
    Matrix B = {
        {17, 18, 19, 20}, 
        {21, 22, 23, 24}, 
        {25, 26, 27, 28}, 
        {29, 30, 31, 32}
    };

    cout << "Strassen's Matrix Multiplication Algorithm\n";
    cout << string(50, '=') << "\n";
    cout << "Matrix A:\n";
    printMatrix(A);
    
    cout << "\nMatrix B:\n";
    printMatrix(B);

    Matrix C = strassenMultiply(A, B, size);

    cout << "\nResultant Matrix (A * B):\n";
    printMatrix(C);

    return 0;
}
