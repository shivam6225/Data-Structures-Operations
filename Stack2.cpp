
#include<iostream>
using namespace std;
#define MIN -10000000

struct stack
{
    int data;
    struct stack* next;
}*head=NULL;

void push(struct stack* ptr,int value)
{
    struct stack* NewNode=(stack*)malloc(sizeof(struct stack));
    NewNode->data=value;
    NewNode->next=NULL;
    if(head==NULL)
    {
        head=NewNode;
    }
    else
    {
        NewNode->next=ptr;
        head=NewNode;
    }
}

int pop(struct stack* ptr)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        struct stack* prev_ptr;
        while(ptr->next!=NULL)
        {
            prev_ptr=ptr;
            ptr=ptr->next;
        }
        int value=ptr->data;
        prev_ptr->next=NULL;
        delete ptr;
        return value;
    }
}
void Max(int *arr,int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            if(arr[j]>arr[i])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        push(head,arr[i]);
    }
}

int main()
{
    int N;
    cin>>N;
    int arr[N],temp_arr[N];
    int i;
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        temp_arr[i]=arr[i];
    }
    Max(temp_arr,N);
    int t=N;
    while(t--)
    {
        int check=pop(head);
        for(i=N-1;i>=0;i--)
        {
            if(check==arr[i])
            {
                cout<<i+1<<" ";
                arr[i]=MIN;
            }
        }
    }
    return 0;
}
