#include <iostream>
#include "Bid.hpp"
#include "Evaluator.hpp"
#include "User.hpp"

int main()
{
	Auction a("Opala 76");
	Bid b1(User("Pafuncio"), 1000);
	Bid b2(User("Jurema"), 2000);

	Evaluator e;

	a.addBid(b1);
	a.addBid(b2);
	e.evaluate(a);

	std::cout << "Lowest bid R$ " << e.getLowestValue() << std::endl;
	std::cout << "Highest bid R$ " << e.getHighestValue() << std::endl;

	auto bids = e.getHighestBids();
	for (auto &b: bids)
		std::cout << b.getUserName() << ", R$ " << b.getValue() << std::endl;

	return 0;
}