// Copied from AI

struct Node{
    int val;
    Node* next;
};
Node* make_node(int v){
    Node* n = new Node;
    n->val = v;
    n->next = n; // points to itself, so a lone node is already circular
    return n;
}
void push_front(Node*& head, int v){
    Node* n = make_node(v);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* tail = head;
    while(tail->next != head) tail = tail->next; // O(n) to find tail
    n->next = head;
    tail->next = n;
    head = n;
}
void push_back(Node*& head, int v){
    Node* n = make_node(v);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* tail = head;
    while(tail->next != head) tail = tail->next;
    tail->next = n;
    n->next = head;
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