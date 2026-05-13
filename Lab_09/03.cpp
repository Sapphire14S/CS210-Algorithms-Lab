#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> transpose(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        transpose[v].push_back(u);
    }

    cout << "Transposed Graph (Adjacency List):" << endl;

    for (int i = 0; i < n; i++) {

        cout << i << ": ";

        for (int neighbor : transpose[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    return 0;
}