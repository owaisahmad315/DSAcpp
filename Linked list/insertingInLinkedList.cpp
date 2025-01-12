#include <iostream>
using namespace std; 

struct Node {
    int data;
    Node* next;
};

 Node *first = NULL;

void create(int A[], int n) {
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

void Insert(int pos, int x)
{
    Node *p, *t;
    if(pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0)
    {   
        int i;
        p = first;
        for(i = 0; i<pos-1; i++)
        {
            p = p->next;
        }
        if(p)
        {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
        else
        {
            cout<<"Sorry position " <<pos<<" doesn't exists ";
        }
    }
}

void Display(Node* p) {
    
    while (p != NULL) {
        cout << p->data << " "; 
        p = p->next;
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);
    cout<<"The first Linked List :";
    Display(first);
    cout<<endl;
    Insert(4, 11);
    cout<<endl;
    cout<<"The Linked List after Insertion of new Node :";
    Display(first);
    

    return 0;
}
