
#include <iostream>
#include <conio.h>

using namespace std;

int var = 2023;

// Functions declarations

void print_data_types_sizes();
void scope_operator_example();
void pointers_example_2();
void pointers_example_1();
void pointers_example_3();
void pointers_example_4();

int main()
{

	// The usage of scope operator
	scope_operator_example();

	// Data tyes size
	print_data_types_sizes();

	// Pointers usages - values & memory addresses
	// Address operator (reference) / Dereference operator 
	pointers_example_1();

	// pointers arithmetic
	pointers_example_2();

	pointers_example_3();

	pointers_example_4();

	_getch();
}


// Functions definition
void print_data_types_sizes()
{
	// boolean - true or false => 0 or 1
	cout << "bool: " << sizeof(bool) << "   -   bool*: " << sizeof(bool*) << endl;

	// character
	cout << "char: " << sizeof(char) << "   -   char*: " << sizeof(char*) << endl;
	cout << "wchar_t: " << sizeof(wchar_t) << "   -   wchar_t*: " << sizeof(wchar_t*) << endl;

	// integer 
	cout << "short: " << sizeof(short) << "   -   short*: " << sizeof(short*) << endl;
	cout << "int: " << sizeof(int) << "   -   int*: " << sizeof(int*) << endl;
	cout << "long: " << sizeof(long) << "   -   long*: " << sizeof(long*) << endl;
	cout << "long long: " << sizeof(long long) << "   -   long long*: " << sizeof(long long*) << endl;

	// floating point
	cout << "float: " << sizeof(float) << "   -   float*: " << sizeof(float*) << endl;
	cout << "double: " << sizeof(double) << "   -   double*: " << sizeof(double*) << endl;
	cout << "long double: " << sizeof(long double) << "   -   long double*: " << sizeof(long double*) << endl;

	cout << endl;
	_getch();
}

void scope_operator_example()
{
	int var = 1234;

	cout << "Local variable `var` - current function's scope: " << var << endl;
	cout << "Global variable `var`: " << ::var << endl;
	cout << endl;
	_getch();
}

void pointers_example_1()
{
	// Local variables declaration - function scope
	// Variables initialization - data types

	int a = 3;
	int b = 5;
	int var = 5478;
	int* ptr_a = nullptr;
	int* ptr_b = nullptr;
	int* ptr_var = nullptr;
	int* ptr_global_var = nullptr;
	char c = 'A';
	char* ptr_c = nullptr;

	// Copy the address of variable a to pointer variable *ptr_a
	ptr_a = &a;

	// Copy the address of variable b to pointer variable *ptr_b
	ptr_b = &b;

	// ...
	ptr_var = &var;

	//  ...
	ptr_global_var = &(::var);

	// ...
	ptr_c = &c;

	// Print the values and memory addresses for each variable
	cout << endl << endl << "### Valorile stocate in variabile si adresele de memorie ale variabilelor" << endl;
	cout << "a: " << "Valoarea: " << a << "  -  la adresa: " << ptr_a << endl;
	cout << "b: " << "Valoarea: " << b << "  -  la adresa: " << ptr_b << endl;
	cout << "var: " << "Valoarea: " << var << "  -  la adresa: " << ptr_var << endl;
	cout << "::var: " << "Valoarea: " << ::var << "  -  la adresa: " << ptr_global_var << endl;
	cout << "c: " << "Valoarea: " << c << "  -  la adresa: " << 0 << endl;  // De ce (void*)?  Discutie
	cout << "c: " << "Valoarea: " << c << "  -  la adresa: " << (void*)ptr_c << endl;  // De ce (void*)?  Discutie

	_getch();

	// List stored vaalues and memory addresses - reference / dereference to get the value
	cout << endl << endl << "### Reafisare folosind operatorul de dereferentiere =>  *" << endl;
	cout << "a: " << "Valoarea: " << *ptr_a << "  -  la adresa: " << ptr_a << endl;
	cout << "b: " << "Valoarea: " << *ptr_b << "  -  la adresa: " << ptr_b << endl;
	cout << "var: " << "Valoarea: " << *ptr_var << "  -  la adresa: " << ptr_var << endl;
	cout << "::var: " << "Valoarea: " << *ptr_global_var << "  -  la adresa: " << ptr_global_var << endl;
	cout << "c: " << "Valoarea: " << *ptr_c << "  -  la adresa: " << (void*)ptr_c << endl;  // De ce (void*)?  Discutie

	cout << endl << endl;
}

void pointers_example_2()
{
	// Using Debugger to check values and memory addresse
	// Function scope

	int a = 3, b = 5, var = 5478, * ptr_a = &a, * ptr_b = &b, * ptr_var = &var, * ptr_global_var = &(::var);

	char c = 'A', * ptr_c = nullptr;

	short s = 3, * ptr_s = &s;

	float f = 54.3, * ptr_f = &f;
	double d = 54.3, * ptr_d = &d;

	// Increment / Decrement  address/value
	*ptr_a++;

	*ptr_a--;

	(*ptr_a)++;

	ptr_a++;

	ptr_a--;



	// Similar ... but not the same:
	// Pointer operations are executed considering data types sizes =>
	// Obs: difference between ++ operator applied on int* vs.short* vs. char*

	*ptr_s++;

	*ptr_s--;

	(*ptr_s++);

	ptr_s++;


	// Store the address of a variable
	int* ptr = ptr_b;

	ptr = ptr_b - 12; //  ptr <= ptr_b - 12*sizeof(int) - because ptr_b stores the address of b variable, int data type

	ptr += 12; // Restore the address

	int** ptr_ptr = &ptr; // ...
	int*** ptr_ptr_ptr = &ptr_ptr;

	// How to access the value of variable b
	cout << "Valoarea variabilei b este: " << **ptr_ptr << endl;
	cout << "Valoarea variabilei b este: " << b << endl;


	//// Similar with float/double and char


	// # Example of modifying a previously unallocated memory area
	// In the variable x of type int* (pointer to a memory address where the value of an variable of type int is stored) the address of the neighboring memory area with the address of the variable a is copied
	int* x = ptr_a + 1;

	// The value stored at the previously saved address in variable x is modified - the value becomes 7
	// This change will generate an exception (in debugger mode) => discussion based on the generated exception - memory allocation
	*x = 7;
}

void pointers_example_3()
{

	int array_var[100] = { 0 };
	array_var[0] = 56;

	int* ptr_array_var = new int[100];
	ptr_array_var[0] = 56;
	ptr_array_var[1] = 123;
	*(ptr_array_var + 2) = 125;

	delete ptr_array_var;
}

void pointers_example_4()
{
	char* char_array = new char[17];

	for (int index = 0; index < 16; index++)
	{
		char_array[index] = 'a' + index;
	}

	cout << char_array;
	cout << endl;

	char_array[16] = '\0';

	cout << char_array;
	cout << endl;

	char_array = (char*)"Acesta este test";

	cout << char_array;
	cout << endl;

	//char_array[16] = '\0';

	cout << char_array;
	cout << endl;

	_getch();
}

