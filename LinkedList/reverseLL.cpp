#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    if(head==NULL){
        cout << "List is empty "<< endl;
        return ;
    }
    Node *temp = head;

    while(temp!=NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}


int main(){
    Node* p1 = new Node(1);
    Node* p2 = new Node(2);
    Node* p3 = new Node(3);

    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;
    
    cout<<"Before reversing "<<endl;
    print(p1);

    p1 = reverseLL(p1);

    cout<<"After reversing "<<endl;
    print(p1);
    return 0;
}