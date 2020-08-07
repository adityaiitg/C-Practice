#include<bits/stdc++.h>
using namespace std;
bool compare(int &a,int &b){
    return (b<a);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,compare);
    int flag=1;
    for(int i=0;i<n-2;i++){
       if(arr[i]<arr[i+1]+arr[i+2]){
           cout<<arr[i+2]<<" "<<arr[i+1]<<" "<<arr[i];
           flag=0;
           break;
       } 
    }
    if(flag){
        cout<<"-1";
    }
	// Write your code here
}