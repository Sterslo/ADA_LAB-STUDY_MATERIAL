/**
 * N-Queens Problem - Backtracking Algorithm
 * Time Complexity: O(N!)
 * Space Complexity: O(N) for recursion and array
 * Place N queens on NxN chessboard such that no two queens attack each other
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Check if queen can be placed at position (row, col)
 * @param board Current board configuration
 * @param row Row to check
 * @param col Column to place queen
 * @return true if safe, false otherwise
 */
bool isSafe(const vector<int>& board, int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = board[prevRow];
        
        // Check if queens are in same column or diagonal
        if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) {
            return false;
        }
    }
    return true;
}

/**
 * Solve N-Queens problem recursively
 * @param board Board configuration (board[i] = column of queen in row i)
 * @param row Current row to place queen
 * @param n Board size
 * @param solutionCount Counter for solutions
 */
void solveNQueens(vector<int>& board, int row, int n, int& solutionCount) {
    if (row == n) {
        // Found a solution
        solutionCount++;
        cout << "Solution " << solutionCount << ": ";
        for (int i = 0; i < n; i++) {
            cout << board[i] + 1 << " "; // 1-indexed output
        }
        cout << "\n";
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutionCount);
        }
    }
}

int main() {
    int n;
    
    cout << "N-Queens Problem (Backtracking)\n";
    cout << string(40, '=') << "\n";
    cout << "Enter number of queens: ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid input. N must be >= 1\n";
        return 1;
    }

    vector<int> board(n, -1);
    int solutionCount = 0;

    cout << "\nFinding all solutions...\n";
    cout << string(40, '-') << "\n";

    solveNQueens(board, 0, n, solutionCount);

    cout << string(40, '-') << "\n";
    cout << "Total solutions found: " << solutionCount << "\n";

    return 0;
}
