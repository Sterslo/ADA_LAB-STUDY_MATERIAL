/**
 * Merge Sort Algorithm - Divide and Conquer Approach
 * Time Complexity: O(n log n) in all cases
 * Space Complexity: O(n) for temporary array
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace chrono;

/**
 * Merge two sorted subarrays
 * @param arr Main array
 * @param low Starting index
 * @param mid Middle index
 * @param high Ending index
 */
void merge(vector<long>& arr, int low, int mid, int high) {
    int leftIdx = low;
    int rightIdx = mid + 1;
    vector<long> temp;
    
    // Merge elements in sorted order
    while (leftIdx <= mid && rightIdx <= high) {
        if (arr[leftIdx] <= arr[rightIdx]) {
            temp.push_back(arr[leftIdx++]);
        } else {
            temp.push_back(arr[rightIdx++]);
        }
    }
    
    // Copy remaining elements from left half
    while (leftIdx <= mid) {
        temp.push_back(arr[leftIdx++]);
    }
    
    // Copy remaining elements from right half
    while (rightIdx <= high) {
        temp.push_back(arr[rightIdx++]);
    }
    
    // Copy merged elements back to original array
    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}

/**
 * Recursive Merge Sort function
 * @param arr Array to sort
 * @param low Starting index
 * @param high Ending index
 */
void mergeSort(vector<long>& arr, int low, int high) {
    if (low >= high) return;
    
    int mid = low + (high - low) / 2;
    
    // Sort left half
    mergeSort(arr, low, mid);
    
    // Sort right half
    mergeSort(arr, mid + 1, high);
    
    // Merge sorted halves
    merge(arr, low, mid, high);
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << fixed << setprecision(6);
    cout << "Merge Sort Performance Analysis\n";
    cout << string(50, '-') << "\n";
    cout << left << setw(15) << "Array Size" 
         << setw(20) << "Avg Time (sec)" << "\n";
    cout << string(50, '-') << "\n";

    const int ITERATIONS = 10;
    
    for (int size = 10000; size <= 100000; size += 10000) {
        double totalTime = 0.0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            vector<long> arr(size);
            uniform_int_distribution<long> dist(1, size);
            
            // Generate random array
            for (int i = 0; i < size; i++) {
                arr[i] = dist(gen);
            }

            auto start = high_resolution_clock::now();
            mergeSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();

            duration<double> elapsed = end - start;
            totalTime += elapsed.count();
        }

        double avgTime = totalTime / ITERATIONS;
        cout << left << setw(15) << size 
             << setw(20) << avgTime << "\n";
    }

    return 0;
}

