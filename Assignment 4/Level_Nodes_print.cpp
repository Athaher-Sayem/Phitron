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

void print_level_node(Node *root,int target){
        
        if(!root) {
            cout<<"Invalid"<<endl;
            return ;
        }

        queue<Node*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){

            int size=q.size();
            if(level==target){
                for(int i=0;i<size;i++){
                    Node *x=q.front();
                    q.pop();
                    cout<<x->val<<" ";
                }
                cout<<endl;
                return ;
            }

            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            level++;

        }
        cout<<"Invalid"<<endl;
}

int main() {
    Node *root = input_tree();
    int target;
    cin>>target;
    print_level_node(root,target);
    
}
