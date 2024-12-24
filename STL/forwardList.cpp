#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> v = {2,4,6,8,10};
    v.push_front(11);


    //using for each loop
    cout<<"Using for each loop ";
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;

    forward_list<int>::iterator itr;  // iterator class
    cout<<"Using iterator class ";
    for(itr=v.begin(); itr != v.end(); itr++)
        cout<<*itr<<" ";

    return 0;
}