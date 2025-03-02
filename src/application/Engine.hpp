#pragma once
#include "../domain/OrderBook.hpp"
#include "./interfaces/IMarket.hpp"
#include <algorithm>
#include <iostream>
#include <memory>

namespace TradingEngine::Application {
    class Engine {
	public:
	    Engine(std::unique_ptr<Interfaces::IMarket> market): m_market(std::move(market)) {
		std::cout << "Engine started";
	    }
	private:
	    std::unique_ptr<Interfaces::IMarket> m_market;
    };
}
