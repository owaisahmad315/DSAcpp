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

// // this function will move the key to the Head of the linked list if found,
// so, when next time you search the same key it can be find in constant time.
Node *Search(Node *p, int key)
{   
    Node *q = NULL;

    while(p != NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        else
            q = p;
            p = p->next;
    }
    return NULL;
    
}


void Display(Node *p)
{
    cout<<"Node data :";
    while(p)
    {
        cout<< p->data<<" ";
        p=p->next;
    }
}



int main()
{
    int A[] = {3,5,19,9,10,15};
    Create(A,6);
    Display(first);
    cout<<endl;
    cout<<Search(first, 10);
    cout<<endl;

    Display(first);
    

    return 0;
}