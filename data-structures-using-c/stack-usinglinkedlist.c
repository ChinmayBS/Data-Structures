#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

struct node
{
  int data;
  struct node *addr;

};
typedef struct node *NODE;
int count=0;


NODE push(NODE start,int item)
{
  NODE temp;
  if(count==SIZE)
  {
    printf("\n Stack Overflow");
    return start;

  }

  else
  {
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->addr=start;
    count+=1;
    //printf("%d",count);
    return temp;
  }
}

NODE pop(NODE start)
{
  NODE temp;
  int del_item;
  if(start==NULL)
  {
    printf("\n Stack is empty\n");
    return NULL;
  }
  else
  {

    del_item=start->data;
    printf("\n The poped element is %d: ",del_item);
    count-=1;
    //printf("%d",count);
    temp=start;
    start=start->addr;
    free(temp);
    return start;
   }
}

void display(NODE start)
{
  NODE temp;
  if(start==NULL)
  printf("\n Stack is Empty");
  else
  {
    printf("\n The stack elemnts are: " );
    for(temp=start;temp!=NULL;temp=temp->addr)
    {
      printf("\n %d",temp->data);
    }


  }
}

int main()
{
  NODE start=NULL;
  int item,ch;


  while(1)
  {
    printf("\n Enter operation \n 1.push \n 2.pop \n 3.display \n 4.exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      {
        printf("\n Enter element to be pushed: ");
        scanf("%d",&item);
        start=push(start,item);

        break;
      }
      case 2:
      {
        start=pop(start);

        break;
      }
      case 3:
      {
        display(start);
        break;
      }
      case 4:
      {
        exit(0);
      }
      default : printf("\n Invalid choice");

    }
  }
  return 0;

}
