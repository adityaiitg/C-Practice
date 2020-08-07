#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void append(int);
void display();
void addbeg(int);
void sum();
int search(int);
void remov(int);

int main()
{ int i=0;
  while(i++<1000)
  {
    append(i);
  }
   display();
  sum();
}

void append(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = NULL;
    if (start == NULL)
    {
        start = nptr;
    } 
    else
    {
        struct node *temp;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        } temp->next = nptr;
    }
}


void addbeg(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = start;
    start = nptr;
}


void display()
{
    struct node *temp;
    temp = start;
    if (temp == NULL)
    {
        printf("link list is empty");
    } 
    while (temp != NULL)
    {
        printf("%d : ", temp->data);
        temp = temp->next;
    }
}

void sum()
{
    int sum = 0;
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        sum = sum + temp->data;
        temp = temp->next;
    } printf("sum of elements :%d", sum);
}

int search(int item)
{
    int loc = 0;
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        loc++;
        if (temp->data == item)
        {
            return loc;
        } temp = temp->next;
    }
    return  - 1;
}



void remov(int item)
{
    struct node *temp,  *old;
    temp = start;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            if (temp == start)
            {
                start = temp->next;
            } 
            else
                old->next = temp->next;
            printf("\n%d ttem deleted\n",temp->data);
            free(temp);
            return ;
        }
        else
        {
            old = temp;
            temp = temp->next;
        }
    }
    printf("Item not found ");
}