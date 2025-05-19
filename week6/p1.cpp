#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, graph, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;//v

    vector<vector<int>> graph(n, vector<int>(n));
    
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src, dest;
    cin >> src >> dest;

    
    src--; dest--;

    vector<bool> visited(n, false);

    dfs(src, graph, visited);

    if (visited[dest])
        cout << "Yes Path Exist" << endl;
    else
        cout << "No Such Path Exists" << endl;

    return 0;
}
