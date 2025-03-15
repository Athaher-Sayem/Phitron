#include <bits/stdc++.h>
using namespace std;

int grid[10005][10005];
bool visited[10005][10005];
vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}}; //up down left right
int n,m;

bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>m)
    return false;
return true;
}


void dfs(int source_row,int source_col){
   cout<<source_row<<" " << source_col<<" "<<endl;
    visited[source_row][source_col]=true;

    for(int i=0;i<4;i++){
        int child_row,child_col;
        child_row=source_row+direction[i].first;
        child_col=source_col+direction[i].second;

        if(valid(child_row,child_col) && !visited[child_row][child_col]){
                dfs(child_row,child_col);
        }

       // cout<<child_row<<" "<<child_col<<endl;
    }


}


int main() {
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        cin>>grid[i][j];
        }
    }
    int source_row,source_col;
    cin>>source_row>>source_col;

    memset(visited,false,sizeof(visited));

    dfs(source_row,source_col);



}
