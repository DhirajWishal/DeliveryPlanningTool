// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef ROUTE_H
#define ROUTE_H

#include "Truck.h"
#include "Location.h"

#include <QtCore/QDateTime.h>

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
	Route(int routeNumber, const QDateTime& dateTime = QDateTime::currentDateTime()) : mRouteNumber(routeNumber), mDateTime(dateTime) {}

	/**
	 * Construct the route using the route number and truck.
	 *
	 * @param routeNumber The unique number of the route.
	 * @param truck The truck which uses this route.
	 */
	Route(int routeNumber, const Truck& truck, const QDateTime& dateTime = QDateTime::currentDateTime()) : mRouteNumber(routeNumber), mTruck(truck), mDateTime(dateTime) {}

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
	 * Get the orders in the route.
	 *
	 * @return The order vector reference.
	 */
	std::vector<Order>& GetOrders() { return mOrders; }

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
	void RemoveOrder(const QString& name);

	/**
	 * Get the date and time in which the route was created.
	 *
	 * @return The date time object.
	 */
	const QDateTime GetDateTime() const { return mDateTime; }

	/**
	 * Get the date and time in a formatted string.
	 *
	 * @return The date and time string.
	 */
	const QString GetFormattedDateTimeString() const { return mDateTime.toString("dd.MM.yyyy hh:mm:ss"); }

	/**
	 * Get the date in a formatted string.
	 * 
	 * @return The date in a string.
	 */
	const QString GetFormattedDateString() const { return mDateTime.toString("dd.MM.yyyy"); }

	/**
	 * Sort the route locations to reduct the total travel distance.
	 * 
	 * What we end up with is a list of locations, where each and every location (node) needs to be traveled through ONCE, and should not be ignored. This means that using a
	 * path finding algorithm, like A* or Dijkstra is not applicable. A sorting algorithm best suites this scenario as we just need to sort the location list so that
	 * we end up with the lowest cost (total distance to travel).
	 * 
	 * For sorting, we assume that the location with the highest magnitude (coordinates) is considered as the starting point and the location with the lowest magnitude as the ending
	 * point (assuming that the city of Toronto is the origin (0, 0)). From this, we can sort the array using a wide variety of sorting algorithms.
	 * But for this scenario, I went with merge sort as its worse, best and average performance is O(n log n).
	 * 
	 * Another optimization would be to store the orders in a BST structure (Binary Search Tree). For this, we just need to swap out the std::vector with std::set. But doing so defeats
	 * the purpose of this test task, and might even result in worse performance (since array traversal is far more faster than list traversal due to data locality).
	 */
	void Sort();

private:
	Truck mTruck = {};
	std::vector<Order> mOrders = {};
	QDateTime mDateTime = QDateTime::currentDateTime();

	int mRouteNumber = 0;
};

#endif	// ROUTE_H
