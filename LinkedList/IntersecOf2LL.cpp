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

Node* getIntersectionNode(Node* head1 , Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    int c1 = 0;
    int c2 = 0;

    while(temp1 != NULL){
        c1++;
        temp1 = temp1->next;
    }
    // setting the temp back to head.
    temp1 = head1;

    while(temp2 != NULL){
        c2++;
        temp2 = temp2->next;
    }

    temp2 = head2;

    int diff = abs(c1-c2);
    
    if(c1 > c2){
        for(int i = 0 ; i < diff ; i++){
            temp1 = temp1->next;
        }
    }
    else if(c1 < c2){
        for(int i = 0 ; i < diff ; i++){
            temp2 = temp2->next;
        }
    }
    while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1){
            return temp1;
        }
        else{
            return nullptr;
        }
}

int main(){

    Node* p1 = new Node(1);
    Node* p2 = new Node(2);
    Node* p3 = new Node(3);
    Node* p4 = new Node(4);
    Node* p5 = new Node(5);
    Node* p6 = new Node(6);
    Node* p7 = new Node(7);

    // Create first linked list: 1 -> 2 -> 3 -> 6 -> 7
    p1->next = p2;
    p2->next = p3;
    p3->next = p6;
    p6->next = p7;

    // Create second linked list: 4 -> 5 -> 6 -> 7
    p4->next = p5;
    p5->next = p6;

    Node* intersection = getIntersectionNode(p1,p4);
    if(intersection){
        cout << "Intersection at node with data = " << intersection->data << endl;
    }
    else{
        cout << "No intersection" << endl;
    } 
    return 0;
}