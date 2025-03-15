#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        long long sum=0;

        for(int i=0;i<n-2;i++){
            long long num;
            cin>>num;
            sum+=num;
        }

       long long presum;
        cin>>presum;

        long long sub=presum-sum;

        if(sub<0){
            cout<<0<<endl;
        }
        else{
            cout<<sub+1<<endl;
        }
    }
    
   
}
