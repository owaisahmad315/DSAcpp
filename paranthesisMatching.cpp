#include <iostream>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
};

Node *top = NULL;

void push(char x)
{
    struct Node *t;
    t = new Node;

    if (t == NULL)
        cout << "Stack is FULL" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
        cout << "Stack is EMPTY" << endl;
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete (t);
    }
    return x;
}

void Display()
{
    struct Node *p = top;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            else
            {
                pop();
            }
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[] = "((a+b)*(c-d))";
    cout << isBalanced(exp);
    return 0;
}
