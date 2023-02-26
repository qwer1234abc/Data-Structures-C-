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




/*
class Array1 {

private:
	int* A;
	int size;
	int length;

public:
	Array1(int size, int length, bool sorted = false) {

		this->size = size;
		this->length = length;

		A = new int[size];

		if (sorted) {
			cout << "Enter ints in sorted manner" << endl;
			for (int i = 0; i < length; i++) {
				cout << "Enter element " << i << " : " << flush;
				cin >> A[i];
			}
		}
		else {
			for (int i = 0; i < length; i++) {

				int val;
				val = rand() % 100;  // Random int in range 0 to 100

				// Generate random binary int and make value negative
				if (rand() % 2) {
					A[i] = -1 * val;
				}
				else {
					A[i] = val;
				}

			}
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

	int get(int index) {
		if (index >= 0 && index < length) {
			return A[index];
		}
	}

	void set(int index, int x) {
		if (index >= 0 && index < length) {
			A[index] = x;
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

	bool isSorted(Array1* arr, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (A[i] > A[i + 1])
			{
				return false;
			}
		}
		return true;
	}

	// Splitting Positive and Negative Number

	void seperatePositiveNegative(Array1* arr)
	{
		int i = 0;
		int j = arr->length - 1;
		while (i < j)
		{

			while (A[i] < 0)
			{
				i++;
			}
			while (A[j] >= 0)
			{
				j--;
			}
			if (i < j)
			{
				swap(arr->A[i], arr->A[j]);
			}
		}
	}


	Array1 Merge(Array1& B) {
		Array1 C(length + B.length, length + B.length);
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < length && j < B.length) {
			if (A[i] < B.get(j)) {
				C.set(k++, A[i++]);
			}
			else {
				C.set(k++, B.get(j++));
			}
		}
		for (; i < length; i++) {
			C.set(k++, A[i]);
		}
		for (; j < B.length; j++) {
			C.set(k++, B.get(j));
		}
		return C;
	}
	~Array1()
	{
		delete[] A;
		cout << endl << "Array Example Destroyed" << endl;
	}
};
*/
class Array
{
private:
	int* A;
	int size;
	int length;
	void swap(int* x, int* y);

public:
	Array()
	{
		size = 10;
		length = 0;
		A = new int[size];
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int[size];
	}
	~Array()
	{
		delete[]A;
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int Delete(int index);
	int LinearSearch(int key);
	int BinarySearch(int key);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void InsertSort(int x);
	int isSorted();
	void Rearrange();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Diff(Array arr2);
	Array* Inter(Array arr2);
};
void Array::Display()
{
	int i;
	cout << "\nElements are\n";
	for (i = 0; i < length; i++)
		cout << A[i] << " ";
}
void Array::Append(int x)
{
	if (length < size)
		A[length++] = x;

}
void Array::Insert(int index, int x)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length; i > index; i--)
			A[i] = A[i - 1];
		A[index] = x;
		length++;

	}
}
int Array::Delete(int index)
{
	int x = 0;
	int i;

	if (index >= 0 && index < length)
	{
		x = A[index];
		for (i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
		return x;
	}

	return 0;
}
void Array::swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int Array::LinearSearch(int key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(&A[i], &A[0]);
			return i;
		}
	}
	return -1;
}
int Array::BinarySearch(int key)
{
	int l, mid, h;
	l = 0;
	h = length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
int Array::Get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
	return -1;
}
void Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
		A[index] = x;
}
int Array::Max()
{
	int max = A[0];
	int i;
	for (i = 1; i < length; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}
int Array::Min()
{
	int min = A[0];
	int i;
	for (i = 1; i < length; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}
int Array::Sum()
{
	int s = 0;
	int i;
	for (i = 0; i < length; i++)
		s += A[i];

	return s;
}
float Array::Avg()
{
	return (float)Sum() / length;
}
void Array::Reverse()
{
	int* B;
	int i, j;

	B = (int*)malloc(length * sizeof(int));
	for (i = length - 1, j = 0; i >= 0; i--, j++)
		B[j] = A[i];
	for (i = 0; i < length; i++)
		A[i] = B[i];

}
void Array::Reverse2()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		swap(&A[i], &A[j]);
	}
}
void Array::InsertSort(int x)
{
	int i = length - 1;
	if (length == size)
		return;
	while (i >= 0 && A[i] > x)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;

}
int Array::isSorted()
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return 0;
	}
	return 1;
}
void Array::Rearrange()
{
	int i, j;
	i = 0;
	j = length - 1;

	while (i < j)
	{
		while (A[i] < 0)i++;
		while (A[j] >= 0)j--;
		if (i < j)swap(&A[i], &A[j]);
	}

}
Array* Array::Merge(Array arr2)
{
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = length + arr2.length;

	return arr3;
}
Array* Array::Union(Array arr2)
{
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = k;

	return arr3;
}
Array* Array::Inter(Array arr2)
{
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;
		else if (arr2.A[j] < A[i])
			j++;
		else if (A[i] == arr2.A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}

	arr3->length = k;

	return arr3;
}
Array* Array::Diff(Array arr2)
{
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];


	arr3->length = k;

	return arr3;
}






/*
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
	Array1 arr(10, 5, true);
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

	cout << arr.get(3) << endl;
	arr.set(4, 5);
	cout << arr.sum(&arr) << endl;
	cout << arr.average(&arr) << endl;
	cout << arr.max(&arr) << endl;
	cout << arr.min(&arr) << endl;

	// Reverse and Shift Array
	arr.firstReverse(&arr);
	cout << endl;
	arr.secondReverse(&arr);
	cout << endl;

	// Sorted Array


	// Merging Array
	// 1. Append
	// 2. Concat
	// 3. Compare
	// 4. Copy
	Array1 MergedArray1(10, 5, true);
	Array1 MergedArray2(10, 4, true);

	Array1 Z = MergedArray1.Merge(MergedArray2);
	Z.display();


	// Set Operations on Arrays
	// Union
	// Intersection
	// Difference
	// Set Membership
	Array* arr1;
	int ch, sz;
	int x, index;

	cout << "Enter Size of Array";
	cin >> sz;
	arr1 = new Array(sz);

	do
	{
		cout << "\n\nMenu\n";
		cout << "1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Search\n";
		cout << "4. Sum\n";
		cout << "5. Display\n";
		cout << "6. Exit\n";

		cout << "enter you choice ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter an element and index ";
			cin >> x >> index;
			arr1->Insert(index, x);
			break;
		case 2: cout << "Enter index ";
			cin >> index;
			x = arr1->Delete(index);
			cout << "Deleted Element is" << x;
			break;
		case 3:cout << "Enter element to search";
			cin >> x;
			index = arr1->LinearSearch(x);
			cout << "Element index " << index;
			break;
		case 4:cout << "Sum is " << arr1->Sum();
			break;
		case 5:arr1->Display();

		}
	} while (ch < 6);


}
class Diagonal
{
private:
	int* A;
	int n;
public:
	Diagonal()
	{
		n = 2;
		A = new int[2];
	}
	Diagonal(int n)
	{
		this->n = n;
		A = new int[n];
	}
	~Diagonal()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; }
};
void Diagonal::Set(int i, int j, int x)
{
	if (i == j)
		A[i - 1] = x;
}
int Diagonal::Get(int i, int j)
{
	if (i == j)
		return A[i - 1];
	return 0;
}
void Diagonal::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				cout << A[i - 1] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

class LTMatrix {
private:
	int n;
	int* A;
public:
	LTMatrix(int n) {
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~LTMatrix() { delete[] A; }
	void Display(bool row = true);
	void setRowMajor(int i, int j, int x);
	void setColMajor(int i, int j, int x);
	int getRowMajor(int i, int j);
	int getColMajor(int i, int j);
	int getN() { return n; }

};

void LTMatrix::setRowMajor(int i, int j, int x) {
	if (i >= j) {
		int index = ((i * (i - 1)) / 2) + j - 1;
		A[index] = x;
	}
}

void LTMatrix::setColMajor(int i, int j, int x) {
	if (i >= j) {
		int index = (n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j);
		A[index] = x;
	}
}

int LTMatrix::getRowMajor(int i, int j) {
	if (i >= j) {
		int index = ((i * (i - 1)) / 2) + j - 1;
		return A[index];
	}
	else {
		return 0;
	}
}

int LTMatrix::getColMajor(int i, int j) {
	if (i >= j) {
		int index = (n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j);
		return A[index];
	}
	else {
		return 0;
	}
}

void LTMatrix::Display(bool row) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= j) {
				if (row) {
					cout << getRowMajor(i, j) << " ";
				}
				else {
					cout << getColMajor(i, j) << " ";
				}
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}


int main()
{
	// Strings - ASCII Codes, Unicode
	// Termination character \0
	// Length of String
	char firstString[] = "WELCOME";
	int i;
	for (i = 0; firstString[i] != '\0'; i++)
	{

	}

	cout << "Length of string is " << i << endl;

	// Changing Case using ASCII code
	for (int i = 0; firstString[i] != '\0'; i++)
	{
		if (firstString[i] >= 'A' && firstString[i] <= 'Z')
		{
			firstString[i] += 32;
		}
		else if (firstString[i] >= 'a' && firstString[i] <= 'z')
		{
			firstString[i] = 32;
		}
	}
	cout << ("Lower case of string is ") << firstString << endl;

	// Diagonal Matrix


	int d;
	cout << "Enter Dimensions";
	cin >> d;

	Diagonal dm(d);

	int x;
	cout << "Enter All Elements";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			dm.Set(i, j, x);
		}
	}

	dm.Display();

	LTMatrix rm(4);
	rm.setRowMajor(1, 1, 1);
	rm.setRowMajor(2, 1, 2);
	rm.setRowMajor(2, 2, 3);
	rm.setRowMajor(3, 1, 4);
	rm.setRowMajor(3, 2, 5);
	rm.setRowMajor(3, 3, 6);
	rm.setRowMajor(4, 1, 7);
	rm.setRowMajor(4, 2, 8);
	rm.setRowMajor(4, 3, 9);
	rm.setRowMajor(4, 4, 10);

	rm.Display();
	cout << endl;

	LTMatrix cm(4);
	cm.setColMajor(1, 1, 1);
	cm.setColMajor(2, 1, 2);
	cm.setColMajor(2, 2, 3);
	cm.setColMajor(3, 1, 4);
	cm.setColMajor(3, 2, 5);
	cm.setColMajor(3, 3, 6);
	cm.setColMajor(4, 1, 7);
	cm.setColMajor(4, 2, 8);
	cm.setColMajor(4, 3, 9);
	cm.setColMajor(4, 4, 10);

	cm.Display(false);
}
*/


/*
 *
void recursiveDisplayLinkedList(Node* p)
{
	if (p != NULL)
	{
		cout << p->data << " -> " << flush;
		recursiveDisplayLinkedList(p->next);
	}
}


void recursiveReverseDisplayLinkedList(Node* p)
{
	if (p != NULL)
	{
		recursiveReverseDisplayLinkedList(p->next);
		cout << p->data << " -> " << flush;
	}
}


// Counting nodes in linked list

int countNode(Node* p)
{
	int count = 0;
	while (p != 0)
	{
		count++;
		p->next;
	}
	return  count;
}

int recursiveCountNode(Node* p)
{
	if (p == 0)
	{
		return 0;
	}
	else
	{
		return recursiveCountNode(p->next) + 1;
	}
}

// Sum of elements in linked list

int AddLinkedList(Node* p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int recursiveAddLinkedList(Node* p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return recursiveAddLinkedList(p->next) + p->data;
	}
}


// Maximum Element in linked list

int maxLinkedList(Node* p)
{
	int x = p->data;

	while (p != NULL)
	{
		if (p->data > x)
		{
			x = p->data;
		}
		p = p->next;
	}
	return x;
}

int recursiveMaxLinkedList(Node* p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		int x = recursiveMaxLinkedList(p->next);
		return x > p->data ? x : p->data;
	}

}

// Searching in a linked list ( cannot use binary search )

Node* searchLinkedList(Node* p, int key)
{
	while (p != 0)
	{
		if (p->data == key)
		{
			return p;
		}
		else
		{
			p = p->next;
		}

	}
	return NULL;

}


Node* recursiveSearchLinkedList(Node* p, int key)
{
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		if (key == p->data)
		{
			return p;
		}
		else
		{
			return recursiveSearchLinkedList(p->next, key);
		}
	}
}


// Improved version of linear search, transposition and move to head

Node* moveToHeadSearchLinkedList(Node* p, int key)
{
	Node* q = new Node{p->data};
	while (p != NULL)
	{
		if (key == p->data)
		{

			q->next = p->next;
			p->next = p;
			return p;
		}
		else
		{
			q = p;
			p = p->next;
		}

	}
	return NULL;
}

// Inserting into a linked list
// Insert before first node
// Inserting after given position
int countLinkedList(Node* p)
{
	int l = 0;
	while (p)
	{
		l++;
		p = p->next;
	}

	return l;
}
void insertLinkedList(Node* p, int index, int x)
{
	Node* t = NULL;
	int i;
	if (index < 0 || index > countLinkedList(p))
	{
		return;
	}
	else
	{
		t = new Node{x};
	}
	if (index == 0)
	{
		t->next = p;
		p = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}
 */
class Node {
public:
	int data;
	Node* next;

	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class LinkedList {
private:
	Node* first;
	Node* last;
public:
	LinkedList() {
		first = nullptr;
		last = nullptr;
	}
	void create(int A[], int n) {
		Node* t;
		first = new Node(A[0]);
		last = first;

		for (int i = 1; i < n; i++) {
			t = new Node(A[i]);
			t->next = nullptr;
			last->next = t;
			last = t;
		}
	}

	void display() {
		Node* p = first;

		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}

		cout << endl;
	}

	int count() {
		Node* p = first;
		int count = 0;

		while (p != nullptr) {
			count++;
			p = p->next;
		}

		return count;
	}

	void insert(int index, int x) {
		Node* t = new Node(x);

		if (index < 0 || index > count()) {
			return;
		}

		if (index == 0) {
			t->next = first;
			first = t;
		}
		else {
			Node* p = first;

			for (int i = 0; i < index - 1; i++) {
				p = p->next;
			}

			t->next = p->next;
			p->next = t;
		}
	}

	void insertLast(int x)
	{
		Node* t = new Node(x);
		if (first == nullptr)
		{
			first = last = t;
		}
		else
		{
			last->next = t;
			last = t;
		}
	}

	// Insert into a sorted linked list
	// Use tailing pointer
	void insertSortedLinkedList(int x)
	{
		Node* t = new Node(x);
		Node* q = new Node(NULL);
		Node* p = first;
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		t->next = p;
		q->next = t;

	}

	// Deleting from linked list
	// Delete first node
	// Delete node at any give position

	int deleteLinkedList(int index)
	{
		Node* q = new Node(NULL);
		Node* p = first;
		int x = -1;
		if (index < 0 || index > count())
		{
			return -1;
		}
		if (index == 0)
		{
			q = p;
			x = p->data;
			p = p->next;
			delete q;
			return x;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				q = p;
				p = p->next;
			}
			q->next = p->next;
			x = p->data;
			delete p;
			return x;
		}
	}


	// Check if linked list is sorted

	bool checkSorted()
	{
		Node* p = first;
		int x = p->data;

		while (p)
		{
			if (p->data < x)
			{
				return false;
			}
			else
			{
				x = p->data;
				p = p->next;
			}
		}
		return true;

	}

	// Remove duplicates from linked list

	void removeDuplicates()
	{
		Node* q = new Node(NULL);
		Node* p = first;
		q = p->next;

		while (q)
		{
			if (q->data == p->data)
			{
				p->next = q->next;
				delete q;
				q = p->next;
			}
			p = q;
			q = q->next;
		}
	}

	// Reversing a linked list
	// Reversing elements
	// Reversing links

	void elementReverseLinkedList(int size)
	{
		int* A;
		A = new int[size];
		Node* p = first;
		int i = 0;
		while (p)
		{
			A[i] = p->data;
			p = p->next;
			i++;
		}
		p = first; i--;
		while (p)
		{
			p->data = A[i];
			p = p->next;
			i--;
		}
		delete[]A;
	}


	// using 3 sliding pointers
	void linkReverseLinkedList() {
		Node* p = first;
		Node* q = NULL;
		Node* r = NULL;

		while (p != NULL) {
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}

		first = q;
	}


	// Recursive method

	void recursiveReverseLinkedList(Node* q = NULL, Node* p = NULL)
	{
		p = first;
		if (p == NULL)
		{
			recursiveReverseLinkedList(p, p->next);
			p->next = q;
		}
		else
		{
			first = q;
		}
	}


};
int main()
{
	// Linked List
	// Array is fixed size which is not good during run		

	// Linked List is a collections of nodes where each node contains data and pointed to next node
	// Node consists of data and pointer to next node
	// pointer of its on type (a node)
	/*
	 *
	int A[] = { 3, 5, 7, 10, 15 };

	Node* head = new Node{A[0]};

	Node* temp;
	Node* last;

	head->data = A[0];
	last = head;

	// Create a Linked List
	for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++) {

		// Create a temporary Node
		temp = new Node{A[i]};

		// last's next is pointing to temp
		last->next = temp;
		last = temp;
	}

	// Display Linked List
	Node* p = head;
	while (p != nullptr) {
		cout << p->data << " -> " << flush;
		p = p->next;
	}
	cout << endl;
	recursiveReverseDisplayLinkedList(head);
	cout << endl << recursiveCountNode(head) << endl;
	cout << AddLinkedList(head) << endl;
	cout << maxLinkedList(head) << endl;
	cout << recursiveSearchLinkedList(head, 15) << endl;
	recursiveDisplayLinkedList(head);
	insertLinkedList(head, 0, 11);
	 */
	int A[] = { 1,2,3,4,5 };
	int B[] = { 10, 20, 30, 40, 50 };
	LinkedList list1;
	LinkedList list2;
	list1.create(B, 5);
	list1.insert(0, 5);
	list1.display();
	list2.create(A, 5);
	// Insert into last (create)
	list2.insertLast(6);
	list2.insertSortedLinkedList(3);
	list2.display();
	list2.deleteLinkedList(1);
	list2.display();
	cout << list2.checkSorted() << endl;
	list2.removeDuplicates();
	list2.display();
	list2.elementReverseLinkedList(sizeof(A) / sizeof(int));
	list2.display();
	list2.linkReverseLinkedList();
	list2.display();
	list2.display();
}