#include <bits/stdc++.h>
using namespace std;

int main()
{
    // this is always given in question
    vector<vector<int>> matrix = {
        {0, 1, 0, 1, 0}, // Node 0 → 1, 3
        {0, 0, 1, 0, 0}, // Node 1 → 2
        {0, 0, 0, 0, 1}, // Node 2 → 4
        {0, 0, 1, 0, 0}, // Node 3 → 2
        {0, 0, 0, 0, 0}  // Node 4 has no outgoing edges
    };

    // We have to convert this to adjancy list using unorderd_map
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 1)
                adj[i].push_back(j);
        }
    }
    for (int i = 0; i < matrix.size(); ++i)
    {
        cout << "Node " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}