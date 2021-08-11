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
	 * Default constructor.
	 */
	Item() = default;

	/**
	 * Construct the item using its name and size.
	 *
	 * @param name The name of the item.
	 * @param size The size of the item in cubic meters.
	 */
	Item(const std::string& name, int size);

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

public:
	/**
	 * Is equal to operator.
	 *
	 * @param other The other item.
	 * @return Boolean value stating if its equal or not.
	 */
	const bool operator==(const Item& other) const;

private:
	std::string m_name = "";
	int m_size = 0;				// Size in cubic meters.
};

/**
 * Package structure.
 * This contains information about a single package.
 */
struct Package
{
	/**
	 * Default constructor.
	 */
	Package() = default;

	/**
	 * Construct the package using the item and quantity.
	 *
	 * @param item The item stored in the package.
	 * @param quantity The quantity of items.
	 */
	Package(const Item& item, int quantity) : mItem(item), mQuantity(quantity) {}

	/**
	 * Get the size of the package.
	 *
	 * @return The size in cubic meters.
	 */
	const int GetSize() const { return mItem.GetSize() * mQuantity; }

	Item mItem = {};
	int mQuantity = 0;
};

#endif	// ITEM_H