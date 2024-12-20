#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout << "Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}
 

void LeftShiftRotation(struct Array *arr)
{
    int i,temp;
    temp = arr->A[0];
    for(i=0; i<arr->length; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}

int main()
{
    struct Array arr = {{1,2,3,4,5,6,8,10,13,15}, 10, 10};
    cout<<"Actual Array ";
    Display(arr);
    cout<<endl;

    cout<<"After left rotation ";
    LeftShiftRotation(&arr);
    Display(arr);

    return 0;
}