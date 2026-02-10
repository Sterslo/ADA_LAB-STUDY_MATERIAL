/**
 * Binary Search - Recursive Implementation
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) for recursion stack
 * Works only on sorted arrays
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Recursive binary search function
 * @param arr Sorted array to search in
 * @param key Element to search for
 * @param left Left boundary
 * @param right Right boundary
 * @return true if found, false otherwise
 */
bool binarySearch(const vector<int>& arr, int key, int left, int right) {
    if (left > right) {
        return false; // Base case: element not found
    }

    int mid = left + (right - left) / 2; // Prevent overflow

    if (arr[mid] == key) {
        return true; // Base case: element found
    }

    if (key < arr[mid]) {
        return binarySearch(arr, key, left, mid - 1); // Search left half
    } else {
        return binarySearch(arr, key, mid + 1, right); // Search right half
    }
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int key = 10;

    cout << "Binary Search Algorithm\n";
    cout << string(40, '=') << "\n";
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\nSearching for: " << key << "\n\n";

    bool found = binarySearch(arr, key, 0, arr.size() - 1);

    if (found) {
        cout << "Result: Element FOUND\n";
    } else {
        cout << "Result: Element NOT FOUND\n";
    }

    return 0;
}

