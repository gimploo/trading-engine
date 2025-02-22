#pragma once
#include "../domain/Order.hpp"
#include <iostream>
#include <vector>

namespace TradingEngine::Application {
    class Engine {
	public:
	    Engine() {
		std::cout << "Engine started";
	    }
	private:
	    std::vector<TradingEngine::Domain::Entity::Order> orders;
    };
}
