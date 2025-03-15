#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> dis = {{-1,0},{1,0},{0,-1},{0,1}};
int level[1005][1005];
int n,m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}


void bfs(int si,int sj){
  //  cout<<si<<" "<<sj;

    queue<pair<int,int>> parent;
    parent.push({si,sj});
    visited[si][sj]=true;
    level[si][sj] = 0;

    while(!parent.empty()){
            pair<int,int> root=parent.front();
            parent.pop();
            
            int root_i=root.first;
            int root_j=root.second;

            for(int i=0;i<4;i++){
                int ci=root_i + dis[i].first;
                int cj=root_j + dis[i].second;

                if(valid(ci,cj) && !visited[ci][cj]){
                    parent.push({ci,cj});
                    visited[ci][cj]=true;
                     level[ci][cj] = level[root_i][root_j] + 1;
                }
            }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int si,sj,di,dj;
    cin >>si>>sj>>di>>dj; //source index ... distance to distance index

    memset(visited,false,sizeof(visited));
     memset(level,-1,sizeof(level));

    bfs(si,sj);    

    cout << level[di][dj] << endl;


}
