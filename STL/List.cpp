#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> v = {2,4,6,8,10};
    v.pop_back();
    v.push_front(13);


    //using for each loop
    cout<<"Using for each loop ";
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;

    list<int>::iterator itr;  // iterator class
    cout<<"Using iterator class ";
    for(itr=v.begin(); itr != v.end(); itr++)
        cout<<*itr<<" ";

    return 0;
}