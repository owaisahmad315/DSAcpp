#include <iostream> // include the input-output stream library
using namespace std; // use the standard namespace

#include "queueHeaderFile.h" // include the custom queue header file

// Define the Tree class
class Tree 
{
    public:
        Node *root; // declare a pointer to the root node
        Tree() { // constructor to initialize the root to NULL
            root = NULL;
        }
        void CreateTree(); // function to create the tree
        void Preorder(Node *p); // function to traverse the tree in preorder
        void Postorder(Node *p); // function to traverse the tree in postorder
        void Inorder(Node *p); // function to traverse the tree in inorder
        void Levelorder(Node *p); // function to traverse the tree in level order
        int Height(Node *root); // function to calculate the height of the tree
  };

// Function to create the tree
void Tree::CreateTree()
{
    Node *p, *t; // declare node pointers
    int x; // declare a variable to hold data
    Queue q(100); // create a queue with a size of 100

    // ask user to input the root value
    cout << "Enter root value: ";
    cin >> x; // read the root value
    root = new Node; // allocate memory for the root node
    root->data = x; // assign data to the root node
    root->lchild = root->rchild = NULL; // set left and right child of root to NULL
    q.enqueue(root); // enqueue the root node

    // loop until the queue is empty
    while (!q.isEmpty())
    {
        p = q.dequeue(); // dequeue a node
        // ask user to input the left child value
        cout << "Enter left child of " << p->data << ": ";
        cin >> x; // read the left child value
        if (x != -1)
        {
            t = new Node; // allocate memory for the left child node
            t->data = x; // assign data to the left child node
            t->lchild = t->rchild = NULL; // set left and right child of left child node to NULL
            p->lchild = t; // link the left child node to the parent node
            q.enqueue(t); // enqueue the left child node
        }

        // ask user to input the right child value
        cout << "Enter right child of " << p->data << ": ";
        cin >> x; // read the right child value
        if (x != -1)
        {
            t = new Node; // allocate memory for the right child node
            t->data = x; // assign data to the right child node
            t->lchild = t->rchild = NULL; // set left and right child of right child node to NULL
            p->rchild = t; // link the right child node to the parent node
            q.enqueue(t); // enqueue the right child node
        }
    }
}

// Function to traverse the tree in preorder
void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " "; // visit the root node
        Preorder(p->lchild); // traverse the left subtree
        Preorder(p->rchild); // traverse the right subtree
    }
}

// Function to traverse the tree in inorder
void Tree::Inorder(Node *p)
{
    if (p) 
    {
        Inorder(p->lchild); // traverse the left subtree
        cout << p->data << " "; // visit the root node
        Inorder(p->rchild); // traverse the right subtree
    }
}

// Function to traverse the tree in postorder
void Tree::Postorder(Node *p)
{
    if (p) 
    {
        Postorder(p->lchild); // traverse the left subtree
        Postorder(p->rchild); // traverse the right subtree
        cout << p->data << " "; // visit the root node
    }
}

// Function to traverse the tree in level order
void Tree::Levelorder(Node *root)
{
    Queue q(100); // create a queue with a size of 100
    cout << root->data << " "; // visit the root node
    q.enqueue(root); // enqueue the root node

    // loop until the queue is empty
    while (!q.isEmpty())
    {
        root = q.dequeue(); // dequeue a node
        if (root->lchild)
        {
            cout << root->lchild->data << " "; // visit the left child node
            q.enqueue(root->lchild); // enqueue the left child node
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " "; // visit the right child node
            q.enqueue(root->rchild); // enqueue the right child node
        }
    }
}

// Function to calculate the height of the tree
int Tree::Height(Node *root)
{
    int x = 0, y = 0; // declare variables to hold the height of left and right subtrees
    if (root == nullptr) // if the root is NULL, return 0
        return 0;
    x = Height(root->lchild); // calculate the height of the left subtree
    y = Height(root->rchild); // calculate the height of the right subtree
    if (x > y) // if the left subtree is taller, return the height of the left subtree + 1
        return x + 1;
    else // if the right subtree is taller, return the height of the right subtree + 1
        return y + 1;
}

 

// Main function
int main()
{
    Tree t; // create a Tree object
    t.CreateTree(); // create the tree
    cout << "Preorder: ";
    t.Preorder(t.root); // traverse the tree in preorder
    cout << endl;

    cout << "Inorder: ";
    t.Inorder(t.root); // traverse the tree in inorder
    cout << endl;

    cout << "Postorder: ";
    t.Postorder(t.root); // traverse the tree in postorder
    cout << endl;

    cout << "Levelorder: ";
    t.Levelorder(t.root); // traverse the tree in level order
    cout << endl;

     

     

    return 0;  
}
