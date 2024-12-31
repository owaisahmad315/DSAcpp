#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *first = NULL;

void Create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    if(p != 0)
    {
        cout<<p->data<<endl;
        Display(p->next);
    }
}

int main()
{
    int A[] = {8,3,7,12,9};

    Create(A,5);
    Display(first);

    return 0;
}