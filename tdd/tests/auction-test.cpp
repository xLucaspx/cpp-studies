#include "catch2/catch_test_macros.hpp"
#include "Auction.hpp"

TEST_CASE("Auction")
{
	SECTION("No consecutive bids from the same user") {
		// ARRANGE || GIVEN
		Auction a("Churrasqueira controle remoto");
		User u("Fausto");

		Bid b1(u, 1000);
		Bid b2(u, 1500);
		Bid b3(User("Augustus"), 1700);

		// ACT || WHEN
		a.addBid(b1);
		a.addBid(b2);
		a.addBid(b3);

		// ASSERT || THEN
		std::vector bids = a.getBids();

		REQUIRE(2 == bids.size());
		REQUIRE(b1.getValue() == bids[0].getValue());
		REQUIRE(b3.getValue() == bids[1].getValue());
	}
}
