#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order using Kahn's Algorithm (BFS).
    vector<int> topologicalSort(vector<vector<int>> adj)
    {
        int n = adj.size();
        queue<int> que;
        vector<int> Indegree(n, 0);

        // Marking the indegree of each node
        for (int u = 0; u < n; u++)
        {
            for (int &v : adj[u])
            {
                Indegree[v]++;
            }
        }

        // Pushing all nodes with zero indegree
        for (int u = 0; u < n; u++)
        {
            if (Indegree[u] == 0)
            {
                que.push(u);
            }
        }

        vector<int> res;
        // Simple BFS for sorting
        while (!que.empty())
        {
            int u = que.front();
            res.push_back(u);
            que.pop();

            for (int &v : adj[u])
            {
                Indegree[v]--;
                if (Indegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }

        return res;
    }
};

int main()
{
    // Hardcoded adjacency list for the graph
    vector<vector<int>> adj = {
        {1, 2}, // Vertex 0 has edges to vertices 1 and 2
        {3},    // Vertex 1 has an edge to vertex 3
        {3},    // Vertex 2 has an edge to vertex 3
        {},     // Vertex 3 has no outgoing edges
        {0, 2}  // Vertex 4 has edges to vertices 0 and 2
    };

    Solution obj;
    vector<int> topoOrder = obj.topologicalSort(adj);

    // Output the topological sort result
    cout << "Topological Order: ";
    for (int v : topoOrder)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
