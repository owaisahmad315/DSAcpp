#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int Sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i<arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

int main()
{
    struct Array arr ={{2,4,6,8,10},10,5};
    cout<<Sum(arr);
}