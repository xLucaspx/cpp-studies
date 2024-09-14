#include <iostream>
#include <string>

class Example {
public:
	Example() {
		std::cout << "Example constructor called!" << std::endl;
	}

	Example(int x) {
		std::cout << "Example constructor called with " << x << "!" << std::endl;
	}
};

class Entity {
private:
	std::string m_Name; // it's common in cpp to prefix members with m_
	Example m_Example;

public:
	Entity() {
		m_Name = "Unknown"; // equivalent to `m_Name = std::string("Unknown")`
		m_Example = Example(42); // it's equivalent to `Example m_Example; m_Example = Example(8);` (2 calls)
	}

	Entity(int e) :
			m_Name("Unknown"),
			m_Example(e) {}
};

int main() {
	// In cpp, when we use the most regular constructor with classes, what really happens is that the default
	// constructor of that class is called and then it's initialized, i.e. the class is created twice and one
	// of them is discarded. E.g.: in the default constructor of the class Entity, the string m_Name is created
	// twice and both constructors of the class Example are called:

	Entity e0; // Example constructor called! and Example constructor called with 42!

	// The reason this happens is that it's not because a member is outside the constructor hat it's code isn't
	// going to be executed, e.g. it's like `Example m_Example;` is copied to the constructor and runs before
	// `m_Example = Example(42);`. I.e. we've created two objects and simply discarded one, instead of only creating one.

	// If we use a Initialization List, the compiler is smart enough to realize it only needs to create one
	// object. In our case, we could write the `m_Example` as `m_Example(Example(42))` or just `m_Example(42)`,
	// and only one `Example` constructor would have been called:

	Entity e1 = Entity(42); // Example constructor called with 42!

	// Note: we should keep initialization list attributes in the same order as they were declared in the class!

	return 0;
}
