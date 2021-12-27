#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

int arr1[2][2] = {{1,2},{3,4}};

int **arr2 = new int*[2];

for(int i=0;i<2;i++){
    arr2[i] = new int[2];
}

// Taking input

for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        cin>>arr2[i][j];
    }
}


for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        cout<<arr2[i][j]<<" ";
    }
    cout<<endl;
}
// Using vectors

vector<vector<int>> arr3(2,vector<int>(2,0));


for(int i=0;i<arr3.size();i++){
    for(int j=0;j<arr3[0].size();j++){
        cin>>arr3[i][j];
    }
}


for(vector<int> v : arr3){
    for(int ele : v){
        cout<<ele<<" ";
    }
    cout<<endl;
}

}
