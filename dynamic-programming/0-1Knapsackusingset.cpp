/**
 * 0-1 Knapsack using Sets - Dynamic Programming
 * Time Complexity: O(n * W)
 * Space Complexity: O(n * W)
 * Uses set data structure to store feasible (profit, weight) pairs
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

using Pair = pair<int, int>; // (profit, weight)

/**
 * Merge and purge operation on two sets
 * Removes dominated pairs (lower profit with same or higher weight)
 * @param a First set
 * @param b Second set
 * @return Merged and purged set
 */
set<Pair> mergePurge(const set<Pair>& a, const set<Pair>& b) {
    set<Pair> combined = a;
    combined.insert(b.begin(), b.end());
    
    set<Pair> result;
    int maxProfit = -1;
    
    for (const auto& p : combined) {
        if (p.first > maxProfit) {
            result.insert(p);
            maxProfit = p.first;
        }
    }
    
    return result;
}

/**
 * Traceback to find selected items
 * @param finalProfit Final profit achieved
 * @param finalWeight Final weight used
 * @param n Number of items
 * @param S Array of sets for each stage
 * @param weights Item weights
 * @param values Item values
 */
void traceback(int finalProfit, int finalWeight, int n, 
               const vector<set<Pair>>& S, 
               const vector<int>& weights, 
               const vector<int>& values) {
    
    cout << "\nSelected Items (1-indexed):\n";
    
    for (int i = n - 1; i >= 0; i--) {
        int prevProfit = finalProfit - values[i];
        int prevWeight = finalWeight - weights[i];
        
        if (S[i].count({finalProfit, finalWeight})) {
            cout << "  Item " << (i + 1) << ": NOT selected\n";
        } else if (S[i].count({prevProfit, prevWeight})) {
            cout << "  Item " << (i + 1) << ": SELECTED\n";
            finalProfit = prevProfit;
            finalWeight = prevWeight;
        }
    }
}

/**
 * 0-1 Knapsack using set-based dynamic programming
 * @param weights Item weights
 * @param values Item values
 * @param capacity Knapsack capacity
 */
void knapsackSet(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<set<Pair>> S(n + 1);
    
    // Base: empty knapsack
    S[0].insert({0, 0});
    
    // Fill DP sets
    for (int i = 1; i <= n; i++) {
        set<Pair> S1; // Set of pairs including current item
        
        for (const auto& p : S[i - 1]) {
            int newWeight = p.second + weights[i - 1];
            int newProfit = p.first + values[i - 1];
            
            if (newWeight <= capacity) {
                S1.insert({newProfit, newWeight});
            }
        }
        
        S[i] = mergePurge(S[i - 1], S1);
    }
    
    // Find maximum profit
    auto it = S[n].rbegin(); // Last element (max profit)
    int maxProfit = it->first;
    int usedWeight = it->second;
    
    cout << "\nMaximum Profit: " << maxProfit << "\n";
    cout << "Weight Used: " << usedWeight << "\n";
    
    traceback(maxProfit, usedWeight, n, S, weights, values);
}

int main() {
    vector<int> weights = {5, 4, 6, 3};
    vector<int> values = {10, 40, 30, 50};
    int capacity = 10;

    cout << "0-1 Knapsack using Sets (Dynamic Programming)\n";
    cout << string(50, '=') << "\n";
    cout << "Knapsack Capacity: " << capacity << "\n";
    cout << "\nItems:\n";
    for (size_t i = 0; i < weights.size(); i++) {
        cout << "  Item " << (i + 1) << ": Weight=" << weights[i] 
             << ", Value=" << values[i] << "\n";
    }

    knapsackSet(weights, values, capacity);

    return 0;
}
