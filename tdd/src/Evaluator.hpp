#ifndef tdd_avaliador_hpp
#define tdd_avaliador_hpp
#define HIGHEST_BID_COUNT 3

#include <vector>
#include "Bid.hpp"
#include "Auction.hpp"

class Evaluator
{
private:
	float highestValue = INT_MIN;
	float lowestValue = INT_MAX;
	std::vector<Bid> highestBids;

	/**
	 * @return `true` if, and only if, the value of the
	 * first bid is greater than the value of the second bid;
	 * `false` otherwise.
	 */
	static bool compareBids(const Bid &, const Bid &);

public:
	Evaluator();

	void evaluate(const Auction &);

	[[nodiscard]] float getHighestValue() const;

	[[nodiscard]] float getLowestValue() const;

	[[nodiscard]] std::vector<Bid> getHighestBids() const;
};

#endif // tdd_avaliador_hpp
