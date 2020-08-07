#include<stdio.h>
#include<math.h>
int main()
{
    long int a;
    int n,k;
    scanf("%ld %d %d",&a,&n,&k);
    for(int i=0;i<k;i++)
    {
        printf("%d",((int)(a*pow(1/k,i))%n));
    }

}