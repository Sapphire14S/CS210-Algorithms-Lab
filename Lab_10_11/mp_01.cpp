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

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<Cell> q;

    if (grid[0][0] == '#') {
        cout << -1 << endl;
        return 0;
    }

    q.push({0, 0});
    dist[0][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {

        Cell current = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {

            int nx = current.x + dx[d];
            int ny = current.y + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny] == '.' &&
                dist[nx][ny] == -1) {

                dist[nx][ny] = dist[current.x][current.y] + 1;

                q.push({nx, ny});
            }
        }
    }

    cout << dist[n - 1][m - 1] << endl;

    return 0;
}