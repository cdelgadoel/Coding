#include <iostream>
#include <string>
#include <new> 

using namespace std;

struct Trie{
    struct Node{
        Node *children[26];
        bool isEndOfWord;
    };
    struct Node *getNode() 
    { 
        struct Node *p =  new Node; 
        p -> isEndOfWord = false; 
        for (int i = 0; i < 26; i++) 
            p->children[i] = NULL; 
        return p; 
    } 
    Node* root;
    Trie(){root = getNode();}
    void insert(string key) 
    { 
        Node *it = root; 
        for (int i = 0; i < key.length(); ++i) 
        { 
            int idx = key[i] - 'a'; 
            if (!it->children[idx]) 
                it->children[idx] = getNode(); 
            it = it->children[idx]; 
        } 
        it->isEndOfWord = true; 
    } 
    bool search(string word){
        Node *it = root; 
        for (int i = 0; i < word.length(); ++i) 
        { 
            int idx = word[i] - 'a'; 
            if (!it->children[idx]) return false; 
            it = it->children[idx]; 
        } 
        return it->isEndOfWord;
    }
    void remove(string word){
        Node *it = root; 
        for (int i = 0; i < word.length(); ++i) 
        { 
            int index = word[i] - 'a'; 
            if (!it->children[index]) break;
            it = it->children[index]; 
        } 
        it->isEndOfWord = false; 
    }
};


int main(){
    Trie a; 
    a.insert("hola");
    cout<<a.search("hola")<<endl;
    a.remove("hola");
    cout<<a.search("hola");
    return 0;
}
