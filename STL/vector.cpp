#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {2,4,6,8,10};

    //using for each loop
    cout<<"Using for each loop ";
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;

    vector<int>::iterator itr;  // iterator class
    cout<<"Using iterator class ";
    for(itr=v.begin(); itr != v.end(); itr++)
        cout<<*itr<<" ";

    return 0;
}