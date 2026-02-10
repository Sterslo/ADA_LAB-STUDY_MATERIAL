/**
 * Magic Square Generation - Odd Order
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * Creates magic square where all rows, columns, and diagonals sum to same value
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
 * Generate magic square for odd order n
 * @param n Size of magic square (must be odd)
 * @return 2D vector containing magic square
 */
vector<vector<int>> generateMagicSquare(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    
    // Start position: middle of first row
    int row = 0;
    int col = n / 2;
    
    for (int num = 1; num <= n * n; num++) {
        square[row][col] = num;
        
        // Calculate next position: move up and right
        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;
        
        // If position is occupied, move down instead
        if (square[nextRow][nextCol] != 0) {
            nextRow = (row + 1) % n;
            nextCol = col;
        }
        
        row = nextRow;
        col = nextCol;
    }
    
    return square;
}

/**
 * Print magic square
 * @param square Magic square to print
 */
void printMagicSquare(const vector<vector<int>>& square) {
    int n = square.size();
    
    cout << "\nMagic Square:\n";
    cout << string(n * 5, '-') << "\n";
    
    for (const auto& row : square) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << "\n";
    }
    
    // Calculate magic constant
    int magicConstant = n * (n * n + 1) / 2;
    cout << string(n * 5, '-') << "\n";
    cout << "Magic Constant: " << magicConstant << "\n";
}

int main() {
    int n;
    
    cout << "Magic Square Generation (Odd Order)\n";
    cout << string(40, '=') << "\n";
    cout << "Enter size (odd number only): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Error: Magic square can only be generated for odd numbers\n";
        return 1;
    }

    if (n < 1) {
        cout << "Error: Size must be a positive number\n";
        return 1;
    }

    vector<vector<int>> magicSquare = generateMagicSquare(n);
    printMagicSquare(magicSquare);

    return 0;
}
