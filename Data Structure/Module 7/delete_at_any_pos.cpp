#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail,int val)
{
    Node *newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_linked_list(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

void delete_tail(Node *head)
{
    Node *tmp = head;
    while(tmp->next->next != NULL)
    {
        tmp = tmp ->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = NULL;
    delete deleteNode;
    cout<<"Tail node deleted"<<endl;
}


void delete_at_any_pos(Node* head, int idx)
{
    Node* tmp = head;
    for(int i=0;i<idx;i++)
    {
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head,tail,val);
    }
    print_linked_list(head);
    delete_tail(head);
    print_linked_list(head);
    return 0;
}