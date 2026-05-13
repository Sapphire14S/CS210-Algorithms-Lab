#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchMatrix(const vector<vector<int>>& matrix, int n, int target) {
    int row = 0;
    int col = n - 1;

    while (row < n && col >= 0) {

        if (matrix[row][col] == target) {
            return {row, col};
        }

        else if (matrix[row][col] > target) {
            col--;
        }

        else {
            row++;
        }
    }

    return {-1, -1};
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    pair<int, int> result = searchMatrix(matrix, n, target);

    cout << result.first << " " << result.second << endl;

    return 0;
}