//C++ Program for understanding pointers 
// An insight on working of pointers

#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int x = 5;
    int *y;
    y = &x;
    cout<<y<<endl;
    cout<<*y<<endl;
    cout<<&y<<endl;
    cout<<x<<endl;
    cout<<&x<<endl;

    return 0;
}
