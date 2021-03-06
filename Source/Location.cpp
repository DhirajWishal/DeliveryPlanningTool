// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Location.h"
#include "Utility.h"

#include <stdexcept>

const float Coordinates::Magnitude() const
{
	return std::sqrt(std::pow(X, 2) + std::pow(Y, 2));
}

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

const bool Location::operator!=(const Location& other) const
{
	return !((*this) == other);
}

const int Order::GetSize() const
{
	int size = 0;
	for (const auto item : mPackages)
		size += item.GetSize();

	return size;
}

void Order::Sort()
{
	/**
	 * Comparison operator for the package type.
	 */
	struct Compare
	{
		/**
		 * Comparison operator.
		 *
		 * @param lhs The left hand side argument.
		 * @param rhs The right hand side argument.
		 * @return The boolean value.
		 */
		bool operator()(const Package& lhs, const Package& rhs) const
		{
			return lhs.GetSize() >= rhs.GetSize();
		}
	};

	Utility::MergeSort<Package, Compare>(mPackages);
}

const bool Order::operator==(const Order& other) const
{
	return mLocation == other.mLocation && mPackages == other.mPackages;
}

const bool Order::operator!=(const Order& other) const
{
	return mLocation != other.mLocation || mPackages != other.mPackages;
}
