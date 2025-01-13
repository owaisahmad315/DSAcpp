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

int Delete(Node *p, int pos)
{
  Node *q = NULL;
  int x = -1, i;
  if(pos < 1 || pos > Length(first) )
  {
    return -1;
  }  
  if(pos == 1)
  {
    q = first;
    x = first->data;
    first = first->next;
    delete q;
    return x;
  }
  else
  {
    for(i = 0; i<pos-1; i++)
    {
        q=p;
        p = p->next;
    }
    q->next = p->next;
    x=p->data;
    delete p;
    return x;
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
    Delete(first, 4);
    Display(first);

    return 0;
}