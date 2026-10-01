#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5
struct stack{
int top;
int data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,int item)
{
if (s->top==SIZE-1){
    printf("\n Stack overflow");
    }
else{
    s->top=s->top+1;
    s->data[s->top]=item;
    }
}
void pop(STACK *s)
{
if(s->top==-1)
    printf("\n Stack underflow");
else{
    printf("\n Element poped is=%d",s->data[s->top]);
    s->top=s->top-1;
}
}
void display (STACK s)
{
int i;
if(s.top==-1)
    printf("\n Stack is empty");
else{
    printf("\n Stack content:\n",s.data[i]);
    for(i=s.top;i>=0;i--)
        printf("%d\n",s.data[i]);
    }
}
int main()
{
int ch,item;
STACK s;
s.top=-1;
for(;;)
{
printf("\n 1.Push");
printf("\n 2.Pop");
printf("\n 3.Display");
printf("\n 4.Exit");
printf("\n Read choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Read element to be pushed:");
                scanf("%d",&item);
                push( &s, item);
                break;
        case 2: pop(&s);
                break;
        case 3: display(s);
                break;
        default: exit(0);
        }
    }
    return 0;
}
