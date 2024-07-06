 #include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;

};


void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void enqueue(struct Queue *q, int x)
{
    if(q->rear==q->size - 1)
        cout<<"Queue is Full";
    else
    {
        q->front++;
        q->Q[q->front] = x; 
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    cout<<"Queue is already Empty";
    else
    {
        x=q->Q[q->front];
        q->front--;

        

    }
    return x;
}

void display(struct Queue q)
{
    int i;
    for(i = q.front+1; i <= q.rear; i++)
        cout<<q.Q[i]<<endl;
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    
    cout<<"Queue Elememts are: "<<endl;
    display(q);

    cout<<"the deleted value is: "<<dequeue(&q)<<endl;
    cout<<"After deleting one element, now the queue is: "<<endl;
    display(q);

    return 0;
}