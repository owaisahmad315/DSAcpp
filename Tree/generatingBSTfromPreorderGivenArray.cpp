#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
};
struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
};

struct Node *root = NULL;

int stackTop(struct Stack st)
{
        return st.S[st.top];
}

void push(struct Stack *st, *x)
{
        st->top++;
        st->S[st->top] = x;
}

int pop(struct Stack *st)
{
    int x = -1;
      x = st->S[st->top--];
    return x;
}
void createPre(int pre[], int n)
{
    Stack stk;
    Node *t;
    int i;
    struct Node *p;

    root = new Node;
    root->data =pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i<n)
    {
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data= pri[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&stk, p);
            p=t;
        }
         else 
        {
            if(pre[i] > p->data && pre[i] < stackTop(stk)->data)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = pop(&stk);
            }
        }   
    }
}



int main()
{

    int array = [30,20,10,15,25,40,50,45];
    createPre(array)

    return 0;
}