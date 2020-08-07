#include <stdio.h>
int main()
{
long double old,new,e,a,b;
int i;
char  from;
char to;
printf("from");
scanf("%c",&from);
printf("value");
scanf("%d",&old);
printf("to");
scanf("%c",&to);
switch(from){
case 't': a=4;
case 'g': a=3;
case 'm': a=2;
case 'k': a=1;
case 'b': a=0;}
switch(to){
case 't': b=4;
case 'g': b=3;
case 'm': b=2;
case 'k': b=1;
case 'b': b=0;
}
for(i=0;i<(b-a);i++)
{
e=e*1024;}
new=old*e;
printf("%d",new);
return 0;
}


