#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Singleton{

 static Singleton* s;
 int data; 
  
  private:

  Singleton(){
      data = 0;

  } 
 
  public:
  static Singleton* getInstance(){
     if(!s){
         s= new Singleton();
     }
     return s;
  }

  void updateData(int data){
    this->data = data;
  }

  int getData(){
      return data;
  }


};
Singleton *Singleton::s = 0;

int main(){
   Singleton *st = st->getInstance();
   cout << st->getData() << endl;
   st->updateData(100);
   cout << st->getData() << endl;
   return 0;
}

