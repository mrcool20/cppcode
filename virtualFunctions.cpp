#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Base{

public:

 virtual void display(int x=0){
     cout<<"Base Class";
 } 

};

class Derived : public Base{

public:

 void display(int x=10){
     
     cout<<x<<endl;
     cout<<"Derived Class";
 }

};


int main(){

 Derived d;

 Base* bp = &d;

 bp->display(); 

}