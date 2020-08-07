#include<stdio.h>
#include<math.h>
void main()
{
long int b;
b = pow(2,30);
    for(int i=0;i<b;i++)
   {
        for(int j=0;j<b;j++)
        {
        long int c=i+j;
         printf("the value of c=%ld",c);
         }
   }
}
