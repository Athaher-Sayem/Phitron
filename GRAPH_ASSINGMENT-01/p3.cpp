#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
pair<int, int> start, destination;

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visited[i][j]);
}

bool bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x==destination.first && y==destination.second)
            return true; 
        for (auto d : dis) {
            int nx =x + d.first, ny = y + d.second;
            if (valid(nx, ny)) {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    return false; 
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start={i,j};
            if (grid[i][j] == 'B') destination={i,j};
        }
    }

    memset(visited, false, sizeof(visited));

    cout<<(bfs(start.first, start.second) ? "YES" : "NO")<<endl;
}
