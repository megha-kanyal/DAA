#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

// Function to perform Dijkstra's algorithm
void dijkstra(int start, int target, unordered_map<int, vector<pii>>& graph, int n) {
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == target) break;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (curr_dist + weight < dist[v]) {
                dist[v] = curr_dist + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[target] == INT_MAX) {
        cout << "No path from " << start << " to " << target << endl;
        return;
    }

    // Reconstruct path
    stack<int> path;
    int curr = target;
    while (curr != -1) {
        path.push(curr);
        curr = parent[curr];
    }

    cout << "Shortest distance from " << start << " to " << target << " is " << dist[target] << endl;
    cout << "Path: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int n = 6; // total number of nodes
    unordered_map<int, vector<pii>> graph;

    // Sample undirected weighted graph
    graph[1] = {{2, 2}, {3, 4}};
    graph[2] = {{1, 2}, {3, 1}, {4, 7}};
    graph[3] = {{1, 4}, {2, 1}, {5, 3}};
    graph[4] = {{2, 7}, {5, 2}, {6, 1}};
    graph[5] = {{3, 3}, {4, 2}, {6, 5}};
    graph[6] = {{4, 1}, {5, 5}};

    int akshayHouse = 6;

    vector<int> friends = {1, 2, 3, 4, 5};

    for (int friendLoc : friends) {
        dijkstra(friendLoc, akshayHouse, graph, n);
    }

    return 0;
}
