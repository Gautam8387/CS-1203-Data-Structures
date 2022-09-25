//C++ Program for understanding pointers

// Pointers Arithmetic

#include <iostream>
using namespace std;
int main(){
	int x = 3;
	int *y;
	y = &x;
	// *y is the value at the address of x
	*y = *y + 1;
	// this will change the value of x
	cout<<*y<<x;
	//both will print 4. Changed value of x
	return 0;
}
