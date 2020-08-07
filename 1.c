#include<stdio.h>
void output(int n)
{
if(n>0){
output(n/4);
printf("%d",n%4);
}
}
int main()
{
output(200);   
}
