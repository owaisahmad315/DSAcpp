#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

void insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if(root == NULL)
    {
        p= new Node;
        p->data = key;
        p->lchild=p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r=t;
        if(key < t->data)
            t=t->lchild;
        else if(key > t->data)
            t=t->rchild;
        else
            return;
    }

    p= new Node;
    p->data = key;
    p->lchild=p->rchild = NULL;

    if(key<r->data) r->lchild=p;
    else r->rchild=p;

    
}

void inOrder(struct Node *p)
{
    if(p)
    {
        inOrder(p->lchild);
        cout<<" "<<p->data;
        inOrder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;
    while(t!=NULL)
    {
        if(key == t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}   

int main()
{
    struct Node *temp;

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    inOrder(root);
    cout<<endl;
    
    temp = Search(20);
    if(temp!=NULL)
        cout<<"Element "<<temp->data<<" found";
    else
        cout<<"Element not found";


    return 0;
}