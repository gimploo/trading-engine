#include "Order.hpp"

namespace TradingEngine::Entity {

    class Trade {
public:
	explicit Trade(
	    TradingEngine::Entity::Order buyOrder,
	    TradingEngine::Entity::Order sellOrder) : 
	    m_buyOrder(buyOrder), 
	    m_sellOrder(sellOrder)
	    { }

private:
	const TradingEngine::Entity::Order m_buyOrder;
	const TradingEngine::Entity::Order m_sellOrder;
    };
}
