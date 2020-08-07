#include <stdio.h>

int main(void) {
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        b=0;
        while(a)
        {
          b=b+a%10;
          a=a/10;
        }
        printf("%d\n",b);
    }
	// your code goes here
	return 0;
}


