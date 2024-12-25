#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> v = {2,4,6,8,10,10};
    


    //using for each loop
    cout<<"Using for each loop ";
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;

    set<int>::iterator itr;  // iterator class
    cout<<"Using iterator class ";
    for(itr=v.begin(); itr != v.end(); itr++)
        cout<<*itr<<" ";

    return 0;
}