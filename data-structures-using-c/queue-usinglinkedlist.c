#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct node
{
  int data;
  struct node *addr;
};
typedef struct node *NODE;

int count;

NODE enqueue(NODE start,int item)
{
  NODE temp,cur;
  if (count==5)
  {
    printf("\n Queue is Full");
    return start;
  }
  else
  {
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->addr=NULL;
    if (start==NULL)
    {
      count+=1;
      start=temp;
      return start;
    }
    else
    {
      for(cur=start;cur->addr!=NULL;cur=cur->addr);
      cur->addr=temp;
      count+=1;
      return start;
    }
  }

}

NODE dequeue(NODE start)
{
  NODE temp;
  if (start==NULL)
  {
    printf("Queue is Empty");
    return start;
  }
  else
  {
    printf("\n The element removed is: %d",start->data);
    count-=1;
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
  printf("\n Queue is Empty" );
  else
  {
    printf("\n Queue elements are: \n");
    for(temp=start;temp!=NULL;temp=temp->addr)
    {
      printf("%d\n",temp->data);
    }

  }

}

int main()
{
  NODE start=NULL;
  int item,ch;
  while(1)
  {
    printf("\n 1.Enqueue  \n 2.Dequeue \n 3.Display \n 4.exit \n Enter the choice: \n");
    scanf("%d",&ch);
    switch (ch)
     {
      case 1:
      {
        printf("\n Enter element to be inserted \n");
        scanf("%d",&item);
        start=enqueue(start,item);
        break;
      }
      case 2:
      {
        start=dequeue(start);
        break;
      }
      case 3:
      {
        display(start);
        break;
      }
      case 4: exit(0);
      default :printf("\n Invalid choice");
     }
  }
  return 0;
}
