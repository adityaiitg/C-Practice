#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0;i<=n;i++)
       dp[i]=i;
    for(int i=2;i<=n;i++){
        if(dp[i]==i){
            dp[i]=i-1;
            for(int j=2*i;j<=n;j=j+i){
                dp[j]=dp[j]/i;
                dp[j]=dp[j]*(i-1);
            }
        }
    }
    cout<<dp[n];
    return 0;
}