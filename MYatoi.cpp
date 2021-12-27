#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int myatoi(char* str){
    
    int ans = 0;
    int i=0;
    bool isNegative = false;
    if(str[0] == '-'){
      i=1;
    isNegative = true;
    }

    for(int j=i;str[j]!='\0';j++){

        if(str[j]>='0' && str[j]<='9'){
              ans = ans*10 + (str[j]-'0'); 
        }
    }

  return isNegative == true ? (ans*-1) : ans;
}


int main(){

   char str[] = "-102345";
   int a = atoi(str);
   cout<<a<<endl;
   int myAns = myatoi(str);
   cout<<myAns<<endl; 
}