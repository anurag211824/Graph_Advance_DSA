#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                       // number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        // udirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph()
    {

        for (int u = 0; u < V; u++)
        {
            cout << "Vertex " << u << ": ";
            for (auto &v : adjList[u])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    // BFS traversal for a single component
    void BfsTraversal(int src, vector<bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto &v : adjList[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // BFS traversal for all disconnected components
    void BfsTraversalAll()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) // Loop through all nodes
        {
            if (!visited[i]) // Start BFS if the node is unvisited
            {
                cout << "Component: ";
                BfsTraversal(i, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    int vertices = 12; // Total number of vertices
    Graph g(vertices);

    // Adding edges for Component 1
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Adding edges for Component 2
    g.addEdge(5, 6);
    g.addEdge(5, 7);

    // Adding edges for Component 3
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(10, 11);

    // Print the adjacency list
    // g.printGraph();
    
    g.BfsTraversalAll();
}