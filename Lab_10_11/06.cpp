#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void fillOrder(int node, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {

    visited[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            fillOrder(neighbor, graph, visited, st);
        }
    }

    st.push(node);
}

void dfsTranspose(int node, const vector<vector<int>>& transpose, vector<bool>& visited) {

    visited[node] = true;

    cout << node << " ";

    for (int neighbor : transpose[node]) {

        if (!visited[neighbor]) {
            dfsTranspose(neighbor, transpose, visited);
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

    stack<int> st;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            fillOrder(i, graph, visited, st);
        }
    }

    vector<vector<int>> transpose = transposeGraph(graph, n);

    fill(visited.begin(), visited.end(), false);

    cout << "Strongly Connected Components:" << endl;

    while (!st.empty()) {

        int node = st.top();
        st.pop();

        if (!visited[node]) {
            dfsTranspose(node, transpose, visited);
            cout << endl;
        }
    }

    return 0;
}