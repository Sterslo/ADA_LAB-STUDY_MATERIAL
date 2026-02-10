/**
 * Peak Element Finding - Binary Search Approach
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Peak element is greater than its neighbors
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Find a peak element using binary search
 * @param arr Array to search
 * @return Index of peak element
 */
int findPeakElement(const vector<int>& arr) {
    int n = arr.size();
    
    // Edge case: single element
    if (n == 1) return 0;
    
    // Check first element
    if (arr[0] > arr[1]) return 0;
    
    // Check last element
    if (arr[n - 1] > arr[n - 2]) return n - 1;
    
    int low = 1;
    int high = n - 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is peak
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        
        // If left neighbor is greater, peak is in left half
        else if (arr[mid] < arr[mid - 1]) {
            high = mid - 1;
        }
        
        // Otherwise, peak is in right half
        else {
            low = mid + 1;
        }
    }
    
    return -1; // Should never reach here
}

int main() {
    vector<int> arr = {11, 13, 20, 25, 18};

    cout << "Peak Element Finding Algorithm\n";
    cout << string(40, '=') << "\n";
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n\n";

    int peakIndex = findPeakElement(arr);
    
    if (peakIndex != -1) {
        cout << "Peak element: " << arr[peakIndex] << "\n";
        cout << "Peak index: " << peakIndex << "\n";
    } else {
        cout << "No peak element found\n";
    }

    return 0;
}
