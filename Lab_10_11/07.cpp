#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> bfs(int start, const vector<vector<int>>& graph, int n) {

    vector<int> distance(n, -1);
    queue<int> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {

            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    int farthestNode = start;

    for (int i = 0; i < n; i++) {

        if (distance[i] > distance[farthestNode]) {
            farthestNode = i;
        }
    }

    return {farthestNode, distance[farthestNode]};
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

    pair<int, int> firstBFS = bfs(0, graph, n);

    pair<int, int> secondBFS = bfs(firstBFS.first, graph, n);

    cout << "Diameter of Graph: " << secondBFS.second << endl;

    return 0;
}