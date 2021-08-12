// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

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
	 * Default constructor.
	 */
	Location() = default;

	/**
	 * Construct the location object using the location name.
	 *
	 * @param name The name of the location/ shop.
	 * @param address The address of the location.
	 */
	Location(const QString& name, const QString& address);

	/**
	 * Get the name of the location.
	 *
	 * @return The name.
	 */
	const QString GetName() const { return mName; }

	/**
	 * Get the address of the location.
	 * 
	 * @return The address string.
	 */
	const QString GetAddress() const { return mAddress; }

public:
	/**
	 * Is equal to operator.
	 *
	 * @param other The other location.
	 * @return Boolean value stating if its equal or not.
	 */
	const bool operator==(const Location& other) const;

private:
	QString mName = "";
	QString mAddress = "";
};

/**
 * Order structure.
 * This structure contains information about a single order for a location.
 */
struct Order
{
	/**
	 * Default constructor.
	 */
	Order() = default;

	/**
	 * Construct the structure using the location and packages.
	 * 
	 * @param location The location to which the order is to be delivered.
	 * @param packages The packages to deliver. Default is {}.
	 */
	Order(const Location& location, const std::vector<Package>& packages = {}) : mLocation(location), mPackages(packages) {}

	/**
	 * Get the size of the order.
	 * 
	 * @return The size in cubic meters.
	 */
	const int GetSize() const;

	Location mLocation = {};
	std::vector<Package> mPackages = {};
};

#endif
