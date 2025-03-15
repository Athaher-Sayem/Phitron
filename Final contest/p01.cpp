#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    vector<long long>a(n+1),pre(n+1);
    
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
    return 0;
}
