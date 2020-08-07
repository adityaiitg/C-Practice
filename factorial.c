#include <stdio.h>

int main(void) {
    int t,f,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&s);
        f=1;
        for(;s>0;s--)
        f=f*s;
        printf("%d\n",f);
    }
    
	// your code goes here
	return 0;
}


