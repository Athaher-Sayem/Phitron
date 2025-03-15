#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];

void DFS(int src){
    cout<<src<<" "<<endl;
    visited[src]=true;

    for(int child: adj[src] ){
        if(!visited[child])
        DFS(child);
    }

}

int main() {
    int n,e;
    cin>>n>>e;

    memset(visited,false,sizeof(visited));

    while(e--){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);

        }


    DFS(0); // cheek that connected all node


}
