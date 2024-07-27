#include <iostream>
using namespace std;

struct Node
{
    struct Node* lchild;
    int data;
   struct Node* rchild;
    int height;
};

struct Node* root = NULL;
// function to calculate the height of left and right sub tree
int NodeHeight(struct Node* p)
{
    int hl, hr;
    hl = p && p->lchild? p->lchild->height : 0;
    hr = p && p->rchild? p->rchild->height : 0;

    return hl>hr ? hl + 1 : hr + 1;
}

// function to calculate the balance factor for each node
int BalanceFactor(struct Node* p)
{
     int hl, hr;
    hl = p && p->lchild? p->lchild->height : 0;
    hr = p && p->rchild? p->rchild->height : 0;

    return hl - hr;
}

// left left rotation function

struct Node* LLrotation(struct Node* p)
{
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;
}
// // left right rotation function

struct Node* LRrotation(struct Node* p)
{
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;

    
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;

    plr->rchild = p;
    plr->lchild = pl;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;
    return plr;

}
// right right rotation function

struct Node* RRrotation(struct Node* p)
{
     struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p)
         root = prl;
    return prl;


}
// // right left rotation function

struct Node* RLrotation(struct Node* p)
{
     struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;

    
    p->rchild= prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild =p;
    prl->rchild = pr;


    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;
    return prl;


    return :
}


struct Node* Rinsert(struct Node* p, int key)
{
    struct Node* t = NULL;
    if(p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }

    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLrotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRrotation(p);
    // else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild)== 1)
    //     return RLrotation(p);
    // else(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    //     return RRrotation(p);

    return p;
}

int main()
{
    root = Rinsert(root, 50);
    Rinsert(root,10);
    Rinsert(root,20);

    return 0;
}