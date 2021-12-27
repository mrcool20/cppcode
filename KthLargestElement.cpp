#include <bits/stdc++.h>
using namespace std;

int kthLargest(int arr[],int n,int k){

priority_queue<int,vector<int>,greater<int>> pq;

for(int i=0;i<k;i++) pq.push(arr[i]);



for(int i=k;i<n;i++){

    if(arr[i]> pq.top()){
        pq.pop();
        pq.push(arr[i]);
    }
}

return pq.top();

}

int main(){

    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th largest element is " << kthLargest(arr, n, k);
    return 0;
}
