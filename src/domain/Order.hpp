#pragma once
#include "./OrderType.hpp"

namespace TradingEngine::Domain::Entity {

    class Order {
	public:
	    Order(
		OrderType type,
		long int quantity,
		double price) 
	    : m_type(type), m_quantity(quantity), m_price(price) { }

	private:
	    OrderType m_type;
	    long int m_quantity;
	    double m_price;
    };

}

