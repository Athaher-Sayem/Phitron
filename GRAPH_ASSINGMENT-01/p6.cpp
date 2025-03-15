#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y]);
}

int dfs(int x, int y){
    visited[x][y]=true;
    int count=1;
    for (auto d:directions){
        int nx=x+d.first,ny=y+d.second;
        if (isValid(nx,ny)){
            count += dfs(nx, ny);
        }
    }
    return count; 
}

vector<int> countRooms(){
    vector<int> roomCounts;
    memset(visited,false,sizeof(visited));

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                roomCounts.push_back(dfs(i,j)); 
            }
        }
    }
    return roomCounts;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> result=countRooms();
    
    if (result.empty()) {
        cout<<"0"<<endl; 
    } else {
        sort(result.begin(),result.end());
        for (int rooms:result) {
            cout<<rooms<<" ";
        }
        cout<<endl;
    }
}
