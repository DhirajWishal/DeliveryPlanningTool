// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef LOCATION_H
#define LOCATION_H

#include "Item.h"
#include <vector>

/**
 * Coordinates structure.
 * This structure holds information about a single location (X and Y location or the latitude and longitude).
 */
struct Coordinates
{
	/**
	 * Default constructor.
	 */
	Coordinates() = default;

	/**
	 * Construct the value using one value which will be assigned to both the fields.
	 * 
	 * @param value The value to set.
	 */
	Coordinates(float value) : X(value), Y(value) {}

	/**
	 * Construct the structure using the two location coordinates.
	 * 
	 * @param x The X location value.
	 * @param y The Y location value.
	 */
	Coordinates(float x, float y) : X(x), Y(y) {}

	union
	{
		struct { float X, Y; };
		struct { float mLatitude, mLongitude; };
	};
};

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
	 * @param coordinates The coordinates of the location.
	 */
	Location(const QString& name, const QString& address, const Coordinates& coordinates);

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

	/**
	 * Get the coordinates of the location.
	 * 
	 * @return The coordinates structure.
	 */
	const Coordinates GetCoordinates() const { return mCoordinates; }

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

	Coordinates mCoordinates = {};
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

#endif	// LOCATION_H
