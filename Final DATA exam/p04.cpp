
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  priority_queue<int, vector<int>, greater<int>> num;

  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    num.push(x);
  }
  int q;
  cin>>q;
  while(q--){
    int c;
    cin>>c;
    if(c==2){
        if(num.empty()) {
            cout<<"Empty"<<endl;
        }
         else {
            num.pop();  
            if(num.empty()) {
            cout<<"Empty"<<endl;
         } 
           else cout<<num.top()<<endl;
            
           
         }
    }
    else if(c==0){
        int nxt;
        cin>>nxt;
        num.push(nxt);
        cout<<num.top()<<endl;
    }
   else  if(c==1) {
          if(num.empty()) {
              cout<<"Empty"<<endl;
          }
            else cout<<num.top()<<endl;
  }

  }

}
