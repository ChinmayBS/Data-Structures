/* This program evaluates postfix expression using stack*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20



struct Stack
{
float data[SIZE];
int top;
};
typedef struct Stack STACK;


void push(STACK *s,float symbol)
{
  s->data[++(s->top)]=symbol;
}


float pop(STACK *s)
{
  return s->data[(s->top)--];
}

float operate(float oper1,float oper2,char symbol)
{
  switch (symbol)
   {
    case '+':return oper1+oper2;
    case '-':return oper1-oper2;
    case '*':return oper1*oper2;
    case '/':return oper1/oper2;
    case '^':return pow(oper1,oper2);
   }
}


float postfix_evaluate(char postfix[],STACK *s)
{

  int i;
  float oper1,oper2,result,value;
  char symbol;
  for(i=0;postfix[i]!='\0';i++)
  {
    symbol=postfix[i];
    if(isdigit(symbol))
    {
      push(s,symbol-'0'); //conversion of charcter 'digit' to integer 'digit'

    }
    else if(isalpha(symbol))
    {
      printf("Read Value of %c: ",symbol);
      scanf("%f",&value );
      push(s,value);
    }
    else
    {
      oper2=pop(s);
      oper1=pop(s);
      result=operate(oper1,oper2,symbol);
      push(s,result);
    }
  }
return pop(s);
}


int main()
{
  STACK s;
  char postfix[20];
  float value;
  s.top=-1;
  printf("Enter postfix expression: " );
  scanf("%s", postfix);
  value=postfix_evaluate(postfix,&s);
  printf("\nThe value after evaluation is: %f",value );
  return 0;
}
