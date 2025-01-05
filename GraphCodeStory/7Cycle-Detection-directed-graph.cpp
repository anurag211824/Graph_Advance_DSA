#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isCyclicDfs(vector<int> adj[], vector<bool> &visited, vector<bool> &inRecursion, int u)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v] && isCyclicDfs(adj, visited, inRecursion, v))
            {
                return true;
            }
            else if (inRecursion[v])
            {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        for (int u = 0; u < V; u++)
        {
            if (!visited[u] && isCyclicDfs(adj, visited, inRecursion, u))
            {
                return true;
            }
        }

        return false;
    }
};

// Driver code
int main()
{
    int V = 4;          // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the graph (directed graph)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // This creates a cycle (1 -> 2 -> 3 -> 1)

    Solution solution;
    bool result = solution.isCyclic(V, adj);

    if (result)
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
