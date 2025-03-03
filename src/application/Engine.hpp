#pragma once
#include "./interfaces/IMarket.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace TradingEngine::Application {
    class Engine {
	public:
	    Engine(std::unique_ptr<Interfaces::IMarket> market): m_market(std::move(market)) { }

	    void listenForOrders(const std::vector<std::pair<std::string, Entity::Order>> &marketOrders) 
	    {
		for(const auto &[stock, order]: marketOrders) 
		{
		    m_market->routeOrder(stock, order);
		}
	    }
	private:
	    std::unique_ptr<Interfaces::IMarket> m_market;
    };
}
