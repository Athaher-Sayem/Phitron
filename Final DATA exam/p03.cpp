#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        string x;
        getline(cin,x);
        stringstream s(x);
        string word;

        unordered_map<string,int> mp;

        string maxword;
        int count=0;
        
        while(s>>word){
            mp[word]++;
            if (mp[word] > count) {
                maxword = word;
                count = mp[word];
            }
        }

        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<" "<<it->second<<endl;
        // }

        // for(auto it:mp){
        //     if(it.second>count){
        //         maxword=it.first;
        //         count=it.second;
        //     }

        // }

        cout<<maxword<<" "<<count<<endl;

    }
    
    

	

}
