#include <iostream>
#include <cstring>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;

public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // +1 for the null termination character
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0; // We could simply add +1 to m_Size in memcpy, but that would work
		// using the assumption that the sting passed as argument is properly null terminated. This
		// way, adding our own null termination character,  is safer.
	}

	String(const String& other) : m_Size(other.m_Size)
	{
		// If we do not implement our own copy constructor, what will be copied is actually the char pointer. C++ default
		// copy constructor may look like:
		// String (const String& other): m_Size(other.m_Size), m_Buffer(other.m_Buffer) {}
		// or, if you want to be more exciting:
		// String(const String& other) { memcpy(this, &other, sizeof(String)); }
		// This is called a shallow copy, it creates a new array but it does not create new copies of the elements
		// within the array; instead, it points to the same elements as the original array. So we would have two strings
		// in memory which have the same child pointer value, i.e., the m_Buffer address is the same for both, and the
		// system may crash because, when one of them reaches the end of its scope, m_Buffer gets deleted and that memory
		// address is freed; when the other one calls delete, we have undefined behavior (we may not free memory that has
		// already been freed, that is not ours). This may also create other situation such as modifying one variable will
		// reflect on another etc. because they would, again, point to the same memory address.
		// To solve that, we want the copied string to have it's own block of memory to point to. This is what is called a
		// deep copy: it creates a completely independent copy of both the array and its data, i.e., it does not share any
		// data with the original array.
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // In here we can use +1 because we know our string
		// will have the null termination character.
		std::cout << "Copied string!" << std::endl;
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void print(const String& s)
{
	// Using a const reference prevents the program from having to allocate and free memory needlessly;
	// if, for some reason, we need to copy the string, we can do it even if its a const reference:
	// String copy = s;
	std::cout << s << std::endl;
}

int main()
{
	String s = "Hello world!";
	String s2 = s;

	s2[5] = '@';

	print(s);
	print(s2);

	return 0;
}