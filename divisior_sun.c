#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            if(n%i==0)
            s=s+i;
        }
        printf("%d",s);
    }
    return 0;
}