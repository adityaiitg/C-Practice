#include<stdio.h>
int main()
{
int a,b,j,i;
char x='A';
printf("ENTER THE VARIABLE A AND B\n");
scanf("%d*%d",&a,&b);
printf("ENTER WHICH SIZE YOU WANT");
scanf("%d",&j);
if(1)
{for(i=0;i<=j;i++)
   {
    if(i==j)
    {printf("A%d %d*%d\n",i,a,b);}
       a=a/2;
       if(b>a)
              {int temp =a;
               a=b;
               b=temp;
               }
   }
}}


