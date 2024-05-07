#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *front = NULL, *rear = NULL;

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
    
}

int main()
{
    return 0;
}