#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void nextGreaterSet(string str){
  
  int i=0;
  for( i=str.length()-1;i>=1;i--){
      if(str[i]>str[i-1]) break;
  }
  
  if(i==0) cout<<"Not Possible";

  int x = str[i-1] -'0';
  int idx = i-1;
  int small = i;
  for(int j=i+1;j<str.length();j++){
      if((str[j] - '0')>x && (str[j]-'0')<(str[small])){
          small = j;
      }
  }
  cout<<str<<endl;
  char temp = str[idx]; 
  str[idx] = str[small];
  str[small] = temp;
  cout<<str<<endl;
  sort(str.begin() + idx+1,str.end());

  cout<<str<<endl;
}


int main(){

 string str = "534976";
 nextGreaterSet(str);
}