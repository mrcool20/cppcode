#include <bits/stdc++.h>
using namespace std;

void printKBalancedParenthesis(int left,int right,string ans){

  if(left==0 && right ==0){
      cout<<ans<<endl;
      return;
  }

  if(left > 0){
    printKBalancedParenthesis(left-1,right,ans+"("); 
  }

  if(left < right){
      printKBalancedParenthesis(left,right-1,ans+")");
  }

}



int main(){

    int k=3;
    printKBalancedParenthesis(k,k,"");
}