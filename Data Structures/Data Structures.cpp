// Data structure is the arrangement of collection data items so that operations on them can be done efficiently.

#include <iostream>
using namespace std;


// Recursion happens when a function calls it self can be for ascending and descending and musts have a base condition or a infinite loop will occur
void BasicRecursion(int n)
{
	if (n > 0)
	{
		cout << n << endl;
		BasicRecursion(n - 1);
	}
}
// static and global variables in Recursion:
// int x = 0 (global variable) same result as static
int staticRecursion(int n)
{
	// x here will only have a single copy unlike n, x will be n here for every recursion
	static int x = 0;
	if (n > 0)
	{
		x++;
		return staticRecursion(n - 1) + x;
	}
	return 0;
}









int main()
{

	BasicRecursion(3);

	int r = staticRecursion(3);
	cout << r;

	r = staticRecursion(3);
	cout << r;






    return 0;
}

