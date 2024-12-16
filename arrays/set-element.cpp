#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
    else
        cout<<"Invalid index";
}

void Display(struct Array arr)
{
    int i;
    cout<<"Elements are ";
    for (i = 0; i<arr.length; i++)
    
        cout<<arr.A[i]<<" ";
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};
    Display(arr);
    Set(&arr, 0, 55);
    cout<<endl;
    Display(arr);

    return 0;
}