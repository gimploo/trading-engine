#pragma once
#include "Engine.hpp"
#include <memory>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include "../domain/OrderBook.hpp"

namespace TradingEngine::Application {
    class StockMarket: public Interfaces::IMarket {
    public:
	explicit StockMarket(const std::vector<std::string> &stocks) : orderBooks([&stocks]() {
	    std::unordered_map<std::string,  std::unique_ptr<Entity::OrderBook>> books;
	    books.reserve(stocks.size());
	    for(const auto &stock: stocks) {
		books.emplace(stock, std::make_unique<Entity::OrderBook>());
	    }
	    return books;
	}()) {}

	std::unordered_map<std::string, std::unique_ptr<Entity::OrderBook>> orderBooks;
	
	bool validateOrder(const Entity::Order &order) override 
	{
	    //TODO: Implement validation
	    return true;
	};

	void routeOrder(const std::string &stockName, const Entity::Order &order) override 
	{
	    std::cout << stockName << " | " << order.getPrice() << " | " << order.getQuantity() << " | " << order.getTimeStamp() << std::endl; 
	    if (validateOrder(order)) {
		orderBooks[stockName]->addOrder(order);
	    }
	};
    };
}
