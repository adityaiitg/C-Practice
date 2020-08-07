#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    //(optional)if(head!=NULL) temp->next=head;
    head=temp;
}
void Print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        Printf(" %d",(*temp).data);
        temp=temp->next;
    }
    Printf("\n");
}
int main()
{
    head=NULL;
    Printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<x;i++)
    {
        Printf("enter the numbers \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
}