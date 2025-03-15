#include <bits/stdc++.h>
using namespace std;

bool cheek(string s1,string s2) {
    if(s1.length()!=s2.length()) 
        return false; 
    
    sort(s1.begin(),s1.end());  
    sort(s2.begin(),s2.end());
    return s1==s2;  
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        if(cheek(s1,s2))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
