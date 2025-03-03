#include <memory>
#include <utility>
#include <vector>
#include "../application/Engine.hpp"
#include "../application/StockMarket.hpp"
#include "../application/interfaces/IMarket.hpp"

int main(void)
{
    const auto stocks = std::vector<std::string>{
        "AXIS",
        "TESLA",
        "FACEBOOK"
    };

    TradingEngine::Application::Engine engine(
        std::unique_ptr<TradingEngine::Interfaces::IMarket>(new TradingEngine::Application::StockMarket(stocks))
    );

    engine.listenForOrders(std::vector<std::pair<std::string, TradingEngine::Entity::Order>> {
        {"AXIS", TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::BUY, 10, 23.0f)},
        {"TESLA", TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::BUY, 5, 20.0f)},
        {"AXIS", TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::SELL, 2, 10.0f)},
        {"FACEBOOK", TradingEngine::Entity::Order(TradingEngine::Entity::OrderType::SELL, 10, 20.0f)},
    });

    return 0;
}
