#ifndef ROUTE_H
#define ROUTE_H

#include "Truck.h"
#include "Location.h"

/**
 * Route object.
 * This object holds information about a single route.
 */
class Route
{
public:
	/**
	 * Default constructor.
	 */
	Route() = default;

	/**
	 * Construct the route using the route number.
	 * 
	 * @param routeNumber The unique number of the route.
	 */
	Route(int routeNumber) : mRouteNumber(routeNumber) {}

	/**
	 * Construct the route using the route number and truck.
	 * 
	 * @param routeNumber The unique number of the route.
	 * @param truck The truck which uses this route.
	 */
	Route(int routeNumber, const Truck& truck) : mRouteNumber(routeNumber), mTruck(truck) {}

	/**
	 * Add an order to the route.
	 *
	 * @param order The order to add.
	 */
	void AddOrder(const Order& order);

	/**
	 * Get the route number.
	 * 
	 * @return The route number.
	 */
	const int GetNumber() const { return mRouteNumber; }

	/**
	 * Get the truck that is using this route.
	 * 
	 * @return The truck.
	 */
	const Truck GetTruck() const { return mTruck; }

	/**
	 * Get the orders in the route.
	 * 
	 * @return The orders.
	 */
	const std::vector<Order> GetOrders() const { return mOrders; }

	/**
	 * Get the current load of the truck.
	 * 
	 * @return The load in cubic meters.
	 */
	const int GetCurrentLoad() const;

	/**
	 * Check if a location is in the route.
	 * 
	 * @param location The location to check.
	 * @return Boolean value stating if its present in the route or not.
	 */
	const bool IsInRoute(const Location& location) const;

	/**
	 * Get the total item count.
	 * 
	 * @return The item count.
	 */
	const int GetTotalItemCount() const;

	/**
	 * Remove an order using the location's name.
	 * 
	 * @param name The name of the location.
	 */
	void RemoveOrder(const std::string& name);

private:
	Truck mTruck = {};
	std::vector<Order> mOrders = {};

	int mRouteNumber = 0;
};

#endif
