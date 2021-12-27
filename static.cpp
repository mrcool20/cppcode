#include<bits/stdc++.h>
using namespace std;


class MyClass{

public:
  static int count;

  static int printCount(){
      return count;
  }

};

int MyClass :: count = 0;


int main(){

MyClass obj;
cout<<obj.count<<endl;
int ans =  MyClass :: printCount();

cout<<ans;

}

