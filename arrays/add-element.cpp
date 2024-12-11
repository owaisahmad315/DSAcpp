#include <iostream>
using namespace std;


struct Array
{
    int A[10];
    int size;
    int length;
    
};

void Append(struct Array *arr, int x)
{
    if(arr->length< arr->size)
        arr->A[arr->length++] = x;
}


void Display(struct Array arr)
{
    int i;
    cout<<"elements are "<<endl;
    for(i=0; i<arr.length; i++)
        cout<<arr.A[i];
};

int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};
    
    Append(&arr, 13);
    Display(arr);


    return 0;
}