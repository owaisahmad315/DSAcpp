#include <iostream>
using namespace std;


int main()
{
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
   int i;

    int *q = new int[10];

    for(i=0; i<5; i++)
    {
        q[i] = p[i];
    }
    delete []p;

    p=q;
    
    p[5] = 6;
    p[6] = 7;
    p[7] = 8;
    p[8] = 9;
    p[9] = 10;
    q = NULL;
    for(i=0; i<10; i++)
      cout<<"Now P values "<<p[i]<<endl;

    return 0;
}