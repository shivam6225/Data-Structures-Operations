/* Given head which is a reference node to a singly-linked list. The value of each node in the
linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.*/ 
#include<iostream>
#include<math.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
}*head=NULL;

void InsertAtLast(struct Node* ptr,int value)   //Inserting Binary Bits from MSB to LSB 
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}

void Display(struct Node* ptr)              //To display the store Binary Bits in linked list
{
    if(head==NULL)
    {
        cout<<"No nodes/elements in linked list\n";
    }
    else
    {
        cout<<"Linked List:(From MSB to LSB)";
        while(ptr!=NULL)
        {
            cout<<"->"<<ptr->data;
            ptr=ptr->next;
        }
    }
}
int ConvertBintoDec(struct Node* ptr,int n)    //Converting Binary to decimal
{
    if(head==NULL)
    {
        cout<<"No nodes/elements in linked list";
        return 0;
    }
    else
    {
        int temp=0;
        while(ptr!=NULL)
        {
            temp+=pow(2,n)*(ptr->data);    
            ptr=ptr->next;
            n--;
        }
        return temp;
    }
}

int main()
{
    int n;
    cout<<"Enter size of n-bit Binary number to be enetered: ";
    cin>>n;
    int binary_num;
    cout<<"\nEnter "<<n<<"-bit Binary number: ";
    int i;
    for(i=0;i<n;i++)
    {
        cin>>binary_num;
        InsertAtLast(head,binary_num);   //Inserting Binary Bits in Linked List  
    }
    Display(head);
    long int num= ConvertBintoDec(head,n-1);
    cout<<"\n\nDecinmal Equivalent of Entered Binary number is: "<<num;
    return 0;
}
