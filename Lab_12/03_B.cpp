#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int findParent(vector<int>& parent, int node) {

    if (parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {

    int pu = findParent(parent, u);
    int pv = findParent(parent, v);

    if (pu == pv) {
        return;
    }

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<Edge> graph(edges);

    for (int i = 0; i < edges; i++) {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }

    sort(graph.begin(), graph.end(), compareEdges);

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    cout << "Edges excluded due to cycle:" << endl;

    for (const Edge& edge : graph) {

        int pu = findParent(parent, edge.u);
        int pv = findParent(parent, edge.v);

        if (pu == pv) {
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
        } else {
            unionSets(parent, rank, edge.u, edge.v);
        }
    }

    return 0;
}