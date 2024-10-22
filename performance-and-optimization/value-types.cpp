#include <iostream>
#include <string>

void printStr(const std::string& s)
{
	std::cout << "[l-value]: " << s << std::endl;
}

void printStr(std::string&& s)
{
	std::cout << "[r-value]: " << s << std::endl;
}

void printStrConstRef(const std::string& s)
{
	std::cout << "[const reference]: " << s << std::endl;
}

void printStrNonConstRef(std::string& s)
{
	std::cout << "[non const reference]: " << s << std::endl;
}

int main()
{
	/*
	 * Basically, l-values are all the ones that we can give an memory address to, like variables,
	 * references and pointers. Not all l-values must be variables, but all variables must be l-values.
	 *
	 * R-values, on the other hand, are temporary values that do not persist after the expression in which
	 * they're used; i.e., they don't posses an identifiable memory location (address).
	 *
	 * L-values may appear both at left and right side of an attribution, but r-values will never be on the left.
	 *
	 * An l-value represents a storage region's "locator" value, or a "left" value, implying that it can appear on
	 * the left of the equal sign ( = ). L-values are often identifiers.
	 * The term "r-value" is sometimes used to describe the value of an expression and to distinguish it from an l-value.
	 * All l-values are r-values but not all r-values are l-values.
	 *
	 * We can pass temporary values to const references and we can also write methods that treat l-values and r-values
	 * differently. To identify an r-value argument we use &&; if we want to, we an make it const, but is not necessáry
	 * because it's a temporary value. This is useful because, for an r-value, we can simply take it's data without
	 * having to copy it (see: move).
	 */
	std::string s = "Hello, world!";
	printStr("Hello, world!");
	printStr(s);
	printStr(s.substr(0, 5));

	printStrConstRef(s.substr((7)));
	printStrConstRef(s);
	printStrConstRef("R-value string");

	// printStrNonConstRef(s.substr((7))); // error: cannot bind non-const lvalue reference of type 'std::string&'
	// printStrNonConstRef("R-value string");   // [...] to an rvalue of type 'std::__cxx11::basic_string<char>'
	printStrNonConstRef(s);

	return 0;
}
