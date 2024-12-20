#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

bool isSorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
          return false;

    }
    return true;
 }


int main()
{
    struct Array arr = {{1,2,3,4,5,6,7,8}, 10, 8};
    cout<<isSorted(arr);

    return 0;
}