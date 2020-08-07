#include<stdio.h>
int factors(int n)
{ 
  for(int i=1;i<n;i++)
  if(n%i==0)
  {  
     printf("%d /n",i);
     n=n/i;
  }
}

int main()
{
  int n;
  scanf("%d/n",&n);
  factors(n);
return 0;
}

