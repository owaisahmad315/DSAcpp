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



// recursive insertion
struct Node *Rinsert(struct Node *p, int key)
{

    struct Node *t = NULL;
    if(p == NULL)
    {
        t = new Node();
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    else if(key < p->data)
        p->lchild = Rinsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild, key);
        
    return p;
}

// calculate height of a tree or subtree
int Height(struct Node *p)
{
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y ? x+1 : y+1;
}

// predecessor function 
struct Node *InPre(struct Node *p)
{
    while(p && p->rchild != NULL)
        p=p->rchild;
    return p;
}


// Successor function 
struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild != NULL)
        p=p->lchild;
    return p;
}

// deltetion using recursion
struct Node *Delete(Node *p, int key)
{
    struct Node *q;

    if(p == NULL)
        return NULL;

    // check for leaf node, if root node is leaf node then delete this
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        delete(p);
            return NULL;
    }
         
    // search
    if(key < p->data)
        p->lchild=  Delete(p->lchild, key);
    else if(key> p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {   // InOrder predecessor and successor
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp;

    // insert(10);
    // insert(5);
    // insert(20);
    // insert(8);
    // insert(30);

    // recursive insertion function call
    root=Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,20);
    Rinsert(root,8);
    Rinsert(root,30);

    Delete(root, 10);
    
    cout<<"Elements are: "; 
    inOrder(root);

    cout<<endl;
    
     
    
    temp = Search(20);
    if(temp!=NULL)
        cout<<"Element "<<temp->data<<" found";
    else
        cout<<"Element not found";


    return 0;
}