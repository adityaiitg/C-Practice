#include<stdio.h>
int main(){
int i,n;
scanf("%d",&n);
int j=n;
for(i=2;i<=j;i++){
if(n%i==0)
{while(n%i==0)
   { printf("%d ",i);
n=n/i;}

}}
return 0;
}
