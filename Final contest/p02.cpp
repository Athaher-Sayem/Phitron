#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(int i=0;i<s.size();i+=2){
            char c=s[i];
            int count=s[i+1]-'0';
           
            while(count--){
                cout<<c;
            }
        }
        cout<<endl;
    }
    
   
}
