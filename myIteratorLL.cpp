#include <bits/stdc++.h>
using namespace std;


template <typename T> class LinkedList{

class Node{

    T data;
    Node* next;
    public:
    Node(T data){
        this->data = data;
        this->next = NULL;
    }

    friend class LinkedList;
};

static  Node* root;

Node* NewNode(T data){
  
   Node* newNode = new Node(data);
   return newNode;
}

Node*& getRootNode(){
    return root;
}

public:

LinkedList<T>(){
    root=NULL;
}

class Iterator{

private:

 Node* currNode;
  
 public: 
 Iterator() : currNode(root){}
 Iterator(Node *node) : currNode(node){}
  
 Iterator& operator=(Node* node){
     this->currNode = node;
     return (*this);
 } 

 //prefix++ overload

 Iterator& operator++(){
   
   if(currNode){
       currNode = currNode->next;
   }

   return *this;
 }

 //postfix overload
 Iterator& operator++(int){
      Iterator iterator = *this;
            ++*this;
            return iterator;
 }

  bool operator!=(const Iterator& iterator)
        {
            return currNode != iterator.currNode;
        }
 
  int operator*()
        {
            return currNode->data;
        }

};

 Iterator begin()
    {
        return Iterator(root);
    }
 
    // End of LInkedList wrapped in Iterator type
    Iterator end()
    {
        return Iterator(NULL);
    }
 
    // Adds data to the end of list
    void push_back(T data);
 
    void Traverse();
 
};

template <typename T>
/*static*/ typename LinkedList<T>::Node* LinkedList<T>::root = NULL;

template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node* pTemp = NewNode(data);
    if (!getRootNode())
    {
        getRootNode() = pTemp;
    }
    else
    {
        Node* pCrawler = getRootNode();
        while (pCrawler->next)
        {
            pCrawler = pCrawler->next;
        }
 
        pCrawler->next = pTemp;
    }
}
 
template <typename T>
void LinkedList<T>::Traverse()
{
    Node* pCrawler = getRootNode();
 
    while (pCrawler)
    {
        cout << pCrawler->data << " ";
        pCrawler = pCrawler->next;
    }
 
    cout << endl;
}

int main()
{
    LinkedList<int> list;
 
    // Add few items to the end of LinkedList
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
 
    cout << "Traversing LinkedList through method" << endl;
    list.Traverse();
 
    cout << "Traversing LinkedList through Iterator" << endl;
    for ( LinkedList<int>::Iterator iterator = list.begin();
            iterator != list.end(); iterator++)
    {
        cout << *iterator << " ";
    }
 
    cout << endl;
 
    return 0;
}


