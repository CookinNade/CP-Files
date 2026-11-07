// Copied from AI

struct Node{
    int val;
    Node* prev;
    Node* next;
};
Node* make_node(int v){
    Node* n = new Node;
    n->val = v;
    n->prev = n; // lone node points to itself both ways
    n->next = n;
    return n;
}
void push_front(Node*& head, int v){
    Node* n = make_node(v);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* tail = head->prev; // O(1), no walking
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    head = n;
}
void push_back(Node*& head, int v){
    Node* n = make_node(v);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* tail = head->prev;
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    // head unchanged
}
void printall(Node* head){
    if(head == nullptr){ cout<<'\n'; return; }
    Node* cur = head;
    do{
        cout<<cur->val<<" ";
        cur = cur->next;
    }while(cur != head);
    cout<<'\n';
}