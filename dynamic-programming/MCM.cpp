/**
 * Matrix Chain Multiplication - Dynamic Programming
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 * Finds optimal parenthesization to minimize scalar multiplications
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Print optimal parenthesization
 * @param split Split matrix
 * @param i Starting index
 * @param j Ending index
 */
void printParenthesization(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << (i + 1);
    } else {
        cout << "(";
        printParenthesization(split, i, split[i][j]);
        printParenthesization(split, split[i][j] + 1, j);
        cout << ")";
    }
}

/**
 * Matrix Chain Multiplication using DP
 * @param dimensions Matrix dimensions (n matrices have n+1 dimensions)
 */
void matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    
    // cost[i][j] = minimum cost to multiply matrices from i to j
    vector<vector<int>> cost(n, vector<int>(n, 0));
    
    // split[i][j] = optimal split point for matrices i to j
    vector<vector<int>> split(n, vector<int>(n, 0));

    // l is chain length
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            // Try all possible split points
            for (int k = i; k < j; k++) {
                int operations = cost[i][k] + cost[k + 1][j] + 
                                dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                
                if (operations < cost[i][j]) {
                    cost[i][j] = operations;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications: " << cost[0][n - 1] << "\n";
    cout << "Optimal parenthesization: ";
    printParenthesization(split, 0, n - 1);
    cout << "\n";
}

int main() {
    // Matrix dimensions: A1(5x10), A2(10x15), A3(15x20), A4(20x25), A5(25x30)
    vector<int> dimensions = {5, 10, 15, 20, 25, 30};

    cout << "Matrix Chain Multiplication (Dynamic Programming)\n";
    cout << string(50, '=') << "\n";
    cout << "Number of matrices: " << (dimensions.size() - 1) << "\n";
    cout << "Matrix dimensions:\n";
    for (size_t i = 0; i < dimensions.size() - 1; i++) {
        cout << "  A" << (i + 1) << ": " << dimensions[i] << " x " << dimensions[i + 1] << "\n";
    }

    matrixChainMultiplication(dimensions);

    return 0;
}
