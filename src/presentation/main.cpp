#include <iostream>
#include <memory>
#include "../application/Engine.hpp"
#include "../application/StockMarket.hpp"
#include "../application/interfaces/IMarket.hpp"

int main(void)
{
    TradingEngine::Application::Engine engine(
        std::unique_ptr<TradingEngine::Interfaces::IMarket>(new TradingEngine::Application::StockMarket())
    );
    return 0;
}
