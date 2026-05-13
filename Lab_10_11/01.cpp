#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {

    visited[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {

    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
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

    int components = 0;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            dfs(i, graph, visited);
            components++;
        }
    }

    cout << "Connected Components: " << components << endl;

    return 0;
}