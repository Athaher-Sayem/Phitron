#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
vector<pair<int,int>> mov={{0,1},{0,-1},{-1,0},{1,0}};
int m, n;

pair<int,int> parent[1005][1005];

bool valid(int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

void bfs(int si, int sj) {
    vis[si][sj] = true;
    level[si][sj] = 0;
    
    queue<pair<int,int>> q;
    q.push({si, sj});
    
    while(!q.empty()){
        pair<int,int> par = q.front();
        q.pop();
        
        int par_i = par.first;
        int par_j = par.second;
        
        for(auto move : mov){
            int ci = par_i + move.first;
            int cj = par_j + move.second;
            
            if(valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj]=='.' || grid[ci][cj]=='R' || grid[ci][cj]=='D')){
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}

int main() {
    cin >> m >> n;
    int si, sj, di, dj;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'D'){
                di = i;
                dj = j;
            }
        }
    }
    
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    memset(level, -1, sizeof(level));
    
    bfs(si, sj); 
    
    if(level[di][dj] == -1) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    
    int x = di, y = dj;
    while (make_pair(x, y) != make_pair(si, sj)) {
        pair<int, int> par = parent[x][y];
        if(grid[par.first][par.second] == 'R')
            break;
        grid[par.first][par.second] = 'X';
        x = par.first;
        y = par.second;
    }
    
    for (int i=0;i< m; i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
