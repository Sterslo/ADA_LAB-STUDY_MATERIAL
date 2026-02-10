/**
 * Max-Min Finding - Divide and Conquer Approach
 * Time Complexity: O(n)
 * Space Complexity: O(log n) for recursion stack
 * Finds maximum and minimum elements efficiently
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/**
 * Find max and min using divide and conquer
 * @param arr Array to search
 * @param left Left boundary
 * @param right Right boundary
 * @return Pair {maximum, minimum}
 */
pair<int, int> findMaxMin(const vector<int>& arr, int left, int right) {
    // Base case: single element
    if (left == right) {
        return {arr[left], arr[left]};
    }

    // Base case: two elements
    if (right == left + 1) {
        return {max(arr[left], arr[right]), min(arr[left], arr[right])};
    }

    int mid = left + (right - left) / 2;

    // Divide: find max-min in left and right halves
    pair<int, int> leftResult = findMaxMin(arr, left, mid);
    pair<int, int> rightResult = findMaxMin(arr, mid + 1, right);

    // Conquer: combine results
    int maximum = max(leftResult.first, rightResult.first);
    int minimum = min(leftResult.second, rightResult.second);

    return {maximum, minimum};
}

int main() {
    vector<int> arr = {12, 7, 19, 5, 18, 3, 8, 11, 22, 10};

    cout << "Max-Min Finding Algorithm (Divide and Conquer)\n";
    cout << string(50, '=') << "\n";
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n\n";

    pair<int, int> result = findMaxMin(arr, 0, arr.size() - 1);

    cout << "Maximum element: " << result.first << "\n";
    cout << "Minimum element: " << result.second << "\n";

    return 0;
}
