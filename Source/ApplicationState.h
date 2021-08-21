// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef APPLICATION_STATE_H
#define APPLICATION_STATE_H

#include "Route.h"

/**
 * Application state class.
 * This object stores information about the application's state. The state contains the number of trucks, routs, locations and other information.
 */
class ApplicationState
{
public:
	/**
	 * Default constructor.
	 * This sets the initial values of the application.
	 */
	ApplicationState();

	/**
	 * Default destructor.
	 * This dumps the current application state to an external file which is used to load the previous session the next time the application is opened.
	 */
	~ApplicationState();

	/**
	 * Register a truck to the state.
	 *
	 * @param truck The truck to be registered.
	 */
	void RegisterTruck(const Truck& truck) { mTrucks.push_back(truck); }

	/**
	 * Register a location to the state.
	 *
	 * @param location The location to register.
	 */
	void RegisterLocation(const Location& location) { mLocations.push_back(location); }

	/**
	 * Register an item to the state.
	 *
	 * @param item The item to register.
	 */
	void RegisterItem(const Item& item) { mItems.push_back(item); }

	/**
	 * Register a new route to the state.
	 *
	 * @param route The route to register.
	 */
	void RegisterRoute(const Route& route) { mRoutes.push_back(route); }

	/**
	 * Get all the registered trucks.
	 *
	 * @return The trucks.
	 */
	const std::vector<Truck> GetTrucks() const { return mTrucks; }

	/**
	 * Get all the registered trucks.
	 *
	 * @return The truck vector reference.
	 */
	std::vector<Truck>& GetTrucks() { return mTrucks; }

	/**
	 * Find a truck from the application state.
	 *
	 * @param ID The truck ID.
	 * @return The truck. A default truck is returned if not found.
	 */
	const Truck FindTruck(int ID) const;

	/**
	 * Get all the locations.
	 *
	 * @return Locations.
	 */
	const std::vector<Location> GetLocations() const { return mLocations; }

	/**
	 * Get all the locations.
	 *
	 * @return The location vector reference.
	 */
	std::vector<Location>& GetLocations() { return mLocations; }

	/**
	 * Find a location from the application state.
	 *
	 * @param location The location name.
	 * @return The location with the name. This returns a new object if an object was not found.
	 */
	const Location FindLocation(const QString& location) const;

	/**
	 * Check if a given location is present within the application state.
	 *
	 * @param location The location to check.
	 * @return The boolean value stating if its present or not.
	 */
	const bool IsLocationPresent(const Location& location) const;

	/**
	 * Get all the items.
	 *
	 * @return The items.
	 */
	const std::vector<Item> GetItems() const { return mItems; }

	/**
	 * Get all the items.
	 *
	 * @return The item vector reference.
	 */
	std::vector<Item>& GetItems() { return mItems; }

	/**
	 * Find the item name from the application state.
	 *
	 * @param itemName The name of the item.
	 * @return The item with the name. Returns an empty item if not found.
	 */
	const Item FindItem(const QString& itemName) const;

	/**
	 * Get all the routes.
	 *
	 * @return The routes.
	 */
	const std::vector<Route> GetRoutes() const { return mRoutes; }

	/**
	 * Get all the routes.
	 *
	 * @return The route vector reference.
	 */
	std::vector<Route>& GetRoutes() { return mRoutes; }

	/**
	 * Find a route in the application state.
	 *
	 * @param number The route number.
	 * @return The route with the number. If it does not exist, it returns an empty route.
	 */
	const Route FindRoute(int number) const;

	/**
	 * Remove a route from the application.
	 *
	 * @param number The route number.
	 */
	void RemoveRoute(int number);

	/**
	 * Check if a given route is registered.
	 *
	 * @param number: The route number.
	 * @return Boolean stating whether or not the route is present.
	 */
	const bool IsRoutePresent(int number) const;

	/**
	 * Clear all the registered trucks.
	 */
	void ClearTrucks() { mTrucks.clear(); }

	/**
	 * Clear all the registered locations.
	 */
	void ClearLocations() { mLocations.clear(); }

	/**
	 * Clear all the registered items.
	 */
	void ClearItems() { mItems.clear(); }

private:
	/**
	 * Load data from the previous session.
	 * 
	 * @return Boolean stating if the content was loaded successfully.
	 */
	bool LoadData();

	/**
	 * Dump data to an external file.
	 */
	void DumpData() const;

private:
	std::vector<Truck> mTrucks = {};
	std::vector<Location> mLocations = {};
	std::vector<Item> mItems = {};
	std::vector<Route> mRoutes = {};
};

#endif	// APPLICATION_STATE_H