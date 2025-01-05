#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                       // number of vertices
    vector<vector<int>> adjMatrix; // Adjacency Matrix

public:
    Graph(int vertices)
    {
        V = vertices;
        adjMatrix.resize(V,vector<int>(V,0)); // Initialize VxV matrix with 0
    }

    void addEdge(int u, int v)
    {
        // udirected graph
       adjMatrix[u][v]=1;
       adjMatrix[v][u]=1;
    }

    void printGraph()
    {
         cout << "Adjacency Matrix:\n";
        for (int u=0;u<V;u++)
        {
            for (int v=0;v<V;v++)
            {
                cout<<adjMatrix[u][v]<<" ";
            }
            cout << endl;
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
    g.printGraph();
}