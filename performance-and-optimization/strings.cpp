#include <iostream>
#include <string>

void strings();

void stringView();

void printString(std::string_view s);

// Overwriting new operator to check heap allocations
// In C++, a void pointer is a pointer that is declared using the `void` keyword (`void*`).
// It's different from regular pointers; it's used to point to data of no specified data type.
// It can point to any type of data so it is also called a "Generic Pointer".
void* operator new(size_t bytes)
{
	std::cout << "Allocating " << bytes << " bytes" << std::endl;
	// In this case, we're allocating bytes in memory to store text, and not objects, so we don't need
	// to call a constructor; if we were to really overwrite the new operator, we would have to worry about
	// calling the constructor if creating an object.
	return malloc(bytes);
}

int main()
{
	strings();
	stringView();
	return 0;
}

void strings()
{
	// A string is nothing more than a char pointer; in general, strings are immutable, i.e., they're stored
	// in read only memory regions. To avoid unnecessary memory allocations, if we're not going to manipulate
	// a string we may use `const char*`, that way it'll be allocated on the stack. If the string is too big,
	// though, it may cause a stack overflow.
	const char* name = "Slim Shady";
	std::cout << "Hello, World! My name is " << name << std::endl;
	// If we have a small enough string, the STL string offers an optimization called SSO (Small String Optimization).
	// Basically, if the string is small enough it'll be allocated on the stack; the size deemed small enough varies
	// between different compilers (among other things). In this particular test, the largest string allocated on
	// the stack was 15 characters long; from 16 onwards, allocations started to be on the heap.
	std::string s17b = "-> 16 characters"; // Allocating 17 bytes
	std::cout << "Smallest heap allocated string: " << s17b << std::endl;
}

void stringView()
{
	// If we merely want to display a string, we can use a string_view; that consists, basically, of a pointer to
	// the address of the beginning of the string and and int indicating how many bytes we want to read (if omitted,
	// goes through the whole string). It's available since C++17.

	std::string couple = "Pedro de Alcantara Joao Carlos Leopoldo Gonzaga & Teresa Cristina Melchior Gertrude Venancia Spiridione";
	// couple.substr(0, couple.find('&') - 1); // substr will copy the string and will need an allocation
	std::string_view husband(couple.c_str(), couple.find('&') - 1);
	std::string_view wife(couple.c_str() + couple.find('&') + 2); // c_str points to the original string

	printString(couple); // we can pass a string for a string_view argument
	printString(husband);
	printString(wife);
	printString("Another string not in heap");
}

// If, for instance, we receive a string as argument only to exhibit it, we may modify the parameter to receive
// a string_view and avoid unnecessary memory allocations.
void printString(std::string_view s)
{
	std::cout << s << std::endl;
}
