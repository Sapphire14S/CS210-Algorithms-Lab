#include <iostream>
#include <vector>

using namespace std;

void matrixToAdjList(const vector<vector<int>>& matrix, int n) {
    cout << "Adjacency List:" << endl;

    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 1) {
                cout << j << " ";
            }
        }

        cout << endl;
    }
}

void adjListToMatrix(const vector<vector<int>>& adjList, int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {

        for (int neighbor : adjList[i]) {
            matrix[i][neighbor] = 1;
        }
    }

    cout << "Adjacency Matrix:" << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    matrixToAdjList(matrix, n);

    return 0;
}