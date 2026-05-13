#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node,
         int parent,
         const vector<vector<int>>& graph,
         vector<bool>& visited,
         vector<int>& discovery,
         vector<int>& low,
         vector<bool>& articulation,
         vector<pair<int, int>>& bridges,
         int& timer) {

    visited[node] = true;

    discovery[node] = low[node] = timer++;

    int children = 0;

    for (int neighbor : graph[node]) {

        if (neighbor == parent) {
            continue;
        }

        if (!visited[neighbor]) {

            children++;

            dfs(neighbor,
                node,
                graph,
                visited,
                discovery,
                low,
                articulation,
                bridges,
                timer);

            low[node] = min(low[node], low[neighbor]);

            if (parent != -1 && low[neighbor] >= discovery[node]) {
                articulation[node] = true;
            }

            if (low[neighbor] > discovery[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            low[node] = min(low[node], discovery[neighbor]);
        }
    }

    if (parent == -1 && children > 1) {
        articulation[node] = true;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> discovery(n);
    vector<int> low(n);
    vector<bool> articulation(n, false);

    vector<pair<int, int>> bridges;

    int timer = 0;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            dfs(i,
                -1,
                graph,
                visited,
                discovery,
                low,
                articulation,
                bridges,
                timer);
        }
    }

    cout << "Articulation Points: ";

    for (int i = 0; i < n; i++) {
        if (articulation[i]) {
            cout << i << " ";
        }
    }

    cout << endl;

    cout << "Bridges:" << endl;

    for (const auto& bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}