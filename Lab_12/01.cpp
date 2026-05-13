#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int node) {
    while (parent[node] != node) {
        node = parent[node];
    }

    return node;
}

void unionSets(vector<int>& parent, int u, int v) {

    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);

    parent[parentU] = parentV;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<Edge> graph(edges);

    for (int i = 0; i < edges; ++i) {
        cin >> graph[i].u >> graph[i].v >> graph[i].weight;
    }

    sort(graph.begin(), graph.end(), compareEdges);

    vector<int> parent(vertices);

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    int totalWeight = 0;

    vector<Edge> mstEdges;

    for (const Edge& edge : graph) {

        int parentU = findParent(parent, edge.u);

        int parentV = findParent(parent, edge.v);

        if (parentU != parentV) {

            mstEdges.push_back(edge);
            totalWeight += edge.weight;
            unionSets(parent, edge.u, edge.v);
        }
    }

    cout << "Edges in MST:" << endl;

    for (const Edge& edge : mstEdges) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    cout << "Total Weight: " << totalWeight << endl;

    return 0;
}