#include "./../include/index.h"
#include <list>




void print(int x)
{
    cout<< x<< " ";
}

int main()
{


    //create list
    list<int> coll = {1,2,3,4,5,6,7,8,9};

    //print in normal order
    for_each(coll.begin(),coll.end(), //range
             print); //operation
    cout <<endl;

    //print in reverse order
    for_each(coll.rbegin(),coll.rend(), //range
             print); //operation
    cout <<endl;



    //find pos of element
    list<int>::const_iterator pos;
    pos=find(coll.cbegin(),coll.cend(),1);

    //print value to which iterator pos refers
    cout << "pos: "<<*pos <<endl;
    
    //convert iterator to reverse iterator rpos
    list<int>:: rpos(pos);

    // Reverse the list
    reverse(coll.begin(), coll.end());

    // Alternatively, the list class has a built-in reverse method
    // coll.reverse();

    // Update positions after reversing
    pos = find(coll.cbegin(), coll.cend(), 5);
    rpos = list<int>::const_reverse_iterator(pos);
    
    //print value to which reverse iterator rpos refers
    cout << "rpos: "<<*rpos <<endl;


    return 0;
}
