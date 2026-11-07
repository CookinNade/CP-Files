//Codes copied from AI

struct Node{
    int val;
    Node* prev;
    Node* next;
};
Node* make_node(int v){
    Node* n = new Node;
    n->val = v;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}
void push_front(Node*& head, int v){
    Node* n = make_node(v);
    n->next = head;
    if(head != nullptr) head->prev = n;
    head = n;
}
void push_back(Node*& head, int v){
    Node* n = make_node(v);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* cur = head;
    while(cur->next != nullptr) cur = cur->next;
    cur->next = n;
    n->prev = cur;
}
void printall(Node* head){
    for(Node* cur = head; cur != nullptr; cur = cur->next) cout<<cur->val<<" ";
    cout<<'\n';
}