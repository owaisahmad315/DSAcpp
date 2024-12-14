#include <iostream>
using namespace std;

struct Array 
{
    int A[10];
    int size;
    int length;
};

int Search(struct Array arr, int key)
{
    for(int i = 0; i<arr.length; i++)
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}   

int main()
{
    struct Array arr ={{2,4,6,8,10},10,5};

    cout<<"The key is "<<Search(arr, 8);

    return 0;
}