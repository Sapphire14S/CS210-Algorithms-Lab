#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<PII>> graph(vertices);

    for (int i = 0; i < edges; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> inMST(vertices, false);

    priority_queue<PII, vector<PII>, greater<PII>> pq;

    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (inMST[node]) {
            continue;
        }

        inMST[node] = true;

        totalWeight += weight;

        for (const auto& neighbor : graph[node]) {

            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!inMST[nextNode]) {
                pq.push({edgeWeight, nextNode});
            }
        }
    }

    cout << "Total Weight of MST: " << totalWeight << endl;

    return 0;
}