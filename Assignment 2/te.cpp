#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int ar[n+1];
        memset(ar,0,sizeof(ar));
        ar[1]=true;

        for (int i = 2; i <= n; i++) {
            if(i%2==0 && ar[i/2]) 
                ar[i]=true;
            else if(i-3>=1 && ar[i-3]) 
                ar[i]=true;
        
        }

        if(ar[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    

    }


}
