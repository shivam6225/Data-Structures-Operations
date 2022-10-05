#include<iostream>
using namespace std;
#define MAX 10
int size=0;
struct Stack
{
    int data[MAX];
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
void push(stack *s,int value)
{
    if(isfull(s))
        cout<<"Stack is full\n";
    else
    {
        s->top++;
        s->data[s->top]=value;
        size++;
    }
}
void pop(stack *s)
{
    if(isEmpty(s))
        cout<<"\nStack is Empty\n";
    else
    {
        cout<<"\nItem popped:"<<s->data[s->top]<<endl;
        s->top--;
        size--;
    }
}
void print(stack *s)
{ 
        int i;
        for(i=size-1;i>=0;i--)
        {
            cout<<s->data[i]<<"<-";
        }
}
int main()
{
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    int i,value;
    for(i=0;i<11;i++)
    {
       cin>>value;
       push(s,value);
    }
    print(s);
    
    return 0;
}