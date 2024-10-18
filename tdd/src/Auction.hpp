#ifndef  tdd_auction_hpp
#define  tdd_auction_hpp

#include <vector>
#include "Bid.hpp"

class Auction
{
private:
	std::vector<Bid> bids;
	std::string description;

public:
	explicit Auction(std::string description);

	[[nodiscard]] const std::vector<Bid> &getBids() const;

	void addBid(const Bid &bid);
};

#endif // tdd_auction_hpp
