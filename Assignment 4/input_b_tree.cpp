#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *right;
    
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node *input_binary_tree(){
    int val;
    cin>>val;
    Node *root;
    if(val==-1) return NULL;
    else 
    root=new Node(val);

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *p=q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node *myleft,*myright;
        if(l==-1) myleft=NULL;
        else myleft=new Node(l);
        if(r==-1) myright=NULL;
        else myright=new Node(r);

        p->left=myleft;
        p->right=myright;

        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);

    }

    return root;
}

void print_level_order(Node *root){
    if(root==NULL){
        cout<<"No tree"<<endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *p=q.front();
        q.pop();

        cout<<p->val<<" ";

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}


int main (){

    Node *root=input_binary_tree();
    print_level_order(root);


}