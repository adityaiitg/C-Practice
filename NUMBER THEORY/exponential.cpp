#include<bits/stdc++.h>
using namespace std;
int modExp(int a,int b,int c){
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    long long ans;
    if((b%2)==0){
        long long smallans=modExp(a,b/2,c);
        ans=(smallans*smallans)%c;
    }else
    {
        long long smallans=modExp(a,b-1,c);
        ans=(a%c);
        ans=(ans*smallans)%c;
    }
    return int((ans+c)%c);
    
}
int main(){
  int a=2;
  int b=5;
  int c=5;
  cout<<modExp(a,b,c);
}