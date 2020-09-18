#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


struct queue
{
  int data[SIZE];
  int rear,front;
};
typedef struct queue QUEUE;


void enqueue(QUEUE *q, int item)
{
  if(q->rear==SIZE-1)
  printf(" Queue is Full\n" );
  else
  {
    if(q->rear==-1)
    q->front=0;
    q->data[++(q->rear)]=item;
  }

}

int dequeue(QUEUE *q)
{
  int item;
  if(q->front==-1)
  printf(" Queue is empty \n");
  else
  {
    item=q->data[q->front];
    printf(" The element removed is: %d \n",item );
    if(q->front==q->rear)
    {
      q->rear=-1;q->front=-1;
    }
    else
    q->front+=1;

  }

}


void display(QUEUE q)
{
  if(q.rear==-1)
  printf("\n Queue is empty \n" );
  else
  {
    printf(" Queue elements are:" );
    for (int i=q.front;i <= q.rear;i++)
    {
      printf("\t%d",q.data[i]);
    }
    printf("\n");

  }
}


int main()
{
  QUEUE q;
  int item,ch;
  q.rear=-1;
  q.front=-1;
  while (1)
   {
    printf(" 1.enqueue \n 2.dequeue \n 3.display \n 4.exit \n Enter Choice: ");
    scanf("%d",&ch);
    switch (ch)
     {
      case 1:
      {
        printf(" Enter element to be added: ");
        scanf("%d",&item );
        enqueue(&q,item);
        printf("\n" );
        break;
      }
      case 2:
      {
        dequeue(&q);
        printf("\n");
        break;
      }
      case 3:
      {
        display(q);
        printf("\n");
        break;
      }
      case 4: exit(0);
      default:printf("\n Invalid choice\n");
    }
  }
  return 0;
}
