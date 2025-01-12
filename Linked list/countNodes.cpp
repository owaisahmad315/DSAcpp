#include <iostream>
using namespace std;

struct countNodes
{
    int data;
    countNodes *next;
};
countNodes *first = NULL;

void Create(int A[], int n)
{
    int i;
    countNodes *t, *last;

    first = new countNodes;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new countNodes;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Count(countNodes *p) // iterative verison
{
    int count = 0;
    while (p!= NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int Rcount(countNodes *p)
{
    if(p == NULL)
        return 0;
    else    
        return Rcount(p->next) + 1;
}

void Display(countNodes *p)
{
    while (p != NULL)
    {
        cout<<"The data in Node :"<<p->data<<endl;
        p=p->next;
    }
    
}

int main()
{
    int A[] = {3,5,7,10,15};

    Create(A,5);
    Display(first);
    cout<<"Using iterative version "<<Count(first);
    cout<<"Using Recursion version "<<Rcount(first);

    return 0;
}