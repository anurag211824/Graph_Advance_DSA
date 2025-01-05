#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(unordered_map<int, vector<int>> &adjacencyList, int u, vector<bool> &visited)
    {
        if (visited[u])
            return;
        visited[u] = true;
        for (auto &v : adjacencyList[u])
        {
            if (!visited[v])
            {
                dfs(adjacencyList, v, visited);
            }
        }
    }

    int numProvinces(vector<vector<int>> mat, int V)
    {
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    int u = i + 1; // Adjusting index to 1-based
                    int v = j + 1; // Adjusting index to 1-based
                    adjList[u].push_back(v);
                }
            }
        }

        vector<bool> visited(mat.size() + 1, false);
        int count = 0;

        for (int u = 1; u < mat.size() + 1; u++)
        {
            if (!visited[u])
            {
                dfs(adjList, u, visited);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    // Example adjacency matrix (connected components)
    vector<vector<int>> mat = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    int V = 3; // Number of vertices in the graph

    // Call the function to count provinces
    int numOfProvinces = solution.numProvinces(mat, V);

    // Output the result
    cout << "Number of Provinces: " << numOfProvinces << endl;

    return 0;
}
