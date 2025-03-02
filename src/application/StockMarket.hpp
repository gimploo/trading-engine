#pragma once
#include "Engine.hpp"
#include <memory>

namespace TradingEngine::Application {
    class StockMarket: public Interfaces::IMarket {
    public:
	StockMarket() {}

	std::unique_ptr<Entity::OrderBook> orderBook;
	
	bool validateOrder(const Entity::Order &order) override 
	{
	    //TODO: Implement validation
	    std::cout << "Validating: " << order.getOrderId() << " OK \n";
	    return true;
	};

	void routeOrder(const Entity::Order &order) override 
	{
	    if (validateOrder(order)) {
		orderBook->addOrder(std::move(order));
	    }
	};
    };
}
