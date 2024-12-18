#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Reverse(struct Array *array1, struct Array *array2)
{
    int i,j;
    for(i = array1->length-1, j = 0; i>=0; i--, j++)
    {
        array2->A[j] = array1->A[i];
        array2->length++;
    }
}

void Reverse1(struct Array *array1, struct Array *array2)
{
    int i;
    for(i =0; i<array2->length; i++)
    {
        array1->A[i] =array2->A[i];
    
    }
}
void Display(struct Array arr)
{
    for(int i = 0; i<arr.length; i++)
    {
        cout<<arr.A[i]<<",";
    }
        
}

int main()
{
    struct Array array1 ={{2,4,6,8,10,12,14,16,18,20}, 10, 10};
    struct Array array2 = {{},10,0};

    cout<<"Array1 elements are ";
    Display(array1);
    cout<<endl;

    cout<<"Array2 elements are ";
    Reverse(&array1,&array2);
    Display(array2);
    cout<<endl;
    cout<<"Array1  elements are reversed ";
    Reverse1(&array1,&array2);
    Display(array1);



    return 0;
}