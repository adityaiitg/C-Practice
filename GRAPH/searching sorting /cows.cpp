#include<bits/stdc++.h>
using namespace std;
bool possible(long long *arr,int size,long long num,int cow){
    int curr=arr[0];
    cow--;
      for(int i=1;i<size;i++){
          if(arr[i]-curr>=num){
              cow--;
              curr=arr[i];
          }
      }
    if(cow){
        return 0;
    } 
    else{
        return 1;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        int c;
        cin>>n>>c;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long start=0;
        long long end=arr[n-1]-arr[0];
       long long ans = -1;
		while(start<=end){
			long long mid = start + (end-start)/2;
			if(possible(arr,n,mid,c)){
				ans=mid;
				start = mid+1;
			}
            else{
				end = mid-1;
			}

		}
		cout << ans <<endl;
    }

	// Write your code here
}