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
		m_Buffer[m_Size] = 0; // setting null termination character
		std::cout << "Created string!" << std::endl;
	}

	String(const String& other) : m_Size(other.m_Size)
	{
		// see: copy-constructor
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		std::cout << "Copied string!" << std::endl;
	}

	String(String&& other) noexcept
	{
		// Move constructors can be declared with an r-value argument. What they'll do
		// is basically assume the other reference values; in order for that to work, its
		// necessary to put the r-value argument in an invalid state, otherwise its destructor
		// would be called and we would have an invalid pointer. But remember: this is for the
		// cases in which we're managing memory and raw pointers directly!
		m_Size = other.m_Size;
		m_Buffer = other.m_Buffer;
		// invalidating other reference
		other.m_Size = 0;
		other.m_Buffer = nullptr; // calling delete on a nullptr does nothing
		std::cout << "Moved string!" << std::endl;
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

class Entity
{
	String m_Str;
public:
	// creating a Entity constructor that moves the string
	// explicit Entity(String&& s) : m_Str((String&&) s) {}

	// a better way to do that is to use std::move
	explicit Entity(String&& s) : m_Str(std::move(s))
	{}

	void print()
	{
		std::cout << m_Str << std::endl;
	}
};

int main()
{
	Entity e1("Entity"); // creates the string and then moves it
	e1.print();
	return 0;
}