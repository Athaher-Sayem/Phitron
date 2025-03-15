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

void dfs(int si,int sj,int di,int dj){
    vis[si][sj]=true;

    
    if (si==di && sj==dj) {
        flag=true;
        return;
    }

    for(int i=0;i<4;i++){
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;

        if(valid(ci,cj) && grid[ci][cj]=='.' && !vis[ci][cj]){
            dfs(ci,cj,di,dj);
        }
    }
}

int main() {
    
    cin>>m>>n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    memset(vis,false,sizeof(vis));

     dfs(si,sj,di,dj);
        

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
