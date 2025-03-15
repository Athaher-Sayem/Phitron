#include <bits/stdc++.h>
using namespace std;

char  grid[1005][1005];
bool vis[1005][1005];
bool flag=false;
vector<pair<int,int>> mov={{1,0},{-1,0},{0,1},{0,-1}};
int m,n;

bool valid(int i,int j){
    if(i<0 || i>=m || j<0 || j>=n) return false ;
    return true;
}

int dfs(int si,int sj){
    vis[si][sj]=true;
    int cnt = 1;

    for(int i=0;i<4;i++){
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;

        if(valid(ci,cj) && grid[ci][cj]=='.' && !vis[ci][cj]){
           cnt +=dfs(ci,cj);
        }
    }
    return cnt;
}

int main() {
    
    cin>>m>>n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
int area=INT_MAX;
    memset(vis,false,sizeof(vis));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
                int cnt=0;
                int result=dfs(i,j);
               area = min(area, result);
               flag = true;
            }
        }
    }
        
if(flag) cout<<area<<endl;
else cout<<"-1"<<endl;



}
