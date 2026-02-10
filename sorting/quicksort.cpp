/**
 * QuickSort Algorithm - Recursive Implementation
 * Time Complexity: O(n log n) average, O(n²) worst case
 * Space Complexity: O(log n) for recursion stack
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace chrono;

/**
 * Partition the array around a pivot element
 * @param arr Array to partition
 * @param low Starting index
 * @param high Ending index
 * @return Final position of pivot element
 */
int partition(vector<long>& arr, int low, int high) {
    long pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right) {
        // Find element greater than pivot from left
        while (left <= high - 1 && arr[left] <= pivot) {
            left++;
        }
        
        // Find element smaller than pivot from right
        while (right >= low + 1 && arr[right] > pivot) {
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
 * Recursive QuickSort function
 * @param arr Array to sort
 * @param low Starting index
 * @param high Ending index
 */
void quickSort(vector<long>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << fixed << setprecision(6);
    cout << "QuickSort Performance Analysis\n";
    cout << string(50, '-') << "\n";
    cout << left << setw(15) << "Array Size" 
         << setw(20) << "Avg Time (sec)" << "\n";
    cout << string(50, '-') << "\n";

    const int ITERATIONS = 10;
    
    for (int size = 1000; size <= 25000; size += 1000) {
        double totalTime = 0.0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            vector<long> arr(size);
            uniform_int_distribution<long> dist(1, size);
            
            // Generate random array
            for (int i = 0; i < size; i++) {
                arr[i] = dist(gen);
            }

            auto start = high_resolution_clock::now();
            quickSort(arr, 0, size - 1);
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
