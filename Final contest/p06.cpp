#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        string s,x;
        cin>>s>>x;

        long long ch1=0,ch2=0,ch3=0;

        for(char c:s){
            if(c==x[2])
                ch3+=ch2;
            if(c==x[1])
                ch2+=ch1;
            if(c==x[0])
                ch1++;
        }

        cout<<ch3<<endl;
    }

   
}
