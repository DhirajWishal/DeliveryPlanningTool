// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef ITEM_H
#define ITEM_H

#include <QString.h>

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
	Item(const QString& name, int size);

	/**
	 * Get the name of the item.
	 *
	 * @return The name of the item.
	 */
	const QString GetName() const { return mName; }

	/**
	 * Get the size of the item.
	 *
	 * @return The size in cubic meters.
	 */
	const int GetSize() const { return mSize; }

public:
	/**
	 * Is equal to operator.
	 *
	 * @param other The other item.
	 * @return Boolean value stating if its equal or not.
	 */
	const bool operator==(const Item& other) const;

	/**
	 * Is not equal to operator.
	 *
	 * @param other The other item.
	 * @return Boolean value stating if its not equal.
	 */
	const bool operator!=(const Item& other) const;

private:
	QString mName = "";
	int mSize = 0;				// Size in cubic meters.
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

	/**
	 * Is equal to operator.
	 *
	 * @param other The other package.
	 * @return The boolean value stating if its equal to this.
	 */
	const bool operator==(const Package& other) const;

	/**
	 * Is not equal to operator.
	 * 
	 * @param other The other package.
	 * @return The boolean value stating if its not equal to this.
	 */
	const bool operator!=(const Package& other) const;

	Item mItem = {};
	int mQuantity = 0;
};

#endif	// ITEM_H