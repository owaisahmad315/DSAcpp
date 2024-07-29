#include <iostream>
using namespace std;



// deletion
int Delete(int A[], int n)
{
    int i,j,x,val, temp;
    val = A[1];
    x=A[n];
    A[1] = A[n];
    A[n] = val;
    i=1; j=i*2;
    



    while(j<n-1)
    {
        if(A[j+1] > A[j])
            j = j+1;
        if(A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
        }
        else
            break;   
    }
    return val;
}



// insertion in max heap
void insert(int A[], int n)
{
    int temp;
    int i = n;

    temp = A[n];

    while(i>1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}



int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
// insertion
    int i;
    for(i =2; i<=7; i++) 
        insert(H,i);
  // deletion  
    for(i=7; i>1; i--)
    {
        Delete(H,i);
    }
    // display values
    cout<<endl;
    for(i=1; i<=7; i++)
        cout<<H[i]<<" ";
    return 0;
}