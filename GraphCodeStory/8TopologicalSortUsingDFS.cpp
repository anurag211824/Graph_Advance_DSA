#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Your Solution class definition
class Solution
{
public:
    stack<int> st;

    void TopologicalSort(vector<vector<int>> &adj, vector<bool> &visited, int u)
    {
        visited[u] = true;
        // Traverse all adjacent vertices and push them to the stack
        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                TopologicalSort(adj, visited, v);
            }
        }
        // Push the vertex to the stack
        st.push(u);
    }

    // Function to return a list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> adj)
    {
        int v = adj.size();
        vector<bool> visited(v, false);

        for (int u = 0; u < v; u++)
        {
            if (!visited[u])
                TopologicalSort(adj, visited, u);
        }

        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

int main()
{
    // Hardcoded adjacency list for the graph
    vector<vector<int>> adj = {
        {2, 3}, // Vertex 0 has directed edges to vertices 2 and 3
        {3},    // Vertex 1 has a directed edge to vertex 3
        {3},    // Vertex 2 has a directed edge to vertex 3
        {},     // Vertex 3 has no outgoing edges
        {0, 1}, // Vertex 4 has directed edges to vertices 0 and 1
        {0, 2}  // Vertex 5 has directed edges to vertices 0 and 2
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
