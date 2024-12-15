#include <iostream>
#include <cmath>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int BinSearch(struct Array arr, int key)
{
    int l,h,mid;
    l = 0;
    h= arr.length-1;
    
   
   
    while (l<= h)
    {
        mid = floor((l+h)/2);
        if(key == arr.A[mid])
        {
            return mid;
        }
         
        else if(key < arr.A[mid])
        {
            h = mid - 1;
        }
            
        else
        {
            l = mid + 1;
        } 
            
    }
    return -1;
}

int main()
{
    struct Array arr ={{2,3,4,5,6}, 10,5};
    int key = 5;
    
    int result = BinSearch(arr, key);
    if(result != -1)
    cout<<"Binary search key index is "<<result;
    else
        cout<<"Binary search key is not found...!!! ";

    return 0;
}