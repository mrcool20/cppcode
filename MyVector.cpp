#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T> class MyVector{

 T *arr = NULL;
 int capacity = 0;
 int currSize =0;

 public:

 MyVector(){
    arr = new T[1];
    capacity = 1;
    currSize = 0;
 }

 void push_Back(int data){

     if(currSize == capacity){
       T* temp = new T[2*capacity];
       capacity = 2*capacity; 
       for(int i=0;i<capacity;i++){
           temp[i] = arr[i];
       }
       delete []arr;
       arr = temp;
       arr[currSize] = data;
       currSize++;  
     }else{
         arr[currSize] = data;
         currSize++;
     }
 }

 void pop(){
     currSize--;
 }

 int size(){
     return currSize;
 }

 int getCapacity(){
     return capacity; 
 }

 void display(){
     for(int i=0;i<currSize;i++){
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }

 void push(int data,int idx){

     if(idx>capacity) return;

     else if(idx < currSize) arr[idx] = data;

     else if(idx == capacity) push_Back(data);
     else if(idx >= currSize) { arr[idx] = data; currSize++; }
 }

 int getDataAtIndex(int idx){

     if(idx>=currSize || idx<0) return -1;

     return arr[idx];
 }
 

};


int main(){

MyVector<int> v;

v.push_Back(1);
cout<<v.size()<<endl;
v.push_Back(2);
v.push_Back(3);
cout<<v.getCapacity()<<endl;
v.push_Back(4);
v.display();
v.pop();
v.display();
v.push_Back(5);
v.display();
cout<<v.size()<<endl;
cout<<v.getCapacity()<<endl;
v.push_Back(6);
v.display();
cout<<v.size()<<endl;
cout<<v.getCapacity()<<endl;
v.push(7,5);
v.display();
cout<<v.size()<<endl;
cout<<v.getCapacity()<<endl;
v.push(9,2);
v.display();
cout<<v.size()<<endl;
cout<<v.getCapacity()<<endl;
cout<<v.getDataAtIndex(7);


}


