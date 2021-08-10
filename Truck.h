#ifndef TRUCK_H
#define TRUCK_H

#include "Location.h"

/**
 * Truck object.
 * This object holds information about a single truck.
 */
class Truck
{
public:
	/**
	 * Construct the truck object using the truck ID and capacity.
	 * Each truck contains its own unique ID.
	 *
	 * @param ID The truck ID.
	 * @param capacity The capacity of the truck.
	 */
	Truck(int ID, int capacity) : m_truckID(ID), m_capacity(capacity) {}

	/**
	 * Get the current route of the truck.
	 *
	 * @return The vector of locations.
	 */
	const std::vector<Location> GetRoute() const { return m_route; }

	/**
	 * Get the truck's ID.
	 * 
	 * @return The ID.
	 */
	const int GetID() const { return m_truckID; }

	/**
	 * Get the truck's total capacity.
	 *
	 * @return The capacity in cubic meters.
	 */
	const int GetTotalCapacity() const { return m_capacity; }

	/**
	 * Get the current capacity of the truck.
	 * 
	 * @return The capacity in cubic meters.
	 */
	const int GetCurrentCapacity() const;

	/**
	 * Add a location to the route.
	 *
	 * @param location The location to be added.
	 */
	void AddLocationToRoute(const Location& location) { m_route.push_back(location); }

private:
	std::vector<Location> m_route;
	int m_truckID = 0;
	int m_capacity = 0;					// capacity of the truck in cubic meters.
};

#endif
