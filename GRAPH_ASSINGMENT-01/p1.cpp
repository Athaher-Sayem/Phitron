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
    }

    int q;
    cin>>q;

    while(q--){
        int c,d;
        cin>>c>>d;
bool found=false;
        for(int x:adj[c]){
            if(x == d || c==d) {
               found=true;
               break;
            }
        }
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
