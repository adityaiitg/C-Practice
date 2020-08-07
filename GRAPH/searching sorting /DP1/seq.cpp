#include<iostream>
using namespace std;
int longestBitonicSubarray(int *input, int n) {
     int *arr=new int[n];
     int *rev=new int[n];
     int *rev_input=new int[n];
         arr[0]=1;
         rev[0]=1;
     for(int i=0;i<n;i++){
         rev_input[i]=input[n-1-i];
     }
     for(int i=1;i<n;i++){
          arr[i]=1;
          rev[n-1-i]=1;
        for(int j=0;j<i;j++){
            if(input[i]>input[j]&&arr[i]<1+arr[j]){
                    arr[i]=1+arr[j];
            }
            else{
                  arr[i]=1;
            }
            if(rev_input[i]>rev_input[j]&&rev[i]<1+rev[j]){
                    rev[i]=1+rev[j];
            }
            else
            {
             rev[i]=1;   
            }
            
        }
        
     	
 	}
    int ans = arr[0] + rev[0] - 1; 
   for (int i = 1; i < n; i++) 
     if (arr[i] + rev[i] - 1 > ans) 
         ans = arr[i] + rev[i] - 1; 
   return ans; 
     }


int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
