/**
 * Prim's Algorithm - Minimum Spanning Tree using Near Array
 * Time Complexity: O(V²) with adjacency matrix
 * Space Complexity: O(V)
 */

#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

/**
 * Prim's MST algorithm using "near" array approach
 * @param numVertices Number of vertices in graph
 * @param cost Adjacency matrix (INT_MAX for no edge)
 */
void primsAlgorithm(int numVertices, vector<vector<int>>& cost) {
    vector<int> near(numVertices, INT_MAX);  // Near array tracks closest MST vertex
    vector<pair<int, int>> mstEdges;         // Store MST edges
    int totalCost = 0;

    // Step 1: Find the minimum cost edge to start MST
    int u = -1, v = -1, minEdge = INT_MAX;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (cost[i][j] < minEdge) {
                minEdge = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    mstEdges.push_back({u, v});
    totalCost += minEdge;
    
    // Step 2: Initialize near array
    // For each vertex, find closer of u or v
    for (int i = 0; i < numVertices; i++) {
        if (cost[i][u] < cost[i][v]) {
            near[i] = u;
        } else {
            near[i] = v;
        }
    }
    
    // Mark included vertices
    near[u] = near[v] = -1;

    // Step 3: Add remaining (n-2) edges to MST
    for (int iteration = 1; iteration < numVertices - 1; iteration++) {
        int nextVertex = -1;
        int minCost = INT_MAX;

        // Find vertex with minimum cost to MST
        for (int j = 0; j < numVertices; j++) {
            if (near[j] != -1 && cost[j][near[j]] < minCost) {
                minCost = cost[j][near[j]];
                nextVertex = j;
            }
        }

        mstEdges.push_back({nextVertex, near[nextVertex]});
        totalCost += cost[nextVertex][near[nextVertex]];
        
        // Mark vertex as included
        near[nextVertex] = -1;

        // Update near array for remaining vertices
        for (int j = 0; j < numVertices; j++) {
            if (near[j] != -1 && cost[j][nextVertex] < cost[j][near[j]]) {
                near[j] = nextVertex;
            }
        }
    }

    // Display results
    cout << "\nMinimum Spanning Tree (MST) Edges:\n";
    cout << string(40, '-') << "\n";
    
    for (const auto& edge : mstEdges) {
        cout << "Edge: " << edge.first << " - " << edge.second << "\n";
    }
    
    cout << string(40, '-') << "\n";
    cout << "Total MST Cost: " << totalCost << "\n";
}

int main() {
    int numVertices = 5;
    
    // Adjacency matrix (INT_MAX represents no edge)
    vector<vector<int>> cost = {
        {INT_MAX, 2, INT_MAX, 6, INT_MAX},
        {2, INT_MAX, 3, 8, 5},
        {INT_MAX, 3, INT_MAX, INT_MAX, 7},
        {6, 8, INT_MAX, INT_MAX, 9},
        {INT_MAX, 5, 7, 9, INT_MAX}
    };

    cout << "Prim's Minimum Spanning Tree Algorithm\n";
    cout << string(40, '=') << "\n";
    cout << "Number of Vertices: " << numVertices << "\n";

    primsAlgorithm(numVertices, cost);

    return 0;
}

