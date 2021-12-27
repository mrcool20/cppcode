#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{

public:
 int data;
 Node* left;
 Node* right;

 Node(int data){
     this->data = data;
     this->left = NULL;
     this->right = NULL;
 }

};

// Create BST

Node* createBST(vector<int>&arr,int si,int ei){

if(si>ei) return NULL;

int mid = (si+ei)>>1;

Node* root = new Node(arr[mid]);

root->left = createBST(arr,si,mid-1);
root->right = createBST(arr,mid+1,ei);

return root;
}

void inorder(Node* root){

    if(root ==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void secondLargestBST(Node* root,int &count){

 if(root == NULL || count>=2) return ;

 secondLargestBST(root->right,count);

 count++;
 
 if(count == 2){ 
  cout<<root->data;
  return;
 }
 secondLargestBST(root->left,count);

}

Node* prev = NULL;

bool isBST(Node* root){

if(root == NULL) return true;


bool isLeftBST = isBST(root->left);

if(prev->data >=root->data) return false;

prev = root;

return isLeftBST && isBST(root->right);


}



void printTree(Node*root){

    if(root == NULL) return;

    cout<<root->data<<"->";


    if(root->left!=NULL) cout<< root->left->data<<","; 
    else cout<<-1<<",";
   if(root->right!=NULL)cout<< root->right->data<<"," ;
   else cout<<-1;
   cout<<endl;
   printTree(root->left);
   printTree(root->right);    
}

int leftHeight = -1;

void printLeftView(Node* root,int height){

if(root == NULL) return;

if(leftHeight < height) {
   cout<<root->data;
   leftHeight = height;
}

printLeftView(root->left,height+1);
printLeftView(root->right,height+1);

}

 int rightHeight = -1;

void printRightView(TreeNode* root,int height,vector<int>&ans){

if(root == NULL) return;

if(rightHeight < height) {
   ans.push_back(root->val);
   rightHeight = height;
}

printRightView(root->right,height+1,ans);
printRightView(root->left,height+1,ans);

}
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        printRightView(root,0,ans);
        return ans;
    }


Node* prev = NULL;
void printRightViewBFS(Node* root){

queue<Node*> que;
que.push(root);

while(!que.empty()){
   
   int size = que.size();
   while(size--){
   Node* rNode = que.front();
   que.pop();

   if(prev == NULL) cout<<rNode->data;
   prev = rNode;
   if(rvtx->right !=NULL) que.push(root->right);
   if(rvtx->left !=NULL) que.push(root->left); 
   } 
   prev = NULL;
}

}

int main(){

vector<int>arr = {20,30,40,50,60,70,80};

Node* root = createBST(arr,0,arr.size()-1);

printTree(root);
cout<<endl;
inorder(root);
cout<<endl;
int c = 0;
secondLargestBST(root,c);

}