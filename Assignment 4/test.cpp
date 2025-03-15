#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree() {
    int val;
    cin >> val;

    Node *root;
    if (val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        // get out
        Node *p = q.front();
        q.pop();

        // work on that node
        int l, r;
        cin >> l >> r;
        Node *myleft, *myright;
        if (l == -1) myleft = NULL;
        else myleft = new Node(l);

        if (r == -1) myright = NULL;
        else myright = new Node(r);

        p->left = myleft;
        p->right = myright;

        // push children
        if (p->left) 
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
}

void print_outer_left(Node *root,vector<int> &store){
    if(root==NULL) return ;
        store.push_back(root->val);
    if(root->left)
     print_outer_left(root->left,store);
    
}


void print_outer_right(Node *root,vector<int> &store){
  if(root==NULL) return ;
       
    if(root->right)
     print_outer_right(root->right,store);
      
      store.push_back(root->val);

}


int main() {
    Node *root = input_tree();
    vector<int> store;
    print_outer_left(root,store);
  //  cout<<root->val<<" ";
    print_outer_right(root,store);

    for(int x:store) cout<<x<<" ";
}
