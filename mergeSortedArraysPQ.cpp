#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Merge two sorted arrays using Priority queue

void merge(int A[],int B[],int n,int m){
 // Min Priority Queue
 //priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  

//  pq.push({A[0],{0,0}});
//  pq.push({B[0],{0,1}});
 
  vector<int>ans;
//  int i=0;
//  while(i< min(n,m)){
//   pair<int,pair<int,int>> topPair = pq.top();
//   int ele = topPair.first;
//   int indx = topPair.second.first;
//   int arr = topPair.second.first; 
//   ans.push_back(ele);
//   pq.pop();
//   if(arr == 0){ 
//     pq.push({A[indx+1],{indx+1,0}});
//     i = indx+1;
//   }
//   else{
//        pq.push({B[indx+1],{indx+1,1}});
//        i=indx+1;
//   } 
//  }
 
//  while(i<n){
//      ans.push_back(A[i]);
//      i++;
//  }

//  while(i<m){
//      ans.push_back(B[i]);
//      i++;
//  }
 priority_queue<int,vector<int>,greater<int>> pq;
 for(int i=0;i<n;i++) pq.push(A[i]); 
 for(int i=0;i<m;i++) pq.push(B[i]);

 while(!pq.empty()){
     ans.push_back(pq.top());
     pq.pop();
 } 

 for(int ele: ans) cout<<ele<<" ";
}
// Merge K Sorted Arrays
vector<int> mergeKSortedArrays(vector<vector<int>> arrays,int k){

 vector<int> finalSortedArray;
 priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
 for(int i=0;i<k;i++){
  //{element,array, idx} 
   pq.push({arrays[i][0],i,0});
 }
 
 while(!pq.empty()){
 vector<int> minElement = pq.top(); 
 pq.pop();
 finalSortedArray.push_back(minElement[0]);
 
 int arrIdx = minElement[1];   
 int idx = minElement[2];
 
 if(idx+1<arrays[arrIdx].size()){
   pq.push({arrays[arrIdx][idx+1],arrIdx,idx+1});
 } 

}

return finalSortedArray;

}



int main(){

    int A[] = { 5, 6, 8 };
    int B[] = { 4, 7, 8 };
 
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
                 
    // Function call
    merge(A, B, N, M);


}

