#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int x;
    int y;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<Cell> q;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            bool boundary = (i == 0 || i == n - 1 || j == 0 || j == m - 1);

            if (boundary && grid[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {

        Cell current = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {

            int nx = current.x + dx[d];
            int ny = current.y + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny] == 1 &&
                !visited[nx][ny]) {

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int enclaves = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 1 && !visited[i][j]) {
                enclaves++;
            }
        }
    }

    cout << enclaves << endl;

    return 0;
}