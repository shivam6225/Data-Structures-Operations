/*3. Geek has several competitive programming books and he wants to place books one on
another (like a stack). There are total Q queries of two types.
Type 1: This query is represented by &quot;place x&quot;, where x is an integer represents a number of
the book geek wants to place on the top of the stack.
Type 2: This query is represented by &quot;remove&quot;. After this query, print a book number which
is at the top of the stack (If the stack is empty then print -1) and remove it from the stack.
Note: There can be multiple books with the same number. */
#include<iostream>
#include<string.h>
#define MAX 20
using namespace std;

struct stack
{
    int data;
    struct stack* next;
}*head;

void place(struct stack* ptr,int value)
{
    struct stack* newnode=(stack*)malloc(sizeof(struct stack*));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=ptr;
        head=newnode;
    }
}

int remove(struct stack* ptr)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        int value=ptr->data;
        head=ptr->next;
        delete ptr;
        return value;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        head=NULL;
        int Q;
        cin>>Q;
        cin.ignore();
        int pop[Q],i=0;
        while(Q--)
        {
            char query[25];
            cin.getline(query,10);
            if(strcmp(query,"remove")==0)
            {
                pop[i]=remove(head);
                i++;
            }
            else
            {
                char tok[MAX];
                char *token=strtok(query," ");
                if(strcmp(token,"place")==0)
                {
                    token=strtok(NULL," ");
                    strcpy(tok,token);
                    int value=atoi(tok);
                    place(head,value);
                }
            }
        }
        for(int j=0;j<i;j++)
            cout<<pop[j]<<" ";
    }
}
