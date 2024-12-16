#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int main()
{
    struct Array arr = {{4,3,49,-1,6}, 10, 5};
    int minNumber = Min(arr);
    cout<<"The Min Number in an array is "<<minNumber;

    return 0;
}