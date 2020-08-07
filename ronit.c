#include<stdio.h>
struct ronit
{
  int tb;
  int gb;
  int mb;
  int kb;
  int by;
  int bit;
};
int main()
{
    long int data;
    struct ronit a;
    scanf("%ld",&data);
    a.tb=(int)(data/(1024*1024*1024*1024*8));
    a.gb=(int)((data-(long int)a.tb*1024*1024*1024*1024*8)/(1024*1024*1024*8));
    a.mb=(int)((data-(long int)a.tb*(1024*1024*1024*1024*8)-(long int)a.gb*1024*1024*1024*8)/(1024*1024*8);
    a.kb=(int)(data-(long int)a.tb*(1024*1024*1024*1024*8)-(long int)a.gb*1024*1024*1024*8-(long int)a.mb*1024*1024*8)/(1024*8);
    a.by=(int)(data-(long int)a.tb*(1024*1024*1024*1024*8)-(long int)a.gb*1024*1024*1024*8-(long int)a.mb*1024*1024*8-(long int)a.kb*1024*8)/8;
    a.bit=(int)(data-(long int)a.tb*(1024*1024*1024*1024*8)-(long int)a.gb*1024*1024*1024*8-(long int)a.mb*1024*1024*8-(long int)a.kb*1024*8-(long int)a.by*8);
  printf("%d  %d %d %d %d %d",a.tb,a.gb,a.mb,a.kb,a.by,a.bit);

}