#include <iostream>
using namespace std; 

struct Node {
    int data;
    Node* next;
};

 Node *first, *Second, *third = NULL;

void Create(int A[], int n) {
    int i;        
    Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Create1(int A[], int n) {
    int i;        
    Node *t, *last;

    Second = new Node;
    Second->data = A[0];
    Second->next = NULL;
    last = Second;

    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void Merge(Node *p, Node *q)
{
    Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p != NULL)
        last->next = p;
    else   
        last->next = q;
    
}


void Display(Node* p) {
    cout<< ": ";
    while (p != NULL) {
        cout << p->data << " "; 
        p = p->next;
    }
}


int main()

{
    int A[] = {10,20,30,40,50,60};
    int B[] = {15,25,35,45};
    
    Create(A, 6);
    Create1(B,4);

    cout<<"First Linked List :";
    Display(first);

    Merge(first, Second);
    
cout<<endl;
    cout<<"Second Linked List :";
    Display(Second);
cout<<endl;
    cout<<"Merged Linked List :";
    Display(third);

    return 0;
}