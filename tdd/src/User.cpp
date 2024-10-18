#include "User.hpp"

#include <utility>

User::User(std::string name) : name(std::move(name))
{}

std::string User::getName() const
{
	return name;
}

std::string User::getFirstName() const
{
	std::string firstName = name.substr(0, name.find(' '));

	return firstName.empty() ? name : firstName;
}
