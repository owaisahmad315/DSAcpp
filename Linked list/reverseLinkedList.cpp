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

// function to calculate the length of a linkedlist
int Length(Node *p) 
{
    int length = 0;
    while (p!= NULL)
    {
        length++;
        p=p->next;
    }
    return length;
}

// this function is just reversing the elements in the linked list not the actual nodes
void ReverseElements(Node *p)
{
  Node *q =p;
  int *A, i =0;

  int sizeOfLL = Length(first);
  A = new int[sizeOfLL];

  while (q != NULL)    
  {
    A[i] = q->data;
    q=q->next;
    i++;
  }
  q = p;
  i--;
  while (q != NULL)
  {
    q->data = A[i--];
    q= q->next;
  }

  delete []A; 
}

void ReverseNodes(Node *p)
{
    Node *r, *q;
    r=q=NULL;
    while (p != NULL)
    {
        r=q;
        q=p;
        p= p->next;
        q->next =r;
    }
    first = q;
    
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
    int A[] = {10,20,30,40,50};
    
    Create(A, 5);
    Display(first);

    ReverseNodes(first);
    Display(first);

    return 0;
}