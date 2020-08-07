#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char hex[10];
    struct node *ptr;
};
struct node* createNode(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return temp;
}
struct node *read_hexadecimal_number(){
    char curr_value[10];
    struct node *head=NULL;
    struct node *temp;
    while(1){
        if(head==NULL)
        {head=createNode();
        temp=head;}
        scanf("%s",temp->hex);
        if(temp->hex[0]=='-')
        {  temp->hex[0]='\0';
            break;}
        temp->ptr=createNode();
        temp=temp->ptr;
    }
return head;
    }
int pow16(int i){
    int r=1;
    while(i--){
        r=r*16;
    }
    return r;
}
int hex2decimal(char *hex){
 int dec=0;
 int result=0;
 int i=0;
 while(hex[i++]!='\0')
 {}
 --i;
 for(int n=1;n<=i;n++){
      switch(hex[n-1]){
      case '0': dec=0;break;
      case '1': dec=1;break;
      case '2': dec=2;break;
      case '3': dec=3;break;
      case '4': dec=4;break;
      case '5': dec=5;break;
      case '6': dec=6;break; 
      case '7': dec=7;break;
      case '8': dec=8;break;
      case '9': dec=9;break;
      case 'a': dec=10;break;
      case 'b': dec=11;break;
      case 'c': dec=12;break; 
      case 'd': dec=13;break;
      case 'e': dec=14;break;
      case 'f': dec=15;break;
    }
  result=result+dec*pow16(i-n);
}
return result;}


void merge(struct node*a,struct node*b){
struct node *temp1=a;
struct node *temp=b;
struct node *t=NULL;
while(temp != NULL){
    while(temp1!=NULL){
       
      if(hex2decimal(temp1->hex)<=hex2decimal(temp->hex)){
       t=temp1->ptr;
       temp1->ptr=createNode();
       temp1=temp1->ptr;
       strcpy(temp1->hex,temp->hex);
       temp1->ptr=t;
      }
     temp1=temp1->ptr;
     temp=temp->ptr;
    }
}

}

void print(struct node *start)
{
struct node *temp;
temp = start;
while(temp != NULL)
{
printf("%s  ",temp->hex);
temp = temp->ptr;
}
}


int main(){
    struct node *a=read_hexadecimal_number();
    struct node *b=read_hexadecimal_number();
    merge(a,b);
    print(a);
   // print(b);
 //   char c[5];
  //  scanf("%s",c);
 //  printf("%d",hex2decimal(c));
 return 0;
}
