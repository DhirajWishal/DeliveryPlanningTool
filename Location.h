#ifndef LOCATION_H
#define LOCATION_H

#include "Item.h"
#include <vector>

/**
 * Location object.
 * This object holds information about a single location/ cosmetic shop.
 */
class Location
{
public:
	/**
	 * Construct the location object using the location name.
	 *
	 * @param name The name of the location/ shop.
	 */
	Location(const std::string& name) : m_name(name) {}

	/**
	 * Get the name of the location.
	 *
	 * @return The name.
	 */
	const std::string GetName() const { return m_name; }

	/**
	 * Get the items to deliver.
	 *
	 * @return The vector of items.
	 */
	const std::vector<Item> GetItemList() const { return m_items; }

	/**
	 * Get the size of the order.
	 * This is the addition of all the item sizes.
	 * 
	 * @return The size in cubic meters.
	 */
	const int GetOrderSize() const;

private:
	std::string m_name = "";
	std::vector<Item> m_items;
};

#endif
