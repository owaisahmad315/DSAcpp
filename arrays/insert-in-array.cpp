#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i = arr->length; i> index; i--)
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] =x;
    arr->length++;
    
}


void Display(struct Array arr)
{
    int i;
    cout<<"elements are "<<endl;
    for(i=0; i<arr.length; i++)
        cout<<arr.A[i]<<",";
};


int main()
{
    struct Array arr = {{2,4,6,8,10}, 10, 5};
    int index = 4;
    int x = 9;

    Insert(&arr, index, x);
    Display(arr);
    return 0;
}
