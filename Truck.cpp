#include "Truck.h"

const int Truck::GetCurrentCapacity() const
{
	int capacity = 0;
	for (const auto location : m_route)
		capacity += location.GetOrderSize();

	return capacity;
}
