#include <bits/stdc++.h>
using namespace std;

int bfs(int node,vector<int> adj[],vector<int> &vis){
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(auto it:adj[n]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return 0;
}

int main() {
     int n,m;
     cin>>n>>m;
     vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n+1,0);
        vector<int> ans;

        int cnt=0;
        for(int i=1;i<=n;i++){
           if(!vis[i]) {
            ans.push_back(i);
            bfs(i,adj,vis),cnt++;

        }
    }
        cout<<cnt-1<<endl;

        for(int i=1;i<ans.size();i++){
            cout<<ans[0]<<" "<<ans[i]<<endl;
        }


    return 0;
        }

