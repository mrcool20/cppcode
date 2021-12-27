#include <bits/stdc++.h>
using namespace std;

class Complex{

 int real;
 int imaginary;

 public:
 Complex(int real,int imaginary){
     this->real = real;
     this->imaginary = imaginary;
 } 

 Complex operator +(Complex & c){
     Complex ans(0,0);
     ans.real = this->real + c.real;
     ans.imaginary = this->imaginary + c.imaginary;

     return ans;

// For global operator
    
   friend Complex operator+(Complex &,Complex &); 

 }

  void Print(){
      cout<< real <<"+i"<< imaginary;
  } 

};

Complex operator+(Complex &c1,Complex &c2){

    Complex ans(0,0);
     ans.real = c1.real + c2.real;
     ans.imaginary = c1.imaginary + c2.imaginary;

     return ans;

}

int main(){

Complex c1(4,5);
Complex c2(5,4);
Complex c3 = c1+c2;
c3.Print();

}
