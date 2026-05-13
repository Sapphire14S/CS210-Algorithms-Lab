#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position {
    int x;
    int y;
};

int main() {
    int n;
    cin >> n;

    int startX, startY;
    int targetX, targetY;

    cin >> startX >> startY;
    cin >> targetX >> targetY;

    vector<vector<int>> dist(n, vector<int>(n, -1));

    queue<Position> q;

    q.push({startX, startY});
    dist[startX][startY] = 0;

    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (!q.empty()) {

        Position current = q.front();
        q.pop();

        if (current.x == targetX && current.y == targetY) {
            cout << dist[current.x][current.y] << endl;
            return 0;
        }

        for (int d = 0; d < 8; d++) {

            int nx = current.x + dx[d];
            int ny = current.y + dy[d];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < n &&
                dist[nx][ny] == -1) {

                dist[nx][ny] = dist[current.x][current.y] + 1;

                q.push({nx, ny});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}