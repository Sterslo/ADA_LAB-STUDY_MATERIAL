/**
 * Jaccard Similarity Coefficient
 * Time Complexity: O(n + m) where n, m are array sizes
 * Space Complexity: O(n + m)
 * Measures similarity between two sets
 * Jaccard = |A ∩ B| / |A ∪ B|
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>

using namespace std;

/**
 * Calculate Jaccard similarity coefficient
 * @param arr1 First array
 * @param arr2 Second array
 * @return Jaccard coefficient (0 to 1)
 */
double jaccardSimilarity(const vector<int>& arr1, const vector<int>& arr2) {
    // Convert arrays to sets (removes duplicates)
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());

    // Calculate intersection
    int intersectionSize = 0;
    for (int num : set1) {
        if (set2.count(num)) {
            intersectionSize++;
        }
    }

    // Calculate union
    unordered_set<int> unionSet = set1;
    unionSet.insert(set2.begin(), set2.end());
    int unionSize = unionSet.size();

    // Calculate Jaccard coefficient
    if (unionSize == 0) return 0.0;
    
    return static_cast<double>(intersectionSize) / unionSize;
}

int main() {
    vector<int> arr1 = {0, 1, 2, 5, 6};
    vector<int> arr2 = {0, 2, 3, 4, 5, 7, 9};

    cout << "Jaccard Similarity Coefficient\n";
    cout << string(50, '=') << "\n";
    
    cout << "Set A: ";
    for (int num : arr1) cout << num << " ";
    cout << "\n";
    
    cout << "Set B: ";
    for (int num : arr2) cout << num << " ";
    cout << "\n\n";

    double jaccard = jaccardSimilarity(arr1, arr2);

    cout << fixed << setprecision(4);
    cout << "Jaccard Coefficient: " << jaccard << "\n";
    cout << "Similarity Percentage: " << (jaccard * 100) << "%\n";

    return 0;
}
