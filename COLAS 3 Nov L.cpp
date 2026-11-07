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
Node* merge_two_list_ascending_order(Node* head1, Node* head2){ 
    /*
        by reference dei nai for ease of implementation
    */ 

    if(head1 == nullptr)return head2;
    if(head2 == nullptr)return head1;
    Node* n;
    Node* cur1 = head1;
    if(head1->val >= head2->val) {
        n = head2;
        head2 = head2->next;
    }
    else {
        n = head1;
        head1 = head1 -> next;
    }
    Node* head = n;
    while(head1!=nullptr and head2!=nullptr){
        if(head1->val >= head2->val) {
            n->next = head2;
            n = n->next;
            head2 = head2->next;
        }
        else {
            n->next = head1;
            n = n->next;
            head1 = head1 -> next;
        }
    }
    while(head1!=nullptr){
        n->next = head1;
        n = n->next;
        head1= head1->next;
    }
    while(head2!=nullptr){
        n->next = head2;
        n = n->next;
        head2 = head2->next;
    }
    return head;
}
void bubble_sort(Node*& head){
    int n = 0;
    for(Node* cur = head; cur!=nullptr;cur=cur->next)n++;
    for(int i = 0;i<n-1;i++){
        Node* cur = head;
        for(int j=0;j<n-1-i;j++){
            if(cur->val > cur->next->val){
                swap(cur->val, cur->next->val);
            }
            cur = cur->next;
        }
    }
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n,m;
    cin>>n>>m;
    int arr1[n];
    for(int i=0;i<n;i++)cin>>arr1[i];
    for(int i=n-1;i>=0;i--)push_front(head1,arr1[i]);
    int arr2[m];
    for(int i=0;i<m;i++)cin>>arr2[i];
    for(int i=m-1;i>=0;i--)push_front(head2,arr2[i]);
    head1 = merge_two_list_ascending_order(head1, head2);
    printall(head1);
    return 0;
}