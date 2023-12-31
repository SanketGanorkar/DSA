#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //Destructor 
    ~Node(){
        //Memory free
        int value = this->data;
        if(this->next=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }


};

void insertAtHead(Node* &head , int d){
    // Here temp is same as newnode.
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail , int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail=temp;
}

void insertAtPosition(Node* &tail,Node* &head ,int position , int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt=1;

    while(cnt<=position-1){
        temp=temp->next;
        cnt++;
    }
    //inserting at last position.
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void deleteNode(int position , Node* &head){
    if(position==1){
        Node* temp = head;
        head = head->next;
        //Now temp is pointing to 1st node , so that node won't store the address of the next node.
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr= head;
        Node* prev= NULL;

        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        delete curr;
         

    }
}

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

int main() {
   // created a new node
   Node *node1 = new Node(10);
   Node *head = node1;
   Node *tail = node1;
   print(head);
   insertAtHead(head,12);
   print(head);
   insertAtTail(tail,15);    
   print(head);
//    deleteNode(1,head);
//    print(head);
   insertAtPosition(tail, head,1,22);
   print(head);

   
   insertAtPosition(tail, head,5,24);
   print(head);

   cout<<"head is "<<head->data<<endl;
   cout<<"tail is "<<tail->data<<endl;
   return 0;
}