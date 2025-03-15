#include <bits/stdc++.h>
using namespace std;

char matrix[1005][1005];
bool vis[1005][1005];
int n,m;
vector<pair<int,int>> mov={{1,0},{-1,0},{0,-1},{0,1}};

bool valid(int i,int j){
    if (i<0 || i>=n || j<0 || j>=m) return false;
    return true;

}

void dfs(int si,int sj, char matrix[1005][1005]){
    vis[si][sj]=true;
    for(int i=0;i<4;i++){
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;

        if(valid(ci,cj) && !vis[ci][cj] && matrix[ci][cj]=='.')
            dfs(ci,cj,matrix);
    }
}

int main() {
     int cnt=0;
    cin>>n>>m;
    
    memset(vis,false,sizeof(false));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cin>>matrix[i][j];
        }
    } 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(matrix[i][j]=='.' && !vis[i][j])
                   {
                    cnt++;
                    dfs(i,j,matrix);     
                } 
        }
    } 

    cout<<cnt<<endl;

}
