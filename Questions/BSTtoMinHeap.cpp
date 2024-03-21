#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node* root , vector<int>& elements){
    if(root == NULL){
        return ;
    }
    inOrder(root->left,elements);
    // cout<<root->data<<" ";
    elements.push_back(root->data);
    inOrder(root->right,elements);
}


void fillPreorder(Node* root, int index){
    root->data = inOrder(index++);
    fillPreorder(root->left, inorder , index)
}
int main(){
    Node* p = new Node(4);                         
    p->left = new Node(2);                         
    p->right = new Node(6);  

    p->left->left = new Node(1);
    p->left->right = new Node(3);

    p->right->left = new Node(5);
    p->right->right = new Node(7);                       

    inOrder(p);  


    
    return 0;
}
