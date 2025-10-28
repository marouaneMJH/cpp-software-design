#include "./../include/index.h"
#include <list>


void print(int x)
{
    cout<< x<< " ";
}

int main()
{
    HList list;
list.add(42);           // int
list.add("Hello");      // string
list.add(3.14);         // double
list.add(true);         // bool
list.add('A');          // char
list.add(2.5f);         // float
list.add(1000000L);     // long

    cout << list;

    return 0;
}
