// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Location.h"

#include <stdexcept>

Location::Location(const QString& name, const QString& address, const Coordinates& coordinates)
	: mName(name), mAddress(address), mCoordinates(coordinates)
{
	if (mName.isEmpty())
		throw std::runtime_error("Name of a location should not be empty!");

	if (mAddress.isEmpty())
		throw std::runtime_error("Address of a location should not be empty!");
}

const bool Location::operator==(const Location& other) const
{
	return other.mName == this->mName && other.mAddress == this->mAddress;
}

const int Order::GetSize() const
{
	int size = 0;
	for (const auto item : mPackages)
		size += item.GetSize();

	return size;
}
