#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph using DFS.
    bool isCycleDfs(vector<int> adj[], int u, vector<bool>& visited, int parent) {
        visited[u] = true; // Mark the current node as visited
        
        // Traverse all adjacent vertices
        for (int &v : adj[u]) {
            // If adjacent vertex is the parent, skip it
            if (v == parent)
                continue;

            // If the adjacent vertex is already visited, then a cycle is detected
            if (visited[v])
                return true;

            // If DFS from the adjacent vertex detects a cycle, return true
            if (isCycleDfs(adj, v, visited, u)) {
                return true;
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false); // Visited array to track nodes
        
        // Perform DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCycleDfs(adj, i, visited, -1)) {
                return true; // If a cycle is detected
            }
        }
        return false; // No cycle found
    }
};

// Driver code
int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    // Create adjacency list for the graph
    vector<int> adj[V];
    
    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge u-v
        adj[v].push_back(u); // Since the graph is undirected, add v-u as well
    }

    // Create a solution object and check if the graph contains a cycle
    Solution obj;
    bool result = obj.isCycle(V, adj);
    
    if (result) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
