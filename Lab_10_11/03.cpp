#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int parent, const vector<vector<int>>& graph, vector<bool>& visited) {

    visited[node] = true;

    for (int neighbor : graph[node]) {
        
        if (!visited[neighbor]) {

            if (dfs(neighbor, node, graph, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
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

    bool hasCycle = false;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            if (dfs(i, -1, graph, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}