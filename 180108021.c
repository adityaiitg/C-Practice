#include<stdio.h>
int main(){
long long int year;
scanf("%lld",&year);
long long int roll1=(year%100)*10000000;
long long int prog;
char prog1;
char prog2;
scanf("\n%c%c",&prog1,&prog2);
if(prog1=='B'&&prog2=='T'){prog=1;}
if(prog1=='B'&&prog2=='D'){prog=2;}
if(prog1=='M'&&prog2=='T'){prog=21;}
if(prog1=='P'&&prog2=='D'){prog=42;}
long long int roll2=prog*100000;
long long int dep;
char dep1;
char dep2;
scanf("\n%c%c",&dep1,&dep2);
if(dep1=='B'&&dep2=='A'){dep=1;}
if(dep1=='B'&&dep2=='B'){dep=2;}
if(dep1=='B'&&dep2=='C'){dep=3;}
if(dep1=='B'&&dep2=='D'){dep=4;}
long long int roll3=dep*1000;
long long int roll4;
scanf("\n%lld",&roll4);
long long int rollnumber=(roll1+roll2+roll3+roll4);
printf("\n%lld",roll1);
printf("\n%lld",roll2);
printf("\n%lld",roll3);
printf("\n%lld",roll4);
printf("\n%lld",rollnumber);
return 0;}
