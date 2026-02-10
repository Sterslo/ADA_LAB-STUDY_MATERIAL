/**
 * Floyd-Warshall Algorithm - All Pairs Shortest Path
 * Time Complexity: O(V^3)
 * Space Complexity: O(V^2)
 * Finds shortest paths between all pairs of vertices
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
 * Floyd-Warshall algorithm
 * @param graph Adjacency matrix (-1 means no edge)
 * @param n Number of vertices
 */
void floydWarshall(vector<vector<int>>& graph, int n) {
    // For each intermediate vertex k
    for (int k = 0; k < n; k++) {
        // For each source vertex i
        for (int i = 0; i < n; i++) {
            // For each destination vertex j
            for (int j = 0; j < n; j++) {
                // If path through k is shorter, update distance
                if (graph[i][k] != -1 && graph[k][j] != -1) {
                    if (graph[i][j] == -1 || graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

/**
 * Print distance matrix
 * @param graph Distance matrix
 */
void printMatrix(const vector<vector<int>>& graph) {
    cout << "\nShortest Distance Matrix:\n";
    cout << string(40, '-') << "\n";
    
    for (const auto& row : graph) {
        for (int val : row) {
            if (val == -1) {
                cout << setw(6) << "INF";
            } else {
                cout << setw(6) << val;
            }
        }
        cout << "\n";
    }
}

int main() {
    int n = 4; // Number of vertices
    
    // -1 represents no direct edge (infinity)
    // Graph can have negative weights but not negative cycles
    vector<vector<int>> graph = {
        {0, 9, -4, -1},
        {6, 0, -1, 2},
        {-1, 5, 0, -1},
        {-1, -1, 1, 0}
    };

    cout << "Floyd-Warshall All-Pairs Shortest Path Algorithm\n";
    cout << string(50, '=') << "\n";
    cout << "Number of vertices: " << n << "\n";
    
    cout << "\nInitial Adjacency Matrix:\n";
    cout << string(40, '-') << "\n";
    for (const auto& row : graph) {
        for (int val : row) {
            if (val == -1) {
                cout << setw(6) << "INF";
            } else {
                cout << setw(6) << val;
            }
        }
        cout << "\n";
    }

    floydWarshall(graph, n);
    printMatrix(graph);

    return 0;
}
