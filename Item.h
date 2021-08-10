#ifndef ITEM_H
#define ITEM_H

#include <string>

/**
 * Item object.
 * This object holds information about a single cosmetic item.
 */
class Item
{
public:
	/**
	 * Construct the item using its name and size.
	 *
	 * @param name The name of the item.
	 * @param size The size of the item in cubic meters.
	 */
	Item(const std::string& name, int size) : m_name(name), m_size(size) {}

	/**
	 * Get the name of the item.
	 *
	 * @return The name of the item.
	 */
	const std::string GetName() const { return m_name; }

	/**
	 * Get the size of the item.
	 *
	 * @return The size in cubic meters.
	 */
	const int GetSize() const { return m_size; }

private:
	std::string m_name = "";
	int m_size = 0;				// Size in cubic meters.
};

#endif	// ITEM_H