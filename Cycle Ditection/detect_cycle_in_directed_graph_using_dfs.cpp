#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[105];
bool pathvis[105];
bool cycle=false;

void dfs(int src){
    vis[src]=true;
    pathvis[src]=true;

    for(int child: adj_list[src]){
        if(vis[child] && pathvis[true])
            cycle=true;
        if(!vis[child]){
            dfs(child);
        }
    }

    //return 
    pathvis[src]=false;

}


int main() {
    int n,e;
     cin>>n>>e;
    
for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    adj_list[a].push_back(b);
}

memset(pathvis,false,sizeof(pathvis));
memset(vis,false,sizeof(vis));


for(int i=0;i<n;i++){
    if(!vis[i])
    dfs(i);
}

    if(cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n"; 

}
