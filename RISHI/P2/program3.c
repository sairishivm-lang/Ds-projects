#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
struct stack
{
int top;
float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)
{
    s->data[++(s->top)]=item;
}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}
float compute(float oper1,char Symbol,float oper2)
{
    switch(Symbol)
    {
        case '+': return oper1+oper2;
        case '-': return oper1-oper2;
        case '*': return oper1*oper2;
        case '/': return oper1/oper2;
        case '^': return pow(oper1,oper2);
    }
}
float Evalpostfix(STACK *s,char postfix[20])
{
        int i;
        char Symbol;
        float oper1,oper2,res;
        for(i=0;postfix[i]!='\0';i++)
        {
            Symbol=postfix[i];
            if(isdigit(Symbol))
                push(s,Symbol='0');
            else
            {
                oper2=pop(s);
                oper1=pop(s);
                res=compute(oper1,Symbol,oper2);
                push(s,res);
            }
        }
        return pop(s);
}
int main()
{
        char postfix[20];
        STACK s;
        s.top=-1;
        float ans;
        printf("\n Read postfix expression\n");
        scanf("%s",postfix);
        ans=Evalpostfix(&s,postfix);
        printf("\n The final result=%f\n",ans);
        return 0;
}

