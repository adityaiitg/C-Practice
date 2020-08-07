#include<stdio.h>
{
int main(void)
{
char room[26][4];
int str[26];
int end[26];
for(int i=0;i<26;i++)
{
scanf("\n%s %d %d",room[i],&str[i],&end[i]);
}
for(int j=0;j<26;j++)
{
printf("%s %d %d\n",room[j],str[j],end[j]);
}
}




