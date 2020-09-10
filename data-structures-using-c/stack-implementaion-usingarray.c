#include<stdio.h>
#include <stdlib.h>
#define SIZE 5

int top=-1;
int stack[SIZE];

void push(int item)             //push function to push item into stack
{
top+=1;
stack[top]=item;
}


int pop()                           //pop function to pop item from stack
{
int element;
if(top==-1)
  printf("\nStack Underflow\n");
else
{
element=stack[top];
top-=1;
printf("\n Element poped: %d\n", element);
}
}


void display()                             //display function to display elements in stack
{
if(top==-1)
printf("\n Stack is empty\n");
else
{
for(int i=top;i>=0;i--)
printf("%d\t",stack[i]);
}
}

int main()                                 //main function implementation using menu driven programming
{
  int ch,item;
  while(1)
  {
     printf("Enter Stack operations: \n 1.Push \n 2.Pop \n 3.Display \n 4.Exit\n");
     scanf("%d",&ch);
     switch(ch)
    {
      case 1:
       {
       if(top==SIZE-1)
         printf("\n Stack Overflow\n");
       else
       {
         printf("\n Enter element to be pushed\n");
         scanf("%d",&item);
         push(item);
       }
       break;
       }
       case 2:
       {
         pop();

        break;
        }
        case 3:
       {
        display();
        break;
      }
       default : exit(0);
     }
   }
return 0;
}
