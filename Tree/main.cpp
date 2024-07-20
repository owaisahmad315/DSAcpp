#include <iostream>
using namespace std;
#include "queueHeaderFile.h"


class Tree 
{
    public:
        Node *root;
        Tree(){
            root = NULL;
        }
        void CreateTree();
        void Preorder(Node *p);
        void Postorder(Node *p);
        void Inorder(Node *p);
        void Levelorder(Node *p);
        void Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout<<"Enter root value ";
    cin>>"%d", &x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"Enter left child of", p->data;
        cin>>"%d", &x;
        if(x! = -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout>>"Enter right child of ", p->data;
        cin>>"%d", &x;
        if(x! = -1)
        {
            t = new Node;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }   
    } 
}

void Tree::Preorder(struct Node *p)
{
    if(p)
    {
        cout<<"%d", p->data;
        Preorder(p->lchild);
        Preorder(p->rchild)
    }
}

void Tree::Inorder(struct Node *p)
{
    Inorder(p->lchild);
    cout<<"%d", p->data;
    Inorder(p->rchild)

}


void Tree::Postorder(struct Node *p)
{
    Postorder(p->lchild);
    Postorder(p->rchild)
    cout<<"%d", p->data;

}

void Tree::Levelorder(struct Node *root)
{
    Queue q(100);
    cout>>"%d", root->data;
    q.enqueue(root)

    while (!q.isEmpty)
    {
        root = q.dequeu();
        if(root->lchild)
        {
            cout<<"%d", root->lchild->data;
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            print("%d", root->rchild->data);
            q.enqueue(root->rchild); 
        }
    }
}

int Tree::Height(struct Node *root)
{
    int x=0, y=0;
    if(root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(X>y) 
        return x + 1;
    else
        return y + 1;

}

int main()
{
    return 0;
}