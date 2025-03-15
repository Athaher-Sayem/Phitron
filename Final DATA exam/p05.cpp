
#include <bits/stdc++.h>
using namespace std;

class Student{
    public :
     string name;
     int roll;
     int mark;

     Student(string name,int roll,int mark){
        this->name=name;
        this->mark=mark;
        this->roll=roll;
     }


     bool operator<(const Student &other) const{
        if (mark!= other.mark)
            return mark > other.mark;  
          return roll < other.roll;       
    }


    
};


int main() {
  int n;
  cin>>n;

  set<Student> cheek;
  for(int i=0;i<n;i++){
    string name;
    int roll,mark;
    cin>>name>>roll>>mark;
    cheek.insert(Student(name,roll,mark));
  }

    int q;
    cin>>q;
    while(q--){
        int c;
        cin>>c;

        if(c==2){
            if(cheek.empty()){
                cout<<"Empty"<<endl;
            }
            else {
                cheek.erase(cheek.begin());
                if(cheek.empty()){
                cout<<"Empty"<<endl;
                 }
                 else {
                    auto top=*cheek.begin();
                    cout<<top.name<< " "<<top.roll<<" "<<top.mark<<endl;
                 }
            }
        }

        else if(c==0){
            string name;
            int roll,mark;
            cin>>name>>roll>>mark;
            cheek.insert(Student(name,roll,mark));

              auto top=*cheek.begin();
                    cout<<top.name<< " "<<top.roll<<" "<<top.mark<<endl;

        }


        else if(c==1){
            if(cheek.empty()){
                cout<<"Empty"<<endl;
            }
            else {
                 auto top=*cheek.begin();
                    cout<<top.name<< " "<<top.roll<<" "<<top.mark<<endl;
            }

        }
            

}
}