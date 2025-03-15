#include <bits/stdc++.h>
using namespace std;

const int N = 100005; 

vector<int> adj[N];
int level[N];
bool visited[N];
int par[N];

void bfs(int src){
    queue<int> q;
    
    q.push(src);
    visited[src]=true;
    level[src]=0;

    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(int child: adj[parent]){
            if(!visited[child]){
                q.push(child);
                visited[child]=true;
                level[child]=level[parent]+1;
                par[child] = parent;
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;

     memset(visited, false, sizeof(visited));
     memset(level, -1, sizeof(level));
     memset(par, -1, sizeof(par));

    while(m--){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);    
    }

    bfs(1);
    if (level[n] == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

    cout << level[n] + 1 << endl;
    

    vector<int> path;
    int dis=n;


    while(dis != -1){
        path.push_back(dis);
         dis = par[dis];
    }

    reverse(path.begin(),path.end());
    for(int x:path){
        cout<<x<<" ";
    }
    cout<<endl;
 

}
