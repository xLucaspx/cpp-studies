#ifndef tdd_bid_hpp
#define tdd_bid_hpp

#include <string>
#include "User.hpp"

class Bid
{
private:
	User user;
	float value;

public:
	Bid(User user, float value);

	[[nodiscard]] float getValue() const;

	[[nodiscard]] std::string getUserName() const;
};

#endif // tdd_bid_hpp
