#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> result;

    void dfs(unordered_map<int, vector<int>> &adjacencyList, int u, vector<bool> &visited)
    {
        if (visited[u] == true)
            return;
        visited[u] = true;
        result.push_back(u);
        for (auto &v : adjacencyList[u])
        {
            if (!visited[v])
            {
                dfs(adjacencyList, v, visited);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>> &matrix)
    {
        unordered_map<int, vector<int>> adjacencyList;
        int numberOfvertices = matrix.size();
        for (int u = 0; u < numberOfvertices; u++)
        {
            for (auto it = matrix[u].begin(); it != matrix[u].end(); it++)
            {
                adjacencyList[u].push_back(*it);
            }
        }
        vector<bool> visited(numberOfvertices, false);
        dfs(adjacencyList, 0, visited);
        return result;
    }
};

// Driver code
int main()
{
    // Example graph represented as an adjacency matrix
    vector<vector<int>> matrix = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 3, 4}, // Node 1 is connected to nodes 0, 3, and 4
        {0, 4},    // Node 2 is connected to nodes 0 and 4
        {1},       // Node 3 is connected to node 1
        {1, 2}     // Node 4 is connected to nodes 1 and 2
    };

    Solution obj;
    vector<int> dfsResult = obj.dfsOfGraph(matrix);

    // Output the DFS result
    cout << "DFS Traversal of the graph: ";
    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
