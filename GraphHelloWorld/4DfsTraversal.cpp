#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        // Undirected graph
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

    // DFS traversal for a single component
    void DfsTraversalRec(int src, vector<bool> &visited)
    {
        visited[src] = true;
        cout << src << " "; // Print current node

        for (int &v : adjList[src])
        {
            if (!visited[v])
            {
                DfsTraversalRec(v, visited);
            }
        }
    }

    // DFS traversal for all disconnected components
    void DfsTraversal()
    {
        vector<bool> visited(V, false);

        cout << "DFS Traversal (by components):" << endl;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cout << "Component: ";
                DfsTraversalRec(i, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    int vertices = 12;
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

    g.DfsTraversal(); // Perform DFS traversal
    cout << endl;

    g.printGraph(); // Print adjacency list representation
}
