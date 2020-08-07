#include <stdio.h>

#include <math.h>
#include <stdlib.h>

int main() {
    int a,sum=0;
scanf("%d\n",&a);
int  b[a];
for(int i=0;i<a;i++)
{scanf("%d ",&b[i]);
sum=sum+b[i];
}
printf("%d",sum);

    return 0;
}


