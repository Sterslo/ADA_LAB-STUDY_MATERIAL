/**
 * 2D Peak Element Finding - Binary Search on Columns
 * Time Complexity: O(n log m) where n=rows, m=columns
 * Space Complexity: O(1)
 * Peak element is greater than all four neighbors
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Find maximum element in a column
 * @param matrix 2D matrix
 * @param numRows Number of rows
 * @param col Column index
 * @return Row index of maximum element
 */
int findMaxInColumn(const vector<vector<int>>& matrix, int numRows, int col) {
    int maxVal = -1;
    int maxRow = -1;
    
    for (int i = 0; i < numRows; i++) {
        if (matrix[i][col] > maxVal) {
            maxVal = matrix[i][col];
            maxRow = i;
        }
    }
    
    return maxRow;
}

/**
 * Find a peak element in 2D matrix
 * @param matrix 2D matrix
 * @return Vector {row, col} of peak element
 */
vector<int> findPeak2D(const vector<vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int low = 0;
    int high = numCols - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int maxRow = findMaxInColumn(matrix, numRows, mid);
        
        // Check if this element is a peak
        bool isLeftSmaller = (mid == 0) || (matrix[maxRow][mid - 1] < matrix[maxRow][mid]);
        bool isRightSmaller = (mid == numCols - 1) || (matrix[maxRow][mid] > matrix[maxRow][mid + 1]);
        
        if (isLeftSmaller && isRightSmaller) {
            return {maxRow, mid};
        }
        
        // Move towards larger neighbor
        else if (mid > 0 && matrix[maxRow][mid - 1] > matrix[maxRow][mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return {-1, -1};
}

int main() {
    vector<vector<int>> matrix = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    cout << "2D Peak Element Finding Algorithm\n";
    cout << string(40, '=') << "\n";
    cout << "Matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    vector<int> result = findPeak2D(matrix);
    
    if (result[0] != -1) {
        cout << "Peak element: " << matrix[result[0]][result[1]] << "\n";
        cout << "Position: (" << result[0] << ", " << result[1] << ")\n";
    } else {
        cout << "No peak element found\n";
    }

    return 0;
}
