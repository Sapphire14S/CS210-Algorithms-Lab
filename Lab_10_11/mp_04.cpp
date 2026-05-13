#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

    vector<vector<int>> fireTime(n, vector<int>(m, INT_MAX));

    vector<vector<int>> personTime(n, vector<int>(m, -1));

    queue<Cell> fireQueue;
    queue<Cell> personQueue;

    int startX = -1;
    int startY = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 'F') {

                fireQueue.push({i, j});
                fireTime[i][j] = 0;
            }

            if (grid[i][j] == 'P') {
                startX = i;
                startY = j;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!fireQueue.empty()) {

        Cell current = fireQueue.front();
        fireQueue.pop();

        for (int d = 0; d < 4; d++) {

            int nx = current.x + dx[d];
            int ny = current.y + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny] != '#' &&
                fireTime[nx][ny] == INT_MAX) {

                fireTime[nx][ny] = fireTime[current.x][current.y] + 1;

                fireQueue.push({nx, ny});
            }
        }
    }

    personQueue.push({startX, startY});
    personTime[startX][startY] = 0;

    while (!personQueue.empty()) {

        Cell current = personQueue.front();
        personQueue.pop();

        int x = current.x;
        int y = current.y;

        bool boundary = (x == 0 || x == n - 1 || y == 0 || y == m - 1);

        if (boundary && personTime[x][y] <= fireTime[x][y]) {
            cout << "YES" << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny] != '#' &&
                personTime[nx][ny] == -1) {

                int nextTime = personTime[x][y] + 1;

                if (nextTime < fireTime[nx][ny]) {
                    personTime[nx][ny] = nextTime;
                    personQueue.push({nx, ny});
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}