#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int,int>> mov={{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{2,1},{1,2},{-1,2}};

int m,n;

bool valid(int i,int j){
    if(i<0 || i>=m || j<0 || j>=n) return false ;
    return true;
}

void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});

    vis[si][sj]=true;
    level[si][sj]= 0;

    while(!q.empty()){
        pair<int,int>  par=q.front();
        q.pop();
        int par_i=par.first;
        int par_j=par.second;

        for(int i=0;i<8;i++){
            int ci=par_i+mov[i].first;
            int cj=par_j+mov[i].second;

            if(valid(ci,cj) && !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j]+1;
            }
        }
    }
}

int main() {
    
   int t;
   cin>>t;

   while (t--)
   {
        cin>>m>>n;

        int si,sj , di,dj;
        cin>>si>>sj>>di>>dj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(si,sj);

        cout << (level[di][dj] == -1 ? -1 : level[di][dj]) << endl;
   }
   


}
