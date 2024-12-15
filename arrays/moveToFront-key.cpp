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

int MoveToFront(struct Array *arr, int key)
{
    int i;
    for(i = 0; i<arr->length; i++)
    {
        if(key == arr->A[i])
          {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
          }  
    }
    return -1;
}

void Display(struct Array arr)
{
    for (int i =0; i<arr.length; i++)
        cout<<arr.A[i]<<",";
}

int main()
{
    struct Array arr ={{2,4,6,8,10}, 10, 5};
    int key = 8;
    cout<<"the key before moving to front ";
    Display(arr);
    cout<<endl;
    MoveToFront(&arr, key);
    cout<<"the key after moving to front ";
    Display(arr);

    
return 0;
}