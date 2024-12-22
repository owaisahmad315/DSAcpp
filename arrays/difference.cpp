#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new Array;
    while(i<arr1->length && j < arr2->length)

    if(arr1->A[i] < arr2->A[j])
        arr3->A[k++] = arr1->A[i++]; 
    else if(arr2->A[j] <  arr1->A[i])
        j++;
    else
    {
        i++;
        j++;
    }

    for ( ;i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for ( ;j< arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
};

void Display(struct Array arr3)
{
    for(int i= 0; i<arr3.length; i++)
        cout<<arr3.A[i]<<" ";
}

int main()
{
    struct Array arr1 = {{2,6,10,15,25}, 10, 5};
    struct Array arr2 = {{3,5,7,15,20}, 10, 5};
    struct Array *arr3;

    arr3 = Difference(&arr1, &arr2);
    cout<<endl;
    Display(*arr3);

    return 0;
}
