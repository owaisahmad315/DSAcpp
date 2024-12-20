#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};


void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
} 

void MoveNegativeToLeft(struct Array *arr)
{
    int i = 0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if(i<j)
        {
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

void Display(struct Array arr)
{
    cout<<"elements are :";
    for(int i = 0; i<arr.length; i++ )
        cout<<arr.A[i]<<" ";
}

int main()
{
    struct Array arr={{-1,2,3,4,-6,7,2,1,-3,-4}, 10, 10};
    Display(arr);
    cout<<endl;

    MoveNegativeToLeft(&arr);
    Display(arr);


    return 0;
}