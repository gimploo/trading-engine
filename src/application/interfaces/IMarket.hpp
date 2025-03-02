#pragma once
#include "../../domain/Order.hpp"

namespace TradingEngine::Interfaces {

    class IMarket {
    public:
	virtual bool validateOrder(const Entity::Order &order) = 0;
	virtual void routeOrder(const Entity::Order &order) = 0;
    };
}
