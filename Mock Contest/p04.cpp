#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> ball(n);
    for(int i=0;i<n;i++){
        cin>>ball[i];
    } 

    sort(ball.rbegin(),ball.rend());

    long long maxball=0;
    int prev=INT_MAX;

    for(int i=0;i<n;i++){
        if(prev>ball[i]){
            maxball+=ball[i];
            prev=ball[i];
        }
        else if(prev>1){
            maxball+=prev-1;
            prev--;
        }
        else break;
    }
    
    cout<<maxball<<endl;

}
