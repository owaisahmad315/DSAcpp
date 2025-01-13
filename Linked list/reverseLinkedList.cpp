#include <iostream>
using namespace std; 

// Here all the three types of reversing a linked list are available, 
// to use them just make a function a call to the desired function.

struct Node {
    int data;
    Node* next;
};

 Node *first = NULL;
// this Create function is used to create a linked list
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

// this function is just reversing the elements in the linked list,
// not the actual nodes
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

// this function is reversing the whole node is a linked list
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

// using recursion nodes are being reversed in a linked list
void ReverseNodesUsingRecursion(Node *q, Node *p)
{
    if(p != NULL)
    {
        ReverseNodesUsingRecursion(p, p->next);
        p->next = q;
    }
    else
    {
        first =q;
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
    int A[] = {10,20,30,40,50};
    
    Create(A, 5);
    Display(first);

    ReverseNodesUsingRecursion(NULL, first);
    Display(first);

    return 0;
}