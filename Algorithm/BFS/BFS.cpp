#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool visited[100];

void BFS(int src){          // O(N+E)
    queue<int> q;
    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        int parent=q.front();
        q.pop();

        cout<<parent<<" ";

        for(int child : adj_list[parent]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
            }
        }

    }
}


int main() {
    int n,e;
    cin>>n>>e;

    memset(visited,false,sizeof(visited));

    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    BFS(0);


}
