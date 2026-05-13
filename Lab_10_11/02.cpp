#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(const vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {

        if (color[start] != -1) {
            continue;
        }

        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {

                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
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

    if (isBipartite(graph, n)) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is Not Bipartite" << endl;
    }

    return 0;
}