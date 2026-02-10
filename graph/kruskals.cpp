/**
 * Kruskal's Algorithm - Minimum Spanning Tree
 * Time Complexity: O(E log E) where E is number of edges
 * Space Complexity: O(V) for DSU
 * Uses Disjoint Set Union (DSU) with path compression and union by size
 */

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/**
 * Disjoint Set Union (DSU) Data Structure
 * Implements union-find with path compression and union by size
 */
class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int n) : parent(n, -1) {}

    /**
     * Find root of element with path compression
     * @param node Element to find
     * @return Root of the set
     */
    int find(int node) {
        if (parent[node] < 0) return node;
        return parent[node] = find(parent[node]);
    }

    /**
     * Union two sets by size
     * @param u First element
     * @param v Second element
     * @return true if union performed, false if already in same set
     */
    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return false; // Already in same set

        // Union by size: attach smaller tree under larger tree
        if (parent[rootU] < parent[rootV]) {
            parent[rootU] += parent[rootV];
            parent[rootV] = rootU;
        } else {
            parent[rootV] += parent[rootU];
            parent[rootU] = rootV;
        }
        return true;
    }
};

/**
 * Edge structure for storing graph edges
 */
struct Edge {
    int weight, u, v;
    
    Edge(int w, int src, int dest) : weight(w), u(src), v(dest) {}
    
    // Comparator for min-heap (priority queue)
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

/**
 * Kruskal's algorithm to find Minimum Spanning Tree
 * @param numVertices Number of vertices in graph
 * @param edges Vector of edges {weight, u, v}
 */
void kruskalMST(int numVertices, vector<vector<int>>& edges) {
    // Create min-heap of edges sorted by weight
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    
    for (const auto& edge : edges) {
        minHeap.push(Edge(edge[0], edge[1], edge[2]));
    }

    DisjointSet dsu(numVertices);
    int totalCost = 0;
    int edgesUsed = 0;

    cout << "\nMinimum Spanning Tree Edges:\n";
    cout << string(40, '-') << "\n";

    while (!minHeap.empty() && edgesUsed < numVertices - 1) {
        Edge edge = minHeap.top();
        minHeap.pop();

        // If adding edge doesn't create cycle, include it
        if (dsu.unionSets(edge.u, edge.v)) {
            totalCost += edge.weight;
            edgesUsed++;
            cout << "Edge: (" << edge.u << " - " << edge.v 
                 << ") | Weight: " << edge.weight << "\n";
        }
    }

    cout << string(40, '-') << "\n";
    
    if (edgesUsed == numVertices - 1) {
        cout << "Total MST Cost: " << totalCost << "\n";
    } else {
        cout << "MST not possible (graph is not connected)!\n";
    }
}

int main() {
    int numVertices = 5;
    
    // Edges: {weight, vertex1, vertex2}
    vector<vector<int>> edges = {
        {2, 0, 1}, {3, 1, 2}, {7, 2, 4}, {5, 1, 4}, {9, 3, 4}, {6, 0, 3}, {8, 1, 3}
    };

    cout << "Kruskal's Minimum Spanning Tree Algorithm\n";
    cout << string(40, '=') << "\n";
    cout << "Number of vertices: " << numVertices << "\n";
    cout << "Number of edges: " << edges.size() << "\n";

    kruskalMST(numVertices, edges);

    return 0;
}
