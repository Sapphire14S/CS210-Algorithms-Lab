#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int x;
    int y;
    int wallBroken;
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

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));

    queue<State> q;

    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {

        State current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int broken = current.wallBroken;

        if (x == n - 1 && y == m - 1) {
            cout << dist[x][y][broken] << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m) {

                if (grid[nx][ny] == 0 && dist[nx][ny][broken] == -1) {

                    dist[nx][ny][broken] = dist[x][y][broken] + 1;
                    q.push({nx, ny, broken});
                }

                if (grid[nx][ny] == 1 && broken == 0 && dist[nx][ny][1] == -1) {

                    dist[nx][ny][1] = dist[x][y][0] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}