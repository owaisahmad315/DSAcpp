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

int Max(Node *p)
{
    int max = -32768;
    while(p)
    {
        if(p->data > max)
        {
            max = p->data;  
        }
        p = p->next;
        
    }
    return max;
}

int main()
{
    int A[] = {3,5,19,9,10,15};
    Create(A,6);
    cout<<Max(first);

    return 0;
}