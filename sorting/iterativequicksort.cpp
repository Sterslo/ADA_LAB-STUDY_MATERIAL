/**
 * Iterative QuickSort Algorithm - Using Stack
 * Time Complexity: O(n log n) average, O(n²) worst case
 * Space Complexity: O(log n) for stack
 */

#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace chrono;

/**
 * Partition function for QuickSort
 * @param arr Array to partition
 * @param low Starting index
 * @param high Ending index
 * @return Pivot position
 */
int partition(vector<long>& arr, int low, int high) {
    long pivot = arr[low];
    int left = low + 1;
    int right = high;
    
    while (left <= right) {
        // Find element larger than pivot from left
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        
        // Find element smaller than pivot from right
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    
    swap(arr[low], arr[right]);
    return right;
}

/**
 * Iterative QuickSort using explicit stack
 * @param arr Array to sort
 * @param low Starting index
 * @param high Ending index
 */
void iterativeQuickSort(vector<long>& arr, int low, int high) {
    stack<pair<int, int>> st;
    
    do {
        while (low < high) {
            int pivotIdx = partition(arr, low, high);
            
            // Push larger subarray to stack, process smaller one
            if ((pivotIdx - low) > (high - pivotIdx)) {
                st.push({low, pivotIdx - 1});
                low = pivotIdx + 1;
            } else {
                st.push({pivotIdx + 1, high});
                high = pivotIdx - 1;
            }
        }
        
        if (st.empty()) return;
        
        auto range = st.top();
        st.pop();
        low = range.first;
        high = range.second;
        
    } while (true);
}

/**
 * Verify if array is sorted
 * @param arr Array to check
 * @return true if sorted, false otherwise
 */
bool isSorted(const vector<long>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << fixed << setprecision(6);
    cout << "Iterative QuickSort Performance Analysis\n";
    cout << string(50, '-') << "\n";
    cout << left << setw(15) << "Array Size" 
         << setw(20) << "Avg Time (sec)" << "\n";
    cout << string(50, '-') << "\n";

    const int ITERATIONS = 10;
    
    for (int size = 1000; size <= 10000; size += 1000) {
        double totalTime = 0.0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            vector<long> arr(size);
            uniform_int_distribution<long> dist(1, size);
            
            // Generate random array
            for (int i = 0; i < size; i++) {
                arr[i] = dist(gen);
            }

            auto start = high_resolution_clock::now();
            iterativeQuickSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();

            // Validate sorting
            if (!isSorted(arr)) {
                cerr << "Error: Sorting failed for size " << size << "\n";
                return 1;
            }

            duration<double> elapsed = end - start;
            totalTime += elapsed.count();
        }

        double avgTime = totalTime / ITERATIONS;
        cout << left << setw(15) << size 
             << setw(20) << avgTime << "\n";
    }

    return 0;
}

        }

        double avgTime = totalTime / 10;
        cout << "Size: " << n << ", Time: " << avgTime << " seconds" << endl;

        n += 1000; // Increment n properly
    }

    return 0;
}
// Time complexity: O(nlogn) in average case and O(n^2) in worst case

