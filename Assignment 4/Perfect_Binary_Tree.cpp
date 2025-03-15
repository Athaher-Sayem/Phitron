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

    bool perfect_binary_tree(Node *root){
        if(root==NULL) return true;
        if(root->left==NULL && root->right!=NULL || root->left!=NULL && root->right==NULL){
            
            return false;
        }

        bool left_ok= perfect_binary_tree(root->left);
    bool right_ok=  perfect_binary_tree(root->right);
        
        return left_ok && right_ok;
    }

    int main() {
        Node *root = input_tree();
    if( perfect_binary_tree(root))
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    } 
