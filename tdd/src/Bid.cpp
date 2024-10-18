#include <utility>
#include "Bid.hpp"

Bid::Bid(User user, float value) : user(std::move(user)), value(value)
{}

std::string Bid::getUserName() const
{
	return user.getName();
}

float Bid::getValue() const
{
	return value;
}
