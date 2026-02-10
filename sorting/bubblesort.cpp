/**
 * Bubble Sort Algorithm - Comparison-based sorting
 * Time Complexity: O(n²) in worst/average case, O(n) best case
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
 * Bubble Sort implementation with optimization
 * @param arr Vector to sort
 */
void bubbleSort(vector<long>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Early termination if array is already sorted
        if (!swapped) break;
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << fixed << setprecision(6);
    cout << "Bubble Sort Performance Analysis\n";
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
            bubbleSort(arr);
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

