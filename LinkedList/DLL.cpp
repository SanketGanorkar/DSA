#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){

    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// gives length of linkedlist.
int getLength(Node* head){
    int len = 0 ;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}   

void insertAtHead(Node* &head , Node* &tail , int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next=head;
        head->prev=temp;
        head = temp;
    }
}

void insertAtTail(Node* &head , Node* &tail , int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail ,int position , int d){
    if(position==1){
        insertAtHead(head , tail , d);
        return;
    }
    Node* temp = new Node(d);
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }    

    //inserting at last postion
    if(temp->next==NULL){
        insertAtTail(head , tail , d);
        return ;
    }

    // creating a node for d
    Node* newnode = new Node(d);

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next=newnode;
    newnode->prev = temp;
    
}

void deleteNode(Node* &head , int position){

    //deleting at first position
    if(position==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next = curr->next;
        curr->next=NULL;

        delete curr;
    }
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<getLength(head)<<endl;
    
    insertAtPosition(head,tail,2,20);
    print(head);

    cout<<head->data<<" "<<tail->data<<endl;
    deleteNode(head , 2);
    print(head);
    
    

    

    return 0;
}