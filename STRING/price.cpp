#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   sort(arr,arr+n);
   int intial_health;
   int ans=0;
   cin>>intial_health;
   for(int i=0;i<n;i++){
       if(arr[i]<=intial_health){
           intial_health-=arr[i];
           ans++;
       }
   }
   cout<<ans;
    return 0;
}