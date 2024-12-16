#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int main()
{
    struct Array arr = {{2,3,49,5,6}, 10, 5};
    int maxNumber = Max(arr);
    cout<<"The Max Number is an array is "<<maxNumber;

    return 0;
}