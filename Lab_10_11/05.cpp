#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {

    visited[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

vector<vector<int>> transposeGraph(const vector<vector<int>>& graph, int n) {
    vector<vector<int>> transpose(n);

    for (int i = 0; i < n; i++) {

        for (int neighbor : graph[i]) {
            transpose[neighbor].push_back(i);
        }
    }

    return transpose;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    vector<bool> visited(n, false);

    dfs(0, graph, visited);

    for (bool state : visited) {

        if (!state) {
            cout << "Graph is Not Strongly Connected" << endl;
            return 0;
        }
    }

    vector<vector<int>> transpose = transposeGraph(graph, n);

    fill(visited.begin(), visited.end(), false);

    dfs(0, transpose, visited);

    for (bool state : visited) {

        if (!state) {
            cout << "Graph is Not Strongly Connected" << endl;
            return 0;
        }
    }

    cout << "Graph is Strongly Connected" << endl;

    return 0;
}