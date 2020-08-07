#include <bits/stdc++.h>


using namespace std;

pair<long long,long long> knapsack(long long* cost, long long* fun, long long n, long long maxc){
    long long dp[maxc+1]={0};
    for(long long i=0;i<n;i++){   
        for(long long j=maxc;j>=cost[i];j--){
            dp[j]=max(dp[j],fun[i]+dp[j-cost[i]]);
        }
    }
    long long prev=maxc;
    long long i=maxc;
    for(;dp[i]==dp[i-1];i--){
    }
    return make_pair(dp[maxc],i);

}

int main()
{
    while(true){
    long long budget,n;
    cin>>budget>>n;
        if(budget==0||n==0){
            return 0;
        }
    long long cost[n];
    long long fun[n];
    for(long long i=0;i<n;i++){
              cin>>cost[i]>>fun[i];
    }
    pair<long long,long long> ans=knapsack(cost,fun,n,budget);
    cout<<ans.second<<" "<<ans.first<<endl;
    }
    return 0;
} 