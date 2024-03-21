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



    int countNodes(Node* root){
        if(root == NULL){
            return 0;
        }
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    // Checks whether our binary tree is a CBT or not. 
    // CBT matlab first left side of node insertion and then right side of node insertion.
    bool isCBT(Node* root , int i , int nodeCount){
        if(root == NULL){
            return true;
        }
        if( i >= nodeCount){
            return false;
        }
        bool left = isCBT(root , 2*i+1 , nodeCount);
        bool right = isCBT(root , 2*i + 2 , nodeCount);
        return (left && right);    
    }

    bool isMaxHeap(Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        // left node hai par right node nahi
        if(root->right == NULL){
            // root must be greater than left node ( max heap property )
            return (root->data > root->left->data);
        }
        else{
            bool left = isMaxHeap(root->left);
            bool right = isMaxHeap(root->right);    

            if(left && right && ((root->data > root->left->data) && (root->data > root->right->data))){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
int main(){
    Node* p = new Node(4);                         
    p->left = new Node(2);                         
    p->right = new Node(6);  

    p->left->left = new Node(1);
    p->right->right = new Node(3);

    p->right->left = new Node(3);
    p->right->right = new Node(7);                       
                                                  
    
    return 0;
}
