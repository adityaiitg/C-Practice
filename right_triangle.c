#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      double h,s,s1,s2;
      scanf("%le %le",&h,&s);
      float theta;
      if(4*s/(h*h)>1)
      printf("-1\n");
      else 
     { theta=0.5*asin(4*s/(h*h));
        s1=h*sin(theta);
         s2=h*cos(theta);
        if(s1>s2)
        {
           long double k=s1;
           s1=s2;
           s2=k;
        }
        printf("%0.5e %0.5e %0.5e\n",s1,s2,h);

     }
    }
  
    
}