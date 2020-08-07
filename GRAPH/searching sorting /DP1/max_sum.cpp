#include <bits/stdc++.h>
using namespace std;
int main(){   
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n+1];
    for(int i=1;i<=n;i++){
        arr[i]=new int[m+1];
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    int **sum=new int*[n+1];
    for(int i=1;i<=n;i++){
        sum[i]=new int[m+1];
        for(int j=1;j<=m;j++){
          sum[i][j]=0;
          for(int i1=i;i1<=n;i1++){
            for(int j1=j1;j1<=m;j1++){
                sum+=arr[i1][j1];
            }
          } 
        }
    }
    int **out=new int*[n+1];
    for(int i=1;i<=n;i++){
        out[i]=new int[m+1];
         for(int j=1;j<=m;j++){
             out[i][j]=INT_MIN;
           
        }
    }
    out[n][m]=sum[n][m];
     for(int i=n-1;i>0;i--){
     for(int j=m-1;j>0;j--){
           for(int i1=i;i1<n;i1++){
               for(int j1=j;j1<m;j1++){
                 int temp=sum[i][j]+sum[i1+1][j1+1]-sum[i1+1][1]-sum[1][j1+1];
                 if(temp>out[i][j]){
                     out[i][j]=temp;
                 }
               }
           }
           
        }
    }
    int ans=INT_MIN;
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(ans<out[i][j]){
                  ans=out[i][j];
              }
          }
      }
    cout<<ans;
    
    return 0;
}
