#include<stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stack
{
int top;
int data[SIZE];
};
typedef struct stack STACK;


void push(STACK *s,int item)
{

  s->data[++(s->top)]=item;
}

int pop(STACK *s)
{
  if(s->top==-1)
  {
  printf("\nStack Underflow\n");
  return -1;
  }
  else
  {
  return s->data[(s->top)--];
  }
}

void display(STACK s)
{
if(s.top==-1)
printf("\nStack is Empty\n");
else
{
printf("\n Stack content are: \n");
for(int i=s.top;i>=0;i--)
printf("\t %d",s.data[i]);
}
}

int main()
{
  STACK s;
  s.top=-1;
  int ch,item,del;
  while(1)
    {
    printf("\n 1.Push \n 2.pop \n 3.display \n 4.exit \n enter choice: ");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1:
        {
          if(s.top==SIZE-1)
            printf("\nStack Overflow\n");
          else
          {
          printf("\n enter element to be pushed: ");
          scanf("%d",&item);
          push(&s,item);
          }
        break;
        }
      case 2:
       {
        del=pop(&s);
        if(del!=-1)
        printf("\nThe element poped: %d\n", del);
        break;
      }
      case 3:
       {
         display(s);
         break;
       }
      case 4: exit(0);
      default :  printf("\n invalid choice\n");

     }
    }

return 0;
}
