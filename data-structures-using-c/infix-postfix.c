/* This  C program converts infix expression to postfix expression using stack*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20

struct stack
{
  int top;
  char data[SIZE];

};
typedef struct stack STACK;


int preced(char symbol)
{
switch(symbol)
{

 case  '^' :return 5;
 case  '*' :
 case  '/' :return 3;
 case  '-' :
 case  '+' :return 1;
}
}


void push(STACK *s,char item)
{
  s->data[++(s->top)]=item;
}

char pop(STACK *s)
{
  return s->data[(s->top)--];
}


void infixtopostfix(char infix[20],STACK *s)
{
  char postfix[20],symbol,temp;
  int i,j=0;
  for(i=0;infix[i]!='\0';i++)
  {
    symbol=infix[i];
    if(isalnum(symbol))
    postfix[j++]=symbol;
    else
      {
      switch(symbol)
      {
      case '(':
      {
      push(s,symbol);
      break;
      }
      case ')':
      {
      temp=pop(s);
      while(temp!='(')
      {
      postfix[j++]=temp;
       temp=pop(s);
       }
    break;
     }
    case '+':
    case '-':
    case '*':
    case '^':
    case '/':
            {
            if(s->top==-1||s->data[s->top]=='(')
                push(s,symbol);
            else
             {
             while(preced(s->data[s->top])>=preced(symbol) && s->data[s->top]!='(' && s->top!=-1)
                  postfix[j++]=pop(s);
            push(s,symbol);
            }
            break;


            }

    }
  }
}
while(s->top!=-1)
postfix[j++]=pop(s);
postfix[j]='\0';
printf("\n Postfix expression is: %s",postfix);

}




int main()
{
char infix[20];
STACK s;
s.top=-1;
printf("\n Read infix experssion: ");
scanf("%s",infix);
infixtopostfix(infix,&s);
return 0;
}
