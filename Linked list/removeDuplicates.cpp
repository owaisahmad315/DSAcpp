#include <iostream>
using namespace std; 

struct Node {
    int data;
    Node* next;
};

 Node *first = NULL;

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

void RemoveDuplicates(Node *p)
{
    Node *q = p->next;
    while (q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        
    }
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
    int A[] = {2,2,3,3,4,5,5,5,5,6};
    Create(A, 10);
    RemoveDuplicates(first);
    Display(first);

    return 0;
}