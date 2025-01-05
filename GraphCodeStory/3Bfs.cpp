#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> res;

    // BFS helper function
    void bfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        res.push_back(u);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : adj[u])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                    res.push_back(v);
                }
            }
        }
    }

    // Function to return Breadth First Traversal of the given graph
    vector<int> bfsOfGraph(vector<vector<int>> &matrix)
    {
        int noOfVertices = matrix.size();
        unordered_map<int, vector<int>> adj;

        // Building the adjacency list from the matrix
        for (int u = 0; u < noOfVertices; u++)
        {
            for (auto it = matrix[u].begin(); it != matrix[u].end(); it++)
            {
                adj[u].push_back(*it);
            }
        }

        // BFS traversal
        vector<bool> visited(noOfVertices, false);
        bfs(adj, 0, visited);
        return res;
    }
};

// Driver code to test the BFS traversal
int main()
{
    Solution solution;

    // Example adjacency matrix representation of a graph
    vector<vector<int>> graph = {
        {1, 2},    // edges from vertex 0
        {0, 3, 4}, // edges from vertex 1
        {0, 4},    // edges from vertex 2
        {1, 5},    // edges from vertex 3
        {1, 2, 5}, // edges from vertex 4
        {3, 4}     // edges from vertex 5
    };

    vector<int> bfsResult = solution.bfsOfGraph(graph);

    // Output the BFS result
    cout << "BFS Traversal of the graph: ";
    for (int v : bfsResult)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}