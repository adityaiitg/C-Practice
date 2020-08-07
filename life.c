#include <stdio.h>

int main(void) 
{    int a;
     scanf("%d",&a);
      if(a!=42)
      {printf("\n%d\n",a);
        while(1)
       {
       scanf("%d\n",&a);
       if(a!=42)
        {printf("%d\n",a);}
        else break;
       }
      }
	return 0;
}
