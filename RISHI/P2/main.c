#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20

struct Stack {
int top;
char data[SIZE];
};
typedef struct Stack STACK;
void push(STACK *s,char item)
{
s->data[++(s->top)]=item;
}
char pop(STACK *s)
{
return s->data[(s->top)--];
}
int preced(char Symbol)
{
switch(Symbol)
{
    case '^':return 5;
    case '*':
    case '/':return 3;
    case '+':
    case '-':return 1;

}
}

void infixtopostfix(STACK *s,char infix[20])
{
int i,j=0;
char Symbol,postfix[20],temp;
for(i=0;infix[i]!='\0';i++)
    {
    Symbol=infix[i];
    if(isalnum(Symbol))
    {

        postfix[j++]=Symbol;
    }
    else
        {
        switch(Symbol)
        {
        case '(': push(s,Symbol);
                  break;
        case ')': temp=pop(s);
                  while(temp!='(')
                        {
                            postfix[j++]=temp;
                            temp=pop(s);
                        }
                break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': if (s->top==-1 || s->data[s->top]=='(')

{
                       push(s,Symbol);

                       }
                  else
                  {
                    while(preced(s->data[s->top])>=preced(Symbol)&&s->top!=-1)
                          {
                            postfix[j++]=pop(s);
                            push(s,Symbol);
                  }
                   break;
        }
    }
        }
while(s->top!=-1)
{
postfix[j++]=pop(s);
postfix[j]='\0';
}
printf("\n Postfix expression is %s",postfix);


int main()
{
char infix[20];
STACK s;
s.top=-1;
printf("\nRead infix expression\n");
scanf("%s",infix);
infixtopostfix(&s,infix);
return 0;
}
