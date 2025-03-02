#include <iostream>
#include <memory>
#include <vector>
#include "../application/Engine.hpp"
#include "../application/StockMarket.hpp"
#include "../application/interfaces/IMarket.hpp"

int main(void)
{
    TradingEngine::Application::Engine engine(
        std::unique_ptr<TradingEngine::Interfaces::IMarket>(new TradingEngine::Application::StockMarket())
    );

    engine.listenForOrders(std::vector<TradingEngine::Entity::Order> {
        TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::BUY, 10, 23.0f),
        TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::BUY, 5, 20.0f),
        TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::SELL, 2, 10.0f),
        TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::SELL, 10, 20.0f),
    });

    return 0;
}
