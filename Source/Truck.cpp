#include "Truck.h"

#include <stdexcept>

Truck::Truck(int ID, int capacity)
	: m_truckID(ID), m_capacity(capacity)
{
	if (m_capacity == 0)
		throw std::runtime_error("Capacity of a truck should not be zero!");
}

const int Truck::GetCurrentCapacity() const
{
	int capacity = 0;
	for (const auto location : m_route)
		capacity += location.GetOrderSize();

	return capacity;
}

const bool Truck::operator==(const Truck& other) const
{
	return other.m_route == this->m_route && other.m_capacity == this->m_capacity && other.m_truckID == this->m_truckID;
}
