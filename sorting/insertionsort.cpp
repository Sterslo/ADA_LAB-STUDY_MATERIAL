/**
 * Insertion Sort Algorithm - Comparison-based sorting
 * Time Complexity: O(n²) worst/average case, O(n) best case
 * Space Complexity: O(1) - In-place sorting
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace chrono;

/**
 * Insertion Sort implementation
 * @param arr Vector to sort
 */
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Shift elements greater than key one position right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << fixed << setprecision(3);
    cout << "Insertion Sort Performance Analysis\n";
    cout << string(55, '-') << "\n";
    cout << left << setw(20) << "Array Size" 
         << setw(25) << "Avg Time (ms)" << "\n";
    cout << string(55, '-') << "\n";

    const int ITERATIONS = 10;
    
    for (int size = 1000; size <= 10000; size += 1000) {
        long long totalTime = 0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            vector<int> arr(size);
            uniform_int_distribution<int> dist(1, 100000);
            
            // Generate random array
            for (int i = 0; i < size; i++) {
                arr[i] = dist(gen);
            }

            auto start = high_resolution_clock::now();
            insertionSort(arr);
            auto end = high_resolution_clock::now();

            auto elapsed = duration_cast<microseconds>(end - start);
            totalTime += elapsed.count();
        }

        double avgTime = totalTime / (ITERATIONS * 1000.0); // Convert to milliseconds
        cout << left << setw(20) << size 
             << setw(25) << avgTime << "\n";
    }

    return 0;
}
