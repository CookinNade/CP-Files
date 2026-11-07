#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
struct Node{
    int val;
    Node* next;
};
Node* make_node(int v){
    Node* n = new Node; // new always return a pointer. new allocates memory in heap;
    n->val = v;
    n->next = nullptr;
    return n;
}
void push_front(Node*& head, int v){
    Node* n = make_node(v);
    n->next = head;
    head = n;
}
void push_back(Node*& head, int v){
    if(head == nullptr){
        head = make_node(v);
        return;
    }
    Node* cur = head;

    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = make_node(v);
    return;
}
bool remove_value(Node*&head, int v){
    if(head == nullptr)return false;
    Node* cur = head;
    if(head->val == v){
        Node* t = head;
        head = head->next;
        delete t;
        return true;
    }
    while(cur->next != nullptr and cur->next->val!=v)cur = cur->next;
    if(cur->next == nullptr)return false;
    Node* rmv = cur->next;
    cur->next = rmv->next;
    delete rmv;
    return true;
}
void rev(Node*& head){
    Node* prev = nullptr;
    Node* cur = head;
    while(cur!=nullptr){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    return;
}
void insert_at_x(Node*&head, int val, int x){
    Node* cur = head;
    if(x == 1){
        Node* n = make_node(val);
        n->next = head;
        head = n;
        return;
    }
    if(head == nullptr)return;
    for(int i=0;i<x-2;i++){
        cur = cur->next;
        if(cur == nullptr)return;
    }
    Node* n = make_node(val);
    n->next = cur->next;
    cur->next = n;
    return;
}
void printall(Node*& head){
    for(Node* cur = head; cur!=nullptr; cur = cur->next){
        cout<<cur->val<<" ";
    }
    cout<<'\n';
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Node* head = nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        // cout<<s<<endl;
        if(s == "FRONT"){
            int x;
            cin>>x;
            push_front(head, x);
        }
        if(s == "BACK"){
            int x;
            cin>>x;
            push_back(head, x);
        }
        if(s == "REMOVE"){
            int x;
            cin>>x;
            bool yes = remove_value(head, x);
            if(yes) cout<<"OK\n";
            else cout<<"NOT FOUND\n";
        }
        if(s == "PRINT"){
            if(head == nullptr){
                cout<<"EMPTY\n";
                continue;
            }
            printall(head);
        }

    }

    
    return 0;
}