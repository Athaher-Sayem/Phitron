#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    unordered_map<int,int> freq;
    vector<int> arr;

    while(t--){
        int x;
        cin>>x;

        if(x==1){
            int num;
            cin>>num;
            arr.push_back(num);
            freq[num]++;
        }
        else if(x==2){
            if(arr.empty()){
                cout<<"empty"<<endl;
                continue;
            }
            
            int maxf=0,maxval=-1;
            for(auto it : freq){
                if(it.second>maxf || (it.second==maxf && it.first>maxval)){
                    maxf=it.second;
                    maxval=it.first;
                }
            }

            cout<<maxval<<endl;

            int r=maxf/2;
            freq[maxval]-=r;

        }
    }

   
}
