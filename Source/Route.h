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
	void RemoveOrder(const std::string& name);

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

private:
	Truck mTruck = {};
	std::vector<Order> mOrders = {};
	QDateTime mDateTime = QDateTime::currentDateTime();

	int mRouteNumber = 0;
};

#endif
