#include <iostream>
#include <cmath>
using namespace std;

struct Array 
{
    int A[10];
    int size;
    int length;
};

int BinarySearch(struct Array arr, int l, int h, int key)
{
    int mid;
    if(l<=h)
    {   
        mid = floor((l+h)/2);
        if(key==arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            return BinarySearch(arr, l, mid -1, key);
        else
            return BinarySearch(arr,  mid + 1, h, key);
    }
    else
        return -1;      
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10,5};
    int key = 7;
    int result = BinarySearch(arr, 0, arr.length-1, key);

    if(result != -1)
      cout<<"Binary search key index is "<<result;
    else
      cout<<"Binary search key is not found.."<<result;

    return 0;
}