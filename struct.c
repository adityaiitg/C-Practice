#include<stdio.h>
struct rev{
    char a[256];
    char b[256];
};
int i,size;
void reverse(struct rev *s){
    while(i--)
    {
      s->b[i--]=s->a[size-i];
    }
}
int main(){
    struct rev s;
    for(i=0;i<256;i++)
   {scanf("%c",&s.a[i]);
   if(s.a[i]=='\n')
   break;}
   size=i;
reverse(&s);
printf("%s",s.b);
}