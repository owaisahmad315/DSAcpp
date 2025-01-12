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

// iterative
Node *Search(Node *p, int key)
{
    while(p != NULL)
    {
        if(p->data == key)
            return p;
        else
            p = p->next;
    }
    return 0;
}

// recursive function to search for a key in a linked list
Node *Rsearch(Node *p, int key)
{
    if(p == NULL)
        return 0;
    else if(p->data == key)
        return p;
    else
        return Rsearch(p=p->next, key);
}


int main()
{
    int A[] = {3,5,19,9,10,15};
    Create(A,6);
    //cout<<Search(first, 11);
    cout<<Rsearch(first, 10);

    return 0;
}