#include<stdio.h>
#include<stdlib.h>
struct  node
 {
  int data;
  struct node* lc;
  struct node* rc;
 };
struct node* newnode(int data)
 {
     struct node* node=(struct node*)malloc(sizeof(struct node));
     node->data=data;
     node->lc=NULL;
     node->rc=NULL;
     return node;
 }
    
int main()
{
  struct node *root=newnode(1);
  root->lc=newnode(2);
  root->rc=newnode(3);
  root->lc->lc=newnode(4);
  root->lc->rc=newnode(5);
  root->rc->lc=newnode(6);
  root->rc->rc=newnode(7);
  getchar();
  return 0;
}
   
