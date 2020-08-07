#include<stdio.h>
int factorial(int n);
void factors(int n);
void prime_factors(int n);
int main()
{
 int n;
 scanf("%d",&n);
 printf("FACTORIAL=%d",factorial(n));
 factors(n);
 prime_factors(n);
}
int factorial(int n)
{ int s=1;
  for(int i=1;i<=n;i++)
      s*=i;
return s;
}

void factors(int n)
    {printf("\nFACTORS ARE");
    for(int i=1;i<=n;i++)
    if(n%i==0)
      {printf("\t%d",i);
      }
   }
void prime_factors(int n)
   {printf("\nTHE PRIME FACTORS ARE \n%d=1",n);
    for(int i=2;i<=n;i++)
    while(n%i==0)
      {printf("*%d",i);
       n/=i;
      }
   }
