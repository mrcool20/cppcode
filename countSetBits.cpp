#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){

  
  int count =0;

  while(n){
    
    if(n & 1) count++;
    
    n = n>>1;

   
  }
   return count;
}

int main(){

   int n = 7;
   cout<<countSetBits(n); 
}