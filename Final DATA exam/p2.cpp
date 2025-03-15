
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> a , pair<string,int> b){
    if(a.first == b.first) return a.second>b.second;
    return a.first<b.first;   
}


int main() {
   int t;
   cin>>t;
   vector<pair<string,int>> pair;
   while(t--){
        string x;
        int num;
        cin>>x>>num;
        pair.push_back({x,num});
   }
   
   sort(pair.begin(),pair.end(),compare);

    for(auto &p: pair) cout<<p.first<<" "<<p.second<<endl;
    

}
