/**
 * Fractional Knapsack Problem - Greedy Algorithm
 * Time Complexity: O(n log n) for sorting
 * Space Complexity: O(1)
 * Allows taking fractional parts of items
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * Item structure with profit and weight
 */
struct Item {
    int profit;
    int weight;
    
    Item(int p, int w) : profit(p), weight(w) {}
    
    // Calculate profit-to-weight ratio
    double ratio() const {
        return static_cast<double>(profit) / weight;
    }
};

/**
 * Comparator to sort items by profit/weight ratio (descending)
 */
bool compareByRatio(const Item& a, const Item& b) {
    return a.ratio() > b.ratio();
}

/**
 * Fractional Knapsack algorithm
 * @param items Vector of items
 * @param capacity Knapsack capacity
 */
void fractionalKnapsack(vector<Item>& items, int capacity) {
    // Sort items by profit/weight ratio (greedy choice)
    sort(items.begin(), items.end(), compareByRatio);

    double totalProfit = 0.0;
    int currentWeight = 0;

    cout << fixed << setprecision(2);
    cout << "\nItems selected:\n";
    cout << string(60, '-') << "\n";
    cout << left << setw(15) << "Profit" 
         << setw(15) << "Weight" 
         << setw(20) << "Type" << "\n";
    cout << string(60, '-') << "\n";

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take full item
            totalProfit += item.profit;
            currentWeight += item.weight;
            cout << left << setw(15) << item.profit 
                 << setw(15) << item.weight 
                 << setw(20) << "Full" << "\n";
        } else {
            // Take fractional part
            int remainingWeight = capacity - currentWeight;
            double fractionalProfit = item.profit * (static_cast<double>(remainingWeight) / item.weight);
            totalProfit += fractionalProfit;
            
            cout << left << setw(15) << fractionalProfit 
                 << setw(15) << remainingWeight 
                 << setw(20) << "Fractional" << "\n";
            break; // Knapsack is full
        }
    }

    cout << string(60, '-') << "\n";
    cout << "Total Profit: " << totalProfit << "\n";
}

int main() {
    vector<Item> items = {
        {25, 18}, {24, 15}, {15, 10}
    };
    int capacity = 20;

    cout << "Fractional Knapsack Algorithm (Greedy)\n";
    cout << string(40, '=') << "\n";
    cout << "Knapsack Capacity: " << capacity << "\n";
    cout << "\nAvailable Items:\n";
    for (size_t i = 0; i < items.size(); i++) {
        cout << "Item " << (i + 1) << ": Profit=" << items[i].profit 
             << ", Weight=" << items[i].weight 
             << ", Ratio=" << fixed << setprecision(2) << items[i].ratio() << "\n";
    }

    fractionalKnapsack(items, capacity);

    return 0;
}










