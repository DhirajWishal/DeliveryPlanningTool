// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Route.h"

#include <stdexcept>

#define HIGH_MAGNITUDE	100000.0f

namespace Helpers
{
	/**
	 * Find the distance between two order locations.
	 *
	 * @param lhs The left hand side argument.
	 * @param rhs The right hand side argument.
	 * @return The distance between the two points.
	 */
	float Distance(const Order lhs, const Order rhs)
	{
		const float base = std::pow(std::abs(lhs.mLocation.GetCoordinates().X - rhs.mLocation.GetCoordinates().X), 2);
		const float height = std::pow(std::abs(lhs.mLocation.GetCoordinates().Y - rhs.mLocation.GetCoordinates().Y), 2);
		return std::sqrt(base + height);
	}

	/**
	 * Find the total distance the truck has to travel.
	 *
	 * @param orders The orders the truck needs to deliver.
	 * @return The distance.
	 */
	float TotalDistance(const std::vector<Order> orders)
	{
		float distance = 0;

		if (orders.empty() || orders.size() == 1)
			return distance;

		Order previous = orders.front();
		for (int i = 1; i < orders.size(); i++)
		{
			distance += Distance(previous, orders[i]);
			previous = orders[i];
		}

		return distance;
	}
}

void Route::AddOrder(const Order& order)
{
	int load = 0;
	for (const Order order : mOrders)
		load += order.GetSize();

	// Check if the current location would require more space than whats available.
	if (load + order.GetSize() > mTruck.GetTotalCapacity())
		throw std::runtime_error("Cannot add the location \"" + order.mLocation.GetName().toStdString() + "\". The order size is too big for the truck!");

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

void Route::RemoveOrder(const QString& name)
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

void Route::Sort()
{
	const size_t orderCount = mOrders.size();
	std::vector<Order> temporary(mOrders.size());

	// Perform merge sort on the orders.
	for (size_t i = 1; i < orderCount; i *= 2)
	{
		for (size_t j = 0; j < orderCount; j += 2 * i)
		{
			const size_t left = j;
			const size_t right = std::min(j + i, orderCount);
			const size_t end = std::min(j + 2 * i, orderCount);

			size_t firstHalf = left, secondHalf = right;

			// Sort and merge the two halves.
			for (size_t k = left; k < end; k++)
			{
				if (firstHalf < right && (secondHalf >= end || mOrders[firstHalf].mLocation.GetCoordinates().Magnitude() >= mOrders[secondHalf].mLocation.GetCoordinates().Magnitude()))
					temporary[k] = mOrders[firstHalf], firstHalf++;
				else
					temporary[k] = mOrders[secondHalf], secondHalf++;
			}
		}

		std::copy(temporary.begin(), temporary.end(), mOrders.begin());
	}
}
