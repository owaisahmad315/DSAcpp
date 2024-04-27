#include <iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int x)
{
    struct Node *t;
    t= new Node;

    if(t==NULL)
        cout<<"Stack is full"<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top =t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;

    if(top == NULL)
        cout<<"Stack is Empty"<<endl;
    else
    {
         t=top;
         top= top->next;
         x = t->data;
         free(t);
    }
    return x;
}

void Display()
{
    struct Node *p  = top;
    while(p!= NULL)
        cout<<p->data<<endl;
        p=p->next;
}
int main()
{ 
    push(4);
    push(5);
     

    Display();

    cout<<"the poped value is: "<< pop()<<endl;
    return 0;
};