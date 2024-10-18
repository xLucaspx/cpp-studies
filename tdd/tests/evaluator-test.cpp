#include "../src/Auction.hpp"
#include "../src/Evaluator.hpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/generators/catch_generators.hpp"

/**
 * @return An auction in which the first bid value is greater than the second one.
 */
Auction increasingOrderBids()
{
	Auction a("Opala 76");
	Bid b1(User("Pafuncio"), 1000);
	Bid b2(User("Jurema"), 2000);

	a.addBid(b1);
	a.addBid(b2);

	return a;
}

/**
 * @return An auction in which the first bid value is smaller than the second one.
 */
Auction decreasingOrderBids()
{
	Auction a("Opala 76");
	Bid b1(User("Pafuncio"), 1000);
	Bid b2(User("Jurema"), 2000);

	a.addBid(b1);
	a.addBid(b2);

	return a;
}

TEST_CASE("Evaluator")
{
	// ARRANGE || GIVEN
	// the TEST_CASE code is executed one time for each inner section
	Evaluator e;

	// ACT || WHEN
	SECTION("Bid orders") {
		// each test inside this section will be repeated for each argument
		// provided to GENERATE, i.e., for an auction with increasing order bids
		// and another with decreasing order bids.
		Auction a = GENERATE(increasingOrderBids(), decreasingOrderBids());
		e.evaluate(a);

		SECTION("Must retrieve highest bid value") {
			// ASSERT || THEN
			REQUIRE(2000 == e.getHighestValue());
		}

		SECTION("Must retrieve lowest bid value") {
			REQUIRE(1000 == e.getLowestValue());
		}
	}

	SECTION("Highest bids") {
		Auction a("Opala 76");
		Bid highest(User("Joaozinho"), 5000);
		Bid medium(User("Mariazinha"), 3500);
		Bid lowest(User("Kleberson"), 1200);
		Bid evenLower(User("Robertina"), 900);

		a.addBid(evenLower);
		a.addBid(lowest);
		a.addBid(medium);
		a.addBid(highest);

		e.evaluate(a);
		std::vector<Bid> bids = e.getHighestBids();

		REQUIRE(HIGHEST_BID_COUNT == bids.size());
		REQUIRE(highest.getValue() == bids[0].getValue());
		REQUIRE(medium.getValue() == bids[1].getValue());
		REQUIRE(lowest.getValue() == bids[2].getValue());
	}
}
