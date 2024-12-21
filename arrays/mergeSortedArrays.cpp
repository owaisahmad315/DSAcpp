#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = new Array;
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]< arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for( ; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for( ; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

        arr3->length = arr1->length + arr2->length;
        return arr3;
    
}

void Display(struct Array arr3)
{
    for(int i = 0; i<arr3.length; i++)
        cout<<arr3.A[i]<<" ";
}
int main()
{
    struct Array arr1 = {{3,8,16,20,25}, 10, 5};
    struct Array arr2 = {{4,10,12,22,23}, 10, 5};
    struct Array *arr3;

    arr3 = Merge(&arr1,&arr2);
    cout<<endl;
    Display(*arr3);

    delete arr3;
    return 0;
}