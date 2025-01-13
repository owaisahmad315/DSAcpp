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

void Concat(Node *p, Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;  
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
    int A[] = {1,2,3,4,5,6};
    int B[] = {55,33,44};
    
    Create(A, 6);
    Create1(B,3);

    cout<<"First Linked List :";
    Display(first);

    Concat(first, Second);
    
cout<<endl;
    cout<<"Second Linked List :";
    Display(Second);
cout<<endl;
    cout<<"Concatenated Linked List :";
    Display(third);

    return 0;
}