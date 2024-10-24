#include "../src/User.hpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/generators/catch_generators.hpp"

TEST_CASE("User")
{
	SECTION("Must retrieve the user first name") {
		// code in this section will be executed one time for each argument provided to GENERATE
		User u = GENERATE(User("Rodolfo Silva"), User("Rodolfo"));

		std::string firstName = u.getFirstName();

		REQUIRE("Rodolfo" == firstName);
	}
}
