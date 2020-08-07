#include<stdio.h>
#include<math.h>
#define pi 3.14
float area(float b);
int main()
{float a;
scanf("%f",&a);
float b;
b=area(a);
printf("%f",b);
}
float area(float b)
{
return pi*b*b;
}
