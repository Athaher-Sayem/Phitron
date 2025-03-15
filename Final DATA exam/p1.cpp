#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums.insert(x);
        }
        
        for(int x : nums) cout<<x<< " ";
        cout<<endl;
        
    }
    

	

}
