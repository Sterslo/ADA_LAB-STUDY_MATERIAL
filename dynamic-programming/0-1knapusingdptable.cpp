/**
 * 0-1 Knapsack Problem - Dynamic Programming with Traceback
 * Time Complexity: O(n * W)
 * Space Complexity: O(n * W)
 * Items cannot be divided (take completely or leave)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 0-1 Knapsack with item traceback
 * @param weights Vector of item weights
 * @param values Vector of item values
 * @param capacity Knapsack capacity
 * @return Maximum value achievable
 */
int knapsack01(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Max of taking or not taking current item
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Traceback to find selected items
    int w = capacity;
    vector<int> selectedItems;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i); // Item i was selected (1-indexed)
            w -= weights[i - 1];
        }
    }

    // Display results
    cout << "\nMaximum value: " << dp[n][capacity] << "\n";
    cout << "Selected items (1-indexed): ";
    for (auto it = selectedItems.rbegin(); it != selectedItems.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {5, 4, 6, 3};
    vector<int> values = {10, 40, 30, 50};
    int capacity = 10;

    cout << "0-1 Knapsack Problem (Dynamic Programming)\n";
    cout << string(50, '=') << "\n";
    cout << "Knapsack Capacity: " << capacity << "\n";
    cout << "\nItems:\n";
    for (size_t i = 0; i < weights.size(); i++) {
        cout << "Item " << (i + 1) << ": Weight=" << weights[i] 
             << ", Value=" << values[i] << "\n";
    }

    knapsack01(weights, values, capacity);

    return 0;
}
