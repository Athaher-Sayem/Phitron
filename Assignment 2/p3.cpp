#include <bits/stdc++.h>
using namespace std;

int ans(int size,int weight,int we[],int value[]) {
    int dp[size+1][weight+1];
    
    for(int i=0;i<=size;i++) {
        for(int j=0;j<=weight;j++) {
            if(i==0||j==0) dp[i][j]=0;
            
            else if(we[i-1]<=j) dp[i][j]=max(dp[i-1][j],dp[i-1][j-we[i-1]]+value[i-1]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[size][weight];
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int s,w;
        cin>>s>>w;
        int weight[s],value[s];
       
        for(int i=0;i<s;i++) cin>>weight[i];
        for(int i=0;i<s;i++) cin>>value[i];
        
        cout<<ans(s,w,weight,value)<<endl;
    }
    return 0;
}
