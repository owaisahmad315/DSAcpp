#include <iostream>
using namespace std;

struct Array 
{
    int A[10];
    int size;
    int length;
};

void Delete(struct Array *arr, int index)
{    int x=0;
    x=arr->A[index];
    cout<<"index is "<<x<<endl;

    if(index <= arr->length - 1)
    {
        for(int i = index; i<= arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }

    cout<<" the deleted value is "<<x<<endl;
        

}

void Display(struct Array arr)
{
    for(int i =0; i<arr.length; i++)
        cout<<arr.A[i];
}


int main()
{
    struct Array arr={{2,4,6,8,10}, 10, 5};

    Delete(&arr, 2);
    Display(arr);

    return 0;
}