#include<bits/stdc++.h>
using namespace std;
bool compare(int *arr1,int *arr2){
    return arr1[1]<arr2[1];
}

int main()
{
    int n;
    cin>>n;
    
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[3];
    }
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    long *dp=new long[n];
    sort(arr,arr+n,compare);
    dp[0]=(long)arr[0][2];
    dp[1]=(long)arr[1][2];
    if(arr[0][1]<=arr[1][0]){
       dp[1]+=dp[0];
    }
    for(int i=2;i<n;i++){
        dp[i]=(long)arr[i][2];
        for(int j=i-1;j>=0;j--){
             if(arr[i][0]>=arr[j][0]){
                 if(dp[j]+arr[i][2]>dp[i]){
                     dp[i]=dp[j]+arr[i][2];
                 }
             }
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n-1];
    return 0;
}