#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topologicalDFS(int node, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {

    visited[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            topologicalDFS(neighbor, graph, visited, st);
        }
    }

    st.push(node);
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

    stack<int> st;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            topologicalDFS(i, graph, visited, st);
        }
    }

    cout << "Topological Order: ";

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    return 0;
}