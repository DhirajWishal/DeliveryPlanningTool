#include "Truck.h"

#include <stdexcept>

Truck::Truck(int ID, int capacity)
	: mTruckID(ID), mCapacity(capacity)
{
	if (mCapacity == 0)
		throw std::runtime_error("Capacity of a truck should not be zero!");
}

const bool Truck::operator==(const Truck& other) const
{
	return other.mCapacity == this->mCapacity && other.mTruckID == this->mTruckID;
}
