/**
 * Dijkstra's Algorithm - Single Source Shortest Path
 * Time Complexity: O(V²) with adjacency matrix
 * Space Complexity: O(V)
 * Finds shortest paths from source vertex to all other vertices
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

const int VERTICES = 9;

/**
 * Find vertex with minimum distance value from unvisited vertices
 * @param dist Distance array
 * @param visited Visited status array
 * @return Index of vertex with minimum distance
 */
int findMinDistance(const vector<int>& dist, const vector<bool>& visited) {
    int minDist = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < VERTICES; v++) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

/**
 * Display shortest path distances from source
 * @param dist Distance array
 */
void displaySolution(const vector<int>& dist) {
    cout << "\nShortest Path Results:\n";
    cout << string(40, '-') << "\n";
    cout << left << setw(15) << "Vertex" 
         << setw(25) << "Distance from Source\n";
    cout << string(40, '-') << "\n";
    
    for (int i = 0; i < VERTICES; i++) {
        cout << left << setw(15) << i 
             << setw(25) << dist[i] << "\n";
    }
}

/**
 * Dijkstra's shortest path algorithm
 * @param graph Adjacency matrix (0 means no edge)
 * @param source Source vertex
 */
void dijkstra(const vector<vector<int>>& graph, int source) {
    vector<int> dist(VERTICES, INT_MAX);
    vector<bool> visited(VERTICES, false);

    dist[source] = 0;

    // Process all vertices
    for (int count = 0; count < VERTICES - 1; count++) {
        int u = findMinDistance(dist, visited);
        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < VERTICES; v++) {
            // Update dist[v] if:
            // 1. v is not visited
            // 2. There's an edge from u to v
            // 3. Path through u is shorter
            if (!visited[v] && graph[u][v] != 0 && 
                dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    displaySolution(dist);
}

int main() {
    // Graph represented as adjacency matrix
    // 0 means no direct edge between vertices
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    cout << "Dijkstra's Shortest Path Algorithm\n";
    cout << string(40, '=') << "\n";
    
    int sourceVertex = 0;
    cout << "Source Vertex: " << sourceVertex << "\n";
    
    dijkstra(graph, sourceVertex);

    return 0;
}
