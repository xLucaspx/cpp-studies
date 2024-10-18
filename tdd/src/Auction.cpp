#include <utility>
#include "Auction.hpp"

Auction::Auction(std::string description) : description(std::move(description))
{}

const std::vector<Bid> &Auction::getBids() const
{
	return bids;
}

void Auction::addBid(const Bid &bid)
{
	if (bids.empty() || bids.back().getUserName() != bid.getUserName()) {
		bids.push_back(bid);
	}
}
