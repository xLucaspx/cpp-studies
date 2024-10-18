#include <vector>
#include <algorithm>
#include "Evaluator.hpp"

Evaluator::Evaluator()
{
	highestBids.reserve(HIGHEST_BID_COUNT);
}

bool Evaluator::compareBids(const Bid &bid1, const Bid &bid2)
{
	return bid1.getValue() > bid2.getValue();
}

void Evaluator::evaluate(const Auction &a)
{
	std::vector<Bid> bids = a.getBids();

	for (const Bid &b: bids) {
		float value = b.getValue();
		if (value > highestValue) {
			highestValue = value;
		}
		if (value < lowestValue) {
			lowestValue = value;
		}
	}

	std::sort(bids.begin(), bids.end(), compareBids);
	size_t size = bids.size() > HIGHEST_BID_COUNT ? HIGHEST_BID_COUNT : bids.size();
	highestBids.assign(bids.begin(), bids.begin() + size);
}

std::vector<Bid> Evaluator::getHighestBids() const
{
	return highestBids;
}

float Evaluator::getHighestValue() const
{
	return highestValue;
}

float Evaluator::getLowestValue() const
{
	return lowestValue;
}
