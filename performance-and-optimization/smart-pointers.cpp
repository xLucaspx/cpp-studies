#include <iostream>
#include <memory>

void rawPointers();

void uniquePointers();

void sharedPointers();

void weakPointers();

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void print()
	{}
};

int main()
{
	// When using C++, if we allocate memory using new, we explicitly must free that memory using delete; this, and
	// using raw pointers, may get more complicated than what we expected for various reasons...
	rawPointers();
	// Unique pointers guarantee a unique pointer, i.e., a single reference to the object in scope; as soon as
	// as the end of the scope is reached, the object is destroyed and the memory is freed.
	uniquePointers();
	// Unique pointer cannot be copied because, if they did, all the copies would point to the same address and, once
	// one of the copies reached the end of it's scope, it would free that memory and all other pointers would then
	// become invalid.
	// If you need to copy the pointer, share it, pass it as an argument etc. you need to use shared pointers.
	sharedPointers();
	// A weak pointer is, basically, a shared pointer that doesn't increase the reference count
	weakPointers();

	/*
	 * Smart pointers automate memory management and prevent memory leaks; because of it's reference counting system,
	 * shared pointers hava a bit of overhead, but memory management implementations tend to have this characteristic.
	 * Use unique pointers by default (they have almost no overhead) and shared pointers if you know that it'll have
	 * several owners.
	 */
	return 0;
}

void rawPointers()
{
	Entity* rp1 = new Entity();
	rp1->print();
	delete rp1;
}

void uniquePointers()
{
	// We need to explicitly call the constructor of unique_ptr, and we can pass a raw pointer:
	// std::unique_ptr<Entity> entity(new Entity());

	// But, for exception safety, the best way to create a unique pointer is to call make_unique;
	// if, for some reason, the constructor throws an exception, we won't end up having a dangling
	// pointer with no reference (memory  leak)
	std::unique_ptr<Entity> entity = std::make_unique<Entity>();

	// and then you can access it like you would access a raw pointer
	entity->print();
}

void sharedPointers()
{
	// Shared pointers works differently than unique pointers because it does lots of other stuff under the hood.
	// It's implementation depends on the STL and the compiler being used, but basically it uses reference counting,
	// i.e., it keeps count of how many references to the pointer exist and, when that number reaches zero, it gets
	// deleted and the memory freed.
	// With unique pointers, the only reason to use make_unique is because of exception safety; with shared pointers,
	// we will always want to use make_shared because shared pointers must allocate another block of memory, called
	// control block, where it stores the reference count, and if you first create a new object and then pass it to
	// the shared pointer constructor, it has to allocate the control block, so you'll have two allocations. Using
	// make_shared the shared pointer can construct both things together, which is a lot more efficient.

	// std::shared_ptr<Entity> entity(new Entity()); // two allocations
	{
		std::shared_ptr<Entity> shared;
		{
			std::shared_ptr entity = std::make_shared<Entity>(); // more efficient
			entity->print();
			shared = entity;
		} // entity dies at the end of this scope, but the pointer is not destroyed
		shared->print();
	} // shared dies at the end of this scope and now the pointer is destroyed
}

void weakPointers()
{
	// A weak pointer can receive the value of a shared entity like a shared pointer would, except that
	// it doesn't increase the reference count. It's useful, for example, if you don't want to take ownership
	// of the entity. Basically, the weak pointer can do something with your entity if it's still alive, but it
	// won't keep it alive.
	{
		std::weak_ptr<Entity> weak;
		{
			std::shared_ptr entity = std::make_shared<Entity>();
			weak = entity;
		} // entity dies at the end of this scope, and this time the pointer is destroyed
	}
}
