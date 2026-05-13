#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isDirected = false;

    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] != matrix[j][i]) {
                isDirected = true;
            }

            if (matrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    if (!isDirected) {
        edgeCount /= 2;
    }

    cout << "Graph Type: ";

    if (isDirected) {
        cout << "Directed" << endl;
    } else {
        cout << "Undirected" << endl;
    }

    double threshold = (n * (n - 1)) / 4.0;

    cout << "Density Type: ";

    if (edgeCount > threshold) {
        cout << "Dense" << endl;
    } else {
        cout << "Sparse" << endl;
    }

    return 0;
}