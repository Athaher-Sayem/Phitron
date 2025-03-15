#include <bits/stdc++.h>
using namespace std;

int bsearch(int size,long long target,long long ar[]){
   for (int i=0;i<size;i++){
        if (ar[i]==target) return i;
    }
    return -1;
}



int main() {
     int n;
     cin>>n;
    long long ar[n];
     for(int i=0;i<n;i++){
        cin>>ar[i];
     }

    long long target;
     cin>>target;

     cout<<bsearch(n,target,ar)<<endl;
}
