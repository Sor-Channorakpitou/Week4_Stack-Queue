#include <iostream>
#include "Queue.hpp"
using namespace std;
int main()
{
    //Cafeteria Line in the listed
    Linkedlist_OrderQueue Listed;
    for(int i=0;i<10;i++)
    {
        Listed.enqueue(i);
    }
    Listed.traversal();
    cout << "Length: "<< Listed.getlength() << endl;
    Listed.dequeue();
    Listed.traversal();
    cout << "Length: "<< Listed.getlength() << endl;
    return 0;
}