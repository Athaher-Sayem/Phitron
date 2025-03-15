#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;

    set<char> cheek(s.begin(),s.end());

    for(char x:cheek){
        cout<<x;
    }
    cout<<endl;


}
