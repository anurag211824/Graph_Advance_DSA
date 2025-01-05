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
    void BfsTraversal(int src)
    {
        vector<bool> visited(V + 1, false);
        visited[src] = true;
        queue<int> q;
        q.push(src);
        cout<<"Bfs Traversal: ";
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto &v : adjList[u])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};

int main()
{
    int vertices = 5; // Number of vertices
    Graph g(vertices);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency list
    //g.printGraph();
    g.BfsTraversal(0);
}