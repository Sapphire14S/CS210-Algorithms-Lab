#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int NEG_INF = -1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> even(n, vector<int>(m, NEG_INF));
    vector<vector<int>> odd(n, vector<int>(m, NEG_INF));

    if (grid[0][0] % 2 == 0) {
        even[0][0] = grid[0][0];
    } else {
        odd[0][0] = grid[0][0];
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            vector<pair<int, int>> prevCells;

            if (i > 0) {
                prevCells.push_back({i - 1, j});
            }

            if (j > 0) {
                prevCells.push_back({i, j - 1});
            }

            for (auto cell : prevCells) {
                int x = cell.first;
                int y = cell.second;

                if (even[x][y] != NEG_INF) {
                    int value = even[x][y] + grid[i][j];

                    if (value % 2 == 0) {
                        even[i][j] = max(even[i][j], value);
                    } else {
                        odd[i][j] = max(odd[i][j], value);
                    }
                }

                if (odd[x][y] != NEG_INF) {
                    int value = odd[x][y] + grid[i][j];

                    if (value % 2 == 0) {
                        even[i][j] = max(even[i][j], value);
                    } else {
                        odd[i][j] = max(odd[i][j], value);
                    }
                }
            }
        }
    }

    if (odd[n - 1][m - 1] == NEG_INF) {
        cout << -1 << endl;
    } else {
        cout << odd[n - 1][m - 1] << endl;
    }

    return 0;
}