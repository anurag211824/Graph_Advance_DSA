#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair

using namespace std;

class Solution
{
public:
    bool isCycleBfs(vector<int> adj[], int u, vector<bool> &visited)
    {
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;

        while (!q.empty())
        {
            pair<int, int> P = q.front();
            q.pop();
            int src = P.first;
            int parent = P.second;

            for (int &v : adj[src])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, src});
                }
                else if (v != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCycleBfs(adj, i, visited))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // Number of vertices
    int V = 5;

    // Adjacency list for the graph
    vector<int> adj[V];

    // Adding edges to the graph (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Uncomment the line below to introduce a cycle
    adj[4].push_back(1);
    adj[1].push_back(4);

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj);

    if (hasCycle)
    {
        cout << "Graph contains a cycle." << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
