#ifndef APPLICATION_STATE_H
#define APPLICATION_STATE_H

#include "Truck.h"

/**
 * Application state class.
 * This object stores information about the application's state. The state contains the number of trucks, routs, locations and other information.
 */
class ApplicationState
{
public:
	ApplicationState() = default;

	/**
	 * Register a truck to the state.
	 *
	 * @param truck The truck to be registered.
	 */
	void RegisterTruck(const Truck& truck) { m_trucks.push_back(truck); }

	/**
	 * Register a location to the state.
	 *
	 * @param location The location to register.
	 */
	void RegisterLocation(const Location& location) { m_locations.push_back(location); }

	/**
	 * Register an item to the state.
	 *
	 * @param item The item to register.
	 */
	void RegisterItem(const Item& item) { m_items.push_back(item); }

	/**
	 * Get all the registered trucks.
	 *
	 * @return The trucks.
	 */
	const std::vector<Truck> GetTrucks() const { return m_trucks; }

	/**
	 * Get all the registered trucks.
	 *
	 * @return The truck vector reference.
	 */
	std::vector<Truck>& GetTrucks() { return m_trucks; }

	/**
	 * Get all the locations.
	 *
	 * @return Locations.
	 */
	const std::vector<Location> GetLocations() const { return m_locations; }

	/**
	 * Get all the locations.
	 *
	 * @return The location vector reference.
	 */
	std::vector<Location>& GetLocations() { return m_locations; }

	/**
	 * Get all the items.
	 *
	 * @return The items.
	 */
	const std::vector<Item> GetItems() const { return m_items; }

	/**
	 * Get all the items.
	 *
	 * @return The item vector reference.
	 */
	std::vector<Item>& GetItems() { return m_items; }

	/**
	 * Clear all the registered trucks.
	 */
	void ClearTrucks() { m_trucks.clear(); }

	/**
	 * Clear all the registered locations.
	 */
	void ClearLocations() { m_locations.clear(); }

	/**
	 * Clear all the registered items.
	 */
	void ClearItems() { m_items.clear(); }

private:
	std::vector<Truck> m_trucks;
	std::vector<Location> m_locations;
	std::vector<Item> m_items;
};

#endif