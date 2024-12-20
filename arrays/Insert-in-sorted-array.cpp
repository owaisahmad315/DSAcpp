#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void InsertInSortedArray(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        int i = arr->length-1;
        while(arr->A[i] > x)
           {
            arr->A[i+1] = arr->A[i];
            i--;
           } 
           arr->A[i+1] =x;
           arr->length++;

    } else
    {
        cout<<"Sorry memory is already full";
    }
}

void Display(struct Array arr)
{
    cout << "Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

int main()
{
    struct Array arr = {{1,2,3,4,5,6,8,10,12}, 10, 9};
    Display(arr);
    cout<<endl;
    InsertInSortedArray(&arr, 7);
    cout<<endl;
    Display(arr);

    return 0;
}