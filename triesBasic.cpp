#include<iostream>
#include<vector>
using namespace std;

class Trie{

public:

class Node{

public:
int wordEnd=0;
vector<Node*>childs;

Node(){
this->wordEnd=0;
this->childs.assign(26,NULL);
}

};

Node* root=NULL;
Trie() {
        root=new Node();
    }



void insert(string word){
    int n=word.length();
    Node* curr=root;
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
      if(curr->childs[idx]==NULL){
         curr->childs[idx]=new Node();
         curr=curr->childs[idx];
      }
    }
    curr->wordEnd++;
}

bool search(string word){
    int n=word.length();
    Node* curr=root;
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
        if(curr->childs[idx]==NULL) return false;
        curr=curr->childs[idx];
    }
    if(curr->wordEnd!=0){
        return true;
    }

}

bool startsWith(string prefix) {
    int n=prefix.length();
    Node *curr=root;
    for(int i=0;i<n;i++){
        int idx=prefix[i]-'a';
     if(curr->childs[idx]==NULL) return false;
      curr=curr->childs[idx];
    }   
    return true;     
}

};

int main(){
 
  Trie* obj = new Trie();
  obj->insert("apple");
  bool param_2 = obj->search("apple");
  bool param_3 = obj->startsWith("app");
   
  cout<<param_2<<endl;
  cout<<param_3<<endl;
  cout<<obj->startsWith("mo");

}


