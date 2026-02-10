/**
 * Multistage Graph - Dynamic Programming
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 * Finds shortest path from source to destination in a multistage graph
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9;

/**
 * Count number of stages in graph
 * @param graph Adjacency matrix
 * @return Number of stages
 */
int countStages(const vector<vector<int>>& graph) {
    int stages = 1;
    int u = 0;
    
    for (size_t v = u + 1; v < graph.size(); v++) {
        if (graph[u][v] != INF && graph[u][v] != 0) {
            u = v;
            stages++;
        }
    }
    
    return stages;
}

/**
 * Find shortest path in multistage graph
 * @param graph Adjacency matrix
 * @param numStages Number of stages
 */
void multistageGraph(const vector<vector<int>>& graph, int numStages) {
    int n = graph.size();
    
    // Distance from each node to final node
    vector<int> dist(n, INF);
    
    // Next node in shortest path
    vector<int> nextNode(n, -1);
    
    // Final node has distance 0
    dist[n - 1] = 0;
    
    // Calculate minimum distance for each node (backward pass)
    for (int j = n - 2; j >= 0; j--) {
        for (int r = j + 1; r < n; r++) {
            if (graph[j][r] != INF && graph[j][r] != 0) {
                if (graph[j][r] + dist[r] < dist[j]) {
                    dist[j] = graph[j][r] + dist[r];
                    nextNode[j] = r;
                }
            }
        }
    }
    
    // Construct minimum-cost path
    vector<int> path;
    path.push_back(0); // Start from first node
    
    int current = 0;
    while (nextNode[current] != -1) {
        current = nextNode[current];
        path.push_back(current);
    }
    
    // Display results
    cout << "\nShortest Path: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << (path[i] + 1); // 1-indexed output
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << "\n";
    
    cout << "Minimum Cost: " << dist[0] << "\n";
}

int main() {
    int n;
    
    cout << "Multistage Graph Shortest Path (Dynamic Programming)\n";
    cout << string(50, '=') << "\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    // Initialize graph with INF (no edges)
    vector<vector<int>> graph(n, vector<int>(n, INF));
    
    // Diagonal elements are 0
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    int numEdges;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    cout << "Enter edges (u v cost) - 1-indexed:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u - 1][v - 1] = cost; // Convert to 0-indexed
    }

    int numStages = countStages(graph);
    cout << "\nNumber of stages: " << numStages << "\n";

    multistageGraph(graph, numStages);

    return 0;
}
