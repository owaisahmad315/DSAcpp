#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};


void Reverse(struct Array *arr)
{
    int i,j,temp;
    for(i=0, j=arr->length-1; i<j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Display(struct Array arr)
{
    int i;
    for(i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
}

int main()
{
    struct Array arr = {{1,2,3,4,5,6,7,8,9,10},10, 10};
    cout<<"The Array ";
    Display(arr);
    cout<<endl;
    cout<<"The Reversed Array ";
    Reverse(&arr);
    Display(arr);

    return 0;
}