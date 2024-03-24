#include<bits/stdc++.h>
using namespace std;

class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isTerminal;

    Trienode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }   
};

class Trie{
    public:
    Trienode* root;


    Trie(){
        root = new Trienode('/0');
    }
    void insertUtil(Trienode* root , string word){
        
        // base case - puri string traverse kar li hai
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assumption - all words are in caps
        int index = word[0] - 'A';
        Trienode* child;
        
        // present - aage badh jao
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        
        //absent - new node create kari aur aage badh jao
        else{
             child = new Trienode(word[0]);
             root->children[index] = child;
        }

        // recursion sambhal lega
        insertUtil(root, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
};
int main(){
    return 0;
}
