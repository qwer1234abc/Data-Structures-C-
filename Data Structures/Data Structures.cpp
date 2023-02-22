// Data structure is the arrangement of collection data items so that operations on them can be done efficiently.

#include <iostream>
#include <algorithm>
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
	}
	else
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
	}
	else
	{
		return FactorialOfNumber(n - 1) * n;
	}
}


// Power Using Recursion
int Power(int n, int m)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return Power(n - 1, m) * m;
	}
}

// Better Method
int BetterPower(int m, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return BetterPower(m * m, n / 2);
	}
	else
	{
		return m * BetterPower(m * m, (n - 1) / 2);
	}
}


// Taylor Series Using Recursion

int TaylorSeries(int x, int n)
{
	static int p = 1, f = 1;
	int r;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		r = TaylorSeries(x, n - 1);
		p = p * x;
		f = f * n;
		return r + p / f;
	}
}





class Array1 {

private:
	int* A;
	int size;
	int length;

public:
	Array1(int size) {
		this->size = size;
		A = new int[size];
	}

	void create() {
		cout << "Enter number of elements: " << flush;
		cin >> length;
		cout << "Enter the array elements: " << endl;
		for (int i = 0; i < length; i++) {
			cout << "Array element: " << i << " = " << flush;
			cin >> A[i];
		}
	}

	void display() {
		for (int i = 0; i < length; i++) {
			cout << A[i] << " ";
		}
	}
	void append(Array1* arr, int x)
	{
		if (arr->length < arr->size)
		{
			arr->A[arr->length++] = x;
		}
		display();
	}

	void insert(Array1* arr, int index, int x)
	{
		int i;
		if (index >= 0 && index <= arr->length)
		{
			for (i = arr->length; i > index; i--)
			{
				arr->A[i] = arr->A[i - 1];
			}
			arr->A[index] = x;
			arr->length++;
		}
		display();
	}

	void del(Array1* arr, int index)
	{
		int i;
		if (index >= 0 && index <= arr->length)
		{
			for (i = index; i < length - 1; i++)
			{
				A[i] = A[i + 1];
			}
			arr->length--;
		}
		display();
	}
	int linearSearch(Array1* arr, int x)
	{
		for (int i = 0; i < arr->length; i++)
		{
			if (A[i] == x)
			{
				return i;
			}
		}
		return -1;
	}
	// Transposition Linear Search (Improved)
	int improvedLinearSearch(Array1* arr, int x)
	{
		for (int i = 0; i < arr->length; i++)
		{
			if (A[i] == x)
			{
				swap(A[i], A[i - 1]);
				return i - 1;
			}
		}
		return -1;
	}

	// Move to front Linear Search
	int anotherImprovedLinearSearch(Array1* arr, int x)
	{
		for (int i = 0; i < arr->length; i++)
		{
			swap(A[i], A[0]);
			return 0;
		}
		return -1;
	}

	int binarySearch(int l, int h, int key)
	{
		while (l <= h)
		{

			int m = (l + h) / 2;
			if (key == A[m])
			{
				return m;
			}
			else if (key < A[m])
			{
				h = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return -1;
	}

	int recursiveBinarySearch(int l, int h, int key)
	{
		if (l <= h)
		{
			int m = (l + h) / 2;
			if (key == A[m])
			{
				return m;
			}
			else if (key < A[m])
			{
				return recursiveBinarySearch(l, m - 1, key);
			}
			else
			{
				return recursiveBinarySearch(m + 1, h, key);
			}
		}
		return -1;
	}


	int get(Array1* arr, int index)
	{
		if (index >= 0 && index < arr->length)
		{
			return A[index];
		}
	}

	int set(Array1* arr, int index, int x)
	{
		if (index >= 0 && index < arr->length)
		{
			return A[index] = x;
		}
	}

	int max(Array1* arr)
	{
		int max = arr->A[0];
		for (int i = 0; i < arr->length; i++)
		{
			if (A[i] > max)
			{
				max = arr->A[i];
			}
		}
		return max;
	}

	int min(Array1* arr)
	{
		int min = arr->A[0];
		for (int i = 0; i < arr->length; i++)
		{
			if (A[i] < min)
			{
				min = arr->A[i];
			}
		}
		return min;
	}
	int sum(Array1* arr)
	{
		int total = 0;
		for (int i = 0; i < arr->length; i++)
		{
			total += A[i];
		}
		return total;
	}
	int recursionSum(Array1* arr, int n)
	{
		if (n < 0)
		{
			return 0;
		}
		else
		{
			recursionSum(arr, n - 1) + A[n];
		}

	}
	float average(Array1* arr)
	{
		return (float)sum(arr) / arr->length;
	}


	void firstReverse(Array1* arr)
	{
		int* B;
		B = new int[arr->length];
		for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
		{
			B[j] = A[i];
		}
		for (int i = 0; i < arr->length; i++)
		{
			A[i] = B[i];
		}
		display();
	}


	void secondReverse(Array1* arr)
	{

		for (int i = 0, j = arr->length - 1; i < j; i++, j--)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		display();
	}

	// Left Shift/Rotate









	~Array1() {
		delete[] A;
		cout << endl << "Array Example Destroyed" << endl;
	}
};


























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

	cout << Power(2, 3) << endl;

	cout << BetterPower(2, 3) << endl;

	cout << TaylorSeries(3, 4) << endl;





	// Arrays
	// static array is created in the stack whereas dynamic array is created in the heap	
	int staticArray1[] = { 1, 2,3,4,5 };

	int* dynamicArray1 = new int[5];

	// Deleting dynamic array from heap

	// Increase Array Size

	int* dynamicArray2 = new int[10];

	for (int i = 0; i < 5; i++)
	{
		dynamicArray2 = dynamicArray1;
	}
	delete[]dynamicArray1;
	dynamicArray1 = dynamicArray2;
	dynamicArray2 = nullptr;
	// new address and location of new array to the 2nd array

	// 2D Array
	// 3 row 4 column
	int TwoDimensionalArray1[3][4] = { {1,2,3,4} ,{2,4,6,8}, {2,5,10,15} };

	// creating in heap
	int** Dynamic2DArray1 = new int* [3];
	Dynamic2DArray1[0] = new int[4];
	Dynamic2DArray1[1] = new int[4];
	Dynamic2DArray1[2] = new int[4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << TwoDimensionalArray1[i][j] << " ";
		}
	}
	cout << endl;

	// Representation Of Array in Compiler -> Base Address + index + size of data type

	// n as number of elements in row
	// m as number of elements in column
	// Row Major Mapping Formula For 2D Array

	// Address Array[i][j] = Base Address + [i * n + j] * size of data type

	// Column Major Formula For 2D Array

	// Address Array[i][j] = Base Address + [j * m + i] * size of data type

	// Formulas For nD Arrays
	// Refer to SS in telegram

	// Row Major Formula For 3D Array

	// Address Array[i][j][k] = Base Address + [i * m * n + j * n + k] * size of data type

	// Column Major Formula For 3D Array

	// Address Array[i][j][k] = Base Address + [k * l * m + j * l + i] * size of data type

	// Array ADT (Data, Operations)
	Array1 arr(10);
	arr.create();
	arr.display();
	cout << endl;
	// Display and array
	int exampleArray[5] = { 1,2,3,4,5 };

	for (int i = 0; i < sizeof(exampleArray) / sizeof(int); i++)
	{
		cout << exampleArray[i] << " ";
	}
	cout << endl;

	// Add/Append
	arr.append(&arr, 6);
	cout << endl;
	// Insert
	arr.insert(&arr, 3, 100);
	cout << endl;

	// Delete 
	arr.del(&arr, 3);
	cout << endl;

	// Search
	// Linear Search (Checking elements one by one)
	// Binary Search (Array must be sorted) (Check the middle first and split the array into 2) (lower, higher, middle = (higher + lower)/2)

	cout << arr.recursiveBinarySearch(0, 5, 3) << endl;


	// Get Set Avg Max Functions

	cout << arr.get(&arr, 3) << endl;
	cout << arr.set(&arr, 4, 5) << endl;
	cout << arr.sum(&arr) << endl;
	cout << arr.average(&arr) << endl;
	cout << arr.max(&arr) << endl;
	cout << arr.min(&arr) << endl;

	// Reverse and Shift Array
	arr.firstReverse(&arr);
	cout << endl;
	arr.secondReverse(&arr);
	cout << endl;


}

