#pragma once
#include "../domain/OrderBook.hpp"
#include "./interfaces/IMarket.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

namespace TradingEngine::Application {
    class Engine {
	public:
	    Engine(std::unique_ptr<Interfaces::IMarket> market): m_market(std::move(market)) { }

	    void listenForOrders(const std::vector<Entity::Order> orders) 
	    {
		for( auto &order: orders ) 
		{
		    m_market->routeOrder(std::move(order));
		}
	    }
	private:
	    std::unique_ptr<Interfaces::IMarket> m_market;
    };
}
