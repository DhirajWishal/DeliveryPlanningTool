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
	 * Default constructor.
	 */
	Truck() = default;

	/**
	 * Construct the truck object using the truck ID and capacity.
	 * Each truck contains its own unique ID.
	 *
	 * @param ID The truck ID.
	 * @param capacity The capacity of the truck.
	 */
	Truck(int ID, int capacity);

	/**
	 * Get the truck's ID.
	 *
	 * @return The ID.
	 */
	const int GetID() const { return mTruckID; }

	/**
	 * Get the truck's total capacity.
	 *
	 * @return The capacity in cubic meters.
	 */
	const int GetTotalCapacity() const { return mCapacity; }

public:
	/**
	 * Is equal to operator overload.
	 *
	 * @param other The other truck object.
	 * @return Boolean value stating if its equal or not.
	 */
	const bool operator==(const Truck& other) const;

private:
	int mTruckID = 0;
	int mCapacity = 0;					// capacity of the truck in cubic meters.
};

#endif
