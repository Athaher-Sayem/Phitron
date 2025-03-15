#include <bits/stdc++.h>
using namespace std;


vector<int> adj_list[100];
bool visited[100];
int level[100];
int par[100];


void BFS(int src){          // O(N+E)
    queue<int> q;
    q.push(src);
    visited[src]=true;
    level[src] = 0;

    while(!q.empty()){
        int parent=q.front();
        q.pop();

        cout<<parent<<" ";

        for(int child : adj_list[parent]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
                level[child]=level[parent]+1;
                par[child] = parent;
            }
        }

    }
    cout<<endl;
}


int main() {
    int n,e;
    cin>>n>>e;

    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(par,-1,sizeof(par));

    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

        int source , distance;
        cin>>source>>distance;

        BFS(source);

    // for(int i=0;i<n;i++){
    //     cout<<i<<"-> "<<level[i]<<endl;
    // }

       // cout<<level[distance]<<endl;

vector<int> path;
    int node = distance;
    
    while(node != -1){
        path.push_back(node);
        node = par[node];
    }

reverse(path.begin(),path.end());
    for(int x:path) cout<<x<<" ";

}
