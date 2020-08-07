#include<stdio.h>
struct node{
    int data;
    struct node* link;
}
node* A;
A=NULL;
node* temp= (node)malloc(sizeof(node)); //for c++ node* temp=new node();
temp->data=2;//equivalent of (*temp).data=2;
temp->link=NULL;//(*temp).link=NULL;
A=temp;
node* temp= (node)malloc(sizeof(node));
temp->data=4;
temp->link=NULL;

//TRANSVERSAL
node* temp1=A;
while(temp1->link!NULL){
    temp1=temp1->link;
}
temp1->link=temp;