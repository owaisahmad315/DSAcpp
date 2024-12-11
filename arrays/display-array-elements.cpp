
#include <iostream>
using namespace std;

struct Array 
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    cout<<"elements are "<<endl;
    for(i=0; i<arr.length; i++)
        cout<<arr.A[i];
};




int main()

{   struct Array arr;
    int n,i;
    
    cout<<"Enter the size of the array"<<endl;
    cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;


    cout<<"Enter the number of elements "<<endl;
        cin>>n;
        
    cout<<"Enter all elements "<<endl;
     for(i=0; i<n; i++)
        cin>>arr.A[i];
        arr.length = n;
        
    display(arr);



    return 0;
}