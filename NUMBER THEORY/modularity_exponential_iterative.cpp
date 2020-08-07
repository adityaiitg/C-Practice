#include<bits/stdc++.h>
using namespace std;
int modExp(int a,int b,int c){
    if(a==0)
        return 0;
    long long ans=1;
    while(b!=0){
        if(b&1){
        ans=(ans*a)%c;
        }
        ans=(ans*ans)%c;
        b=b/2;
    }
    return ans;
}
int main(){
  int a=2;
  int b=5;
  int c=5;
  cout<<modExp(a,b,c);
}