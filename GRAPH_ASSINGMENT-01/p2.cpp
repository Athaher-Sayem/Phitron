#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];

int main() {
    int n,e;
    cin>>n>>e;



    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin>>q;

    while(q--){
        int c;
        cin>>c;
        vector<int> li;

        if(adj[c].empty())
            cout <<"-1"<<endl; 
        else {
            sort(adj[c].rbegin(),adj[c].rend());
            for(int x:adj[c]){
                 li.push_back(x);
            }
            for(int y:li) cout<<y<<" ";
                cout<<endl;            
        }
     
    }
    

}
