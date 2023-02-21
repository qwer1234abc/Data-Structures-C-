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


/** Types of Recursions
 * Tail Recursion
 * Head Recursion
 * Tree Recursion
 * Indirect Recursion
 * Nested Recursion
 */

// Tail Recursion
// If a recursive function is calling itself and the recursive call is the last statement in the function it is a Tail Recursion
// Everything is performed at calling time and at returning time nothing is performed at all
void TailRecursion(int n)
{
	if (n > 0)
	{
		cout << n << endl;
		TailRecursion(n - 1);
	}
}


/** Compare Tail Recursion with loop
 * Time is the same of O(n)
 * Space taken for Tail Recursion is O(n) but for loop is O(1)
 * If ever a Tail Recursion is needed it is better to convert it into a loop as it is more efficient
 */


// Head Recursion
// Recursive call is the first statement in the function call
// Opposite of Tail Recursion as it does not need to perform anything at the time of calling but at the time of returning


void HeadRecursion(int n)
{
	if (n > 0)
	{
		HeadRecursion(n - 1);
		cout << n << endl;
	}
}


/** Compare Head Recursion with loop
 * Not easily converted into a loop
 */


// Linear Recursion
// Function is calling itself only one time

// Tree Recursion
// Function is calling itself more than one time

void TreeRecursion(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		TreeRecursion(n - 1);
		TreeRecursion(n - 1);
	}
}


/** Tree Recursion Notes
 * Number of calls = O(2n)
 * If n = 3, 15 calls in 1, 2, 4, 8 in each level
 * 2**n+1 -1
 */


// Indirect Recursion
// May be more than one function calling one another in a circular fashion
void IndirectRecursionB(int n);
void IndirectRecursionA(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		IndirectRecursionB(n - 1);
	}
}

void IndirectRecursionB(int n)
{
	if (n > 1)
	{
		cout << n << " ";
		IndirectRecursionA(n / 2);
	}
}


// Nested Recursion
// Pass parameter as a recursive call

int NestedRecursion(int n)
{
	if (n > 100)
	{
		return n - 10;
	}
	else
	{
		return NestedRecursion(NestedRecursion(n + 11));
	}

}


// Sum of first 'n' Natural Numbers 

int SumOfNaturalNumber(int n)
{
	if (n == 0)
	{
		return 0;
	}else
	{
		return SumOfNaturalNumber(n - 1) + n;
	}
}



// Factorial Of A Number
int FactorialOfNumber(int n)
{
	if (n == 0)
	{
		return (1);
	}else
	{
		return FactorialOfNumber(n - 1) * n;
	}
}








































int main()
{

	BasicRecursion(3);

	int r = staticRecursion(3);
	cout << r << endl;

	r = staticRecursion(3);
	cout << r << endl;

	HeadRecursion(3);
	TreeRecursion(3);
	IndirectRecursionA(20);
	cout << endl << NestedRecursion(30) << endl;

	cout << SumOfNaturalNumber(5) << endl;

	cout << FactorialOfNumber(5) << endl;



    return 0;
}

