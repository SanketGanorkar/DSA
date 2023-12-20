#include<bits/stdc++.h>
using namespace std;
    
class Node {
    public :
    int data;
    Node *next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};


// Loop detection method - 1
bool detectLoop(Node* head){
       if(head == NULL){
           return false;
       }
       map<Node* , bool> visited;
       Node* temp = head;
       
       while(temp != NULL){
           //cycle point 
           if(visited[temp] == true){
               return true;
           }
           visited[temp] = true;
           temp = temp->next;
       }
       return false;
}

// Loop detection method - 2  
// FLOYD LOOP DETECTION
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        // we move 1 step forward from slow pointer.
        fast = fast -> next;
        if(fast->next != NULL) {
            // if there is a node after current node ( to which fast is pointing ) or not.
            fast = fast -> next;
        }
        
        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;
}

// Node* getStartingNode(Node* head) {

//     if(head == NULL) 
//         return NULL;

//     Node* intersection = floydDetectLoop(head);

//     if(intersection == NULL){
//         return NULL;
//     }
//     Node* slow = head;

//     while(slow != intersection) {
//         slow = slow -> next;
//         intersection = intersection -> next;
//     }  

//     return slow;

// }

// Node *removeLoop(Node *head)
// {
//     if( head == NULL)
//         return NULL;

//     Node* startOfLoop = getStartingNode(head);

//     if(startOfLoop == NULL)
//         return head;

//     Node* temp = startOfLoop;

//     while(temp -> next != startOfLoop) {
//         temp = temp -> next;
//     } 

//     temp -> next = NULL;
//     return head;
// }

int main(){
    
    // creating head node and other nodes.
    Node *head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);


    // connecting the nodes.
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // Creating the loop
    node5->next = node6;


    if(floydDetectLoop(head)){
        cout<<"Loop detected"<<endl;
    }
    else{
        cout<<"No loop exits"<<endl;
    }
    return 0;
}