#include <stdio.h>
void maxcoin(int *s,int n);
int main(void) {
    int t,n,max=0;
    int *s;
    s=&max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        maxcoin(s,n);
        printf("%d",max);
    }
	return 0;
}
void maxcoin(int *s,int n)
{
    if(n<=4)
    {*s=*s+n;}
    else
    { maxcoin(s,n/2);
      maxcoin(s,n/3);
      maxcoin(s,n/4); 
    }
}
