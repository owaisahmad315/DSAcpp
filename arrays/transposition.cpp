// this program is used to improve the linerar search in an array

#include <iostream>
using namespace std;

struct Array 
{
    int A[10];
    int size;
    int length;
};

int Swap(int *x, int *y)
{   
    int temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}

int Transposition(struct Array *arr, int key)
{ int i;
    for(i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
            
        }
        
    }
    return i-1;
}
void Display(struct Array arr)
{
    for(int i = 0; i< arr.length; i++)
        cout<<arr.A[i]<<",";
}

int main()
{
    struct Array arr ={{2,4,6,8,10},10,5};
    cout<<"Key before transposition";
    Display(arr);
    int key = 8;
    cout<<Transposition(&arr, key);
    cout<<endl;
    cout<<"Key After transposition";
    Display(arr);
    return 0;
}