#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *front = NULL, *rear = NULL; // global

void enqueue(int x)
{
    Node *t;
    t = new Node;
    if(t == NULL)
        cout<<"Queue is Full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    
    }
}

int dequeue()
{
    int x = -1;
    Node *t;

    if(front == NULL)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete(t);
    }
    return x;
}

void Display()
{
    Node *p = front;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);


    cout<<"Queue values before dequue : ", Display();

    dequeue();
    cout<<endl;

    cout<<"Queue values after dequue : ",Display();

    return 0;
}