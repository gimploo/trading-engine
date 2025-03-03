#pragma once
#include "./OrderType.hpp"
#include <atomic>
#include <cassert>
#include <chrono>
#include <cstdint>

namespace TradingEngine::Entity {


    class Order {
public:
	explicit Order(
	    OrderType type,
	    uint64_t quantity,
	    double price) 
	: m_id(m_total_orders++), m_type(type), m_quantity(quantity), m_price(price), m_timestamp(std::chrono::utc_clock::now()) { 
	    assert(quantity > 0 && "Order quantity needs to be greater than zero");
	}

	const OrderType getOrderType() const { return m_type; } 
	const uint64_t getOrderId() const { return m_id; } 
	const double getTotalPrice() const { return m_quantity * m_price; }
	const double getPrice() const { return m_price; }
	const uint64_t getQuantity() const { return m_quantity; } 
	const std::chrono::time_point<std::chrono::utc_clock> getTimeStamp() const { return m_timestamp; }

	void setQuantity(const uint64_t newQuantity) {
	    assert(newQuantity > 0);
	    m_quantity = newQuantity;
	}

private:
	inline static uint64_t m_total_orders;
	uint64_t m_id;
	OrderType m_type;
	uint64_t m_quantity;
	double m_price;
	std::chrono::time_point<std::chrono::utc_clock> m_timestamp;
    };

}

