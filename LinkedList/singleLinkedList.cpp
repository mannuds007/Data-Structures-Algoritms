#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void insertAtHead(Node* &head, int d) {
    // Create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp; 
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last position
    if ( temp->next == NULL) {
        insertAtTail(tail, d);
    }
    else{
        Node* newnode = new Node(d);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp= head;
        head=head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    Node* prev=NULL;
    Node* curr = head;
    int cnt=1;
    while (cnt <pos) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next=curr->next;
    if(curr->next==NULL) tail = prev;
    else curr->next=NULL;
    delete curr;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a new node
    Node* node1 = new Node(10);
    
    // Head and tail pointing to node1
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    
    insertAtHead(head, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);
    
    insertAtPosition(head, tail, 4, 4);
    print(head);

    deleteNode(head, tail, 4);
    print(head);
    
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    
    return 0;
}
