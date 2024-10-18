#ifndef tdd_user_hpp
#define tdd_user_hpp

#include <string>

class User
{
private:
	std::string name;

public:
	explicit User(std::string name);

	[[nodiscard]] std::string getName() const;

	[[nodiscard]] std::string getFirstName() const;
};

#endif // tdd_user_hpp
