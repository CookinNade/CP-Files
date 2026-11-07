#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+2;
bool yes[N+5];
struct Node{
    int val;
    Node* next;
};
Node* make_node(int v){
    Node* n = new Node;
    n->next = nullptr;
    return n;
}
void push_back(Node *& tail, int v, Node *& head){
    if(tail == nullptr){
        head = make_node(v);
        tail = head;
        return;
    }
    Node *n = make_node(v);
    tail->next = n;
    tail = n;
    return;
}
void find_loop(Node* head){
    for(Node* cur = head; cur!=nullptr; cur = cur->next){
        if(cur->val!=-1 and yes[cur->val]){
            cout<<"LOOP AT "<<cur->val<<'\n';
            return;
        }
        yes[cur->val] = true;
    }
    cout<<"NO LOOP\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        push_back(tail,a,head);
    }
    find_loop(head);   
    return 0;
}