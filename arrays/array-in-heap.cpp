#include <iostream>
using namespace std;

int main()
{
    int *p;
    p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
    
    int i;
    for(i=0; i<4; i++ )
        cout<<"array elements in HEAP : "<<p[i]<<endl;
    return 0;
};