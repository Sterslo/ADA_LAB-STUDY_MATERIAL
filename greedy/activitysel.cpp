/**
 * Activity Selection Problem - Greedy Algorithm
 * Time Complexity: O(n log n) for sorting
 * Space Complexity: O(1)
 * Selects maximum number of non-overlapping activities
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Activity structure
 */
struct Activity {
    int start;
    int finish;
    
    Activity(int s, int f) : start(s), finish(f) {}
};

/**
 * Comparator to sort activities by finish time
 */
bool compareByFinishTime(const Activity& a1, const Activity& a2) {
    return a1.finish < a2.finish;
}

/**
 * Select maximum number of non-overlapping activities
 * @param activities Vector of activities with start and finish times
 */
void selectActivities(vector<Activity>& activities) {
    if (activities.empty()) return;
    
    // Sort activities by finish time (greedy choice)
    sort(activities.begin(), activities.end(), compareByFinishTime);

    cout << "\nSelected Activities (Start, Finish):\n";
    cout << string(40, '-') << "\n";
    
    // Always select first activity
    int lastFinishTime = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";
    int count = 1;
    
    // Select remaining activities
    for (size_t i = 1; i < activities.size(); i++) {
        // If start time >= last finish time, select it
        if (activities[i].start >= lastFinishTime) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinishTime = activities[i].finish;
            count++;
        }
    }
    
    cout << string(40, '-') << "\n";
    cout << "Total activities selected: " << count << "\n";
}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {3, 9}, {0, 6}, {5, 7}, {8, 9}
    };

    cout << "Activity Selection Algorithm (Greedy)\n";
    cout << string(40, '=') << "\n";
    cout << "Input Activities:\n";
    for (const auto& activity : activities) {
        cout << "(" << activity.start << ", " << activity.finish << ") ";
    }
    cout << "\n";

    selectActivities(activities);

    return 0;
}

