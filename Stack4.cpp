/*13. Given a string s containing just the characters &#39;(&#39;, &#39;)&#39;, &#39;{&#39;, &#39;}&#39;, &#39;[&#39; and &#39;]&#39;, determine if
the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.*/
#include<iostream>
using namespace std;
#define MAX 100
struct Stack
{
    char data[MAX];
    int top;
};
typedef struct Stack stack;
int isEmpty(stack*s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull(stack*s)
{
    if(s->top==MAX-1)
        return 1;
    else
        return 0;
}
void push(stack *s,char value)
{
    if(isfull(s))
        cout<<"Stack is full\n";
    else
    {
        s->top++;
        s->data[s->top]=value;
    }
}
char pop(stack *s)
{
    if(isEmpty(s))
        return 0;
    else
    {
        char value=s->data[s->top];
        s->top--;
        return value;
    }
}

int main()
{
    char str[MAX];
    cin>>str;
    int i;
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    int check=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            push(s,str[i]);
        if(str[i]==')'||str[i]=='}'||str[i]==']')
        {
            char temp=pop(s);
            if(temp=='{'&&str[i]=='}')
                continue;
            else if(temp=='('&&str[i]==')')
                continue;
            else if(temp=='['&&str[i]==']')
                continue;
            else
                { 
                    check=-1;
                    break;
                }
        }
    }
    if(isEmpty(s))
        if(check) cout<<"False(Not Balanced)";
        else cout<<"True(Balanced)";
    else
        cout<<"False(Not Balanced)";
	return 0;
}
