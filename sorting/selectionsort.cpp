/**
 * Selection Sort Algorithm - Comparison-based sorting
 * Time Complexity: O(n²) in all cases
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
 * Selection Sort implementation
 * @param arr Vector to sort
 */
void selectionSort(vector<long>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap if minimum is not at current position
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << fixed << setprecision(6);
    cout << "Selection Sort Performance Analysis\n";
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
            selectionSort(arr);
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
