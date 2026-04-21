#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int grid[105][105];
bool visited[105][105];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
    visited[x][y] = true;
    int sum = grid[x][y];
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0 && !visited[nx][ny]) {
            sum += dfs(nx, ny);
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> m >> n)) return 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int max_fish = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                max_fish = max(max_fish, dfs(i, j));
            }
        }
    }

    cout << max_fish << endl;

    return 0;
}
