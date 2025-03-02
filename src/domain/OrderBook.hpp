#pragma once
#include "Order.hpp"
#include <map>
#include <vector>
#include "Trade.hpp"

namespace TradingEngine::Entity {
    class OrderBook {
public:
	void addOrder(const Order& order) {
	    if (order.getOrderType() == OrderType::BUY) {
		m_buyOrders.insert({ order.getTotalPrice(), order });
		
	    } else if (order.getOrderType() == OrderType::SELL) {
		m_sellOrders.insert({ order.getTotalPrice(), order });
	    } 
	    assert("Unknown order type");
	}


private:
	std::map<uint64_t, Order> m_buyOrders;
	std::map<uint64_t, Order> m_sellOrders;
	std::vector<Trade> m_orderMatches;

	void matchOrderingViaFIFO()
	{
	    for( const auto& [buyTotalPrice, buyOrder]: m_buyOrders)
	    {
		for( auto& [sellTotalPrice, sellOrder]: m_sellOrders)
		{
		    if (buyTotalPrice <= sellTotalPrice) 
		    {
			m_orderMatches.push_back(Trade(buyOrder, sellOrder));
			const double remaining = sellTotalPrice - buyTotalPrice;
			if (remaining > 0) {
			    const double sellRemainingOrder = remaining / sellOrder.getPrice();
			    sellOrder.setQuantity(sellRemainingOrder);
			}
		    }
		}
	    }
	}
    };
}
