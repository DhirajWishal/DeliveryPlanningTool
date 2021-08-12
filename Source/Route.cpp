// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Route.h"

#include <stdexcept>

void Route::AddOrder(const Order& order)
{
	int load = 0;
	for (const Order order : mOrders)
		load += order.GetSize();

	// Check if the current location would require more space than whats available.
	if (load + order.GetSize() > mTruck.GetTotalCapacity())
		throw std::runtime_error("Cannot add the location \"" + order.mLocation.GetName() + "\". The order size is too big for the truck!");

	mOrders.push_back(order);
}

const int Route::GetCurrentLoad() const
{
	int load = 0;
	for (const Order order : mOrders)
		load += order.GetSize();

	return load;
}

const bool Route::IsInRoute(const Location& location) const
{
	for (const Order order : mOrders)
		if (order.mLocation == location)
			return true;

	return false;
}

const int Route::GetTotalItemCount() const
{
	int count = 0;
	for (const Order order : mOrders)
		count += static_cast<int>(order.mPackages.size());

	return count;
}

void Route::RemoveOrder(const std::string& name)
{
	for (auto itr = mOrders.begin(); itr != mOrders.end(); itr++)
	{
		if (itr->mLocation.GetName() == name)
		{
			mOrders.erase(itr);
			return;
		}
	}
}
