// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Item.h"

#include <stdexcept>

Item::Item(const QString& name, int size)
	: mName(name), mSize(size)
{
	if (mName.isEmpty())
		throw std::runtime_error("Item name should not be empty!");

	if (size <= 0)
		throw std::runtime_error("Item size should be greater than zero!");
}

const bool Item::operator==(const Item& other) const
{
	return other.mName == this->mName && other.mSize == this->mSize;
}

const bool Item::operator!=(const Item& other) const
{
	return !((*this) == other);
}

const bool Package::operator==(const Package& other) const
{
	return mItem == other.mItem && mQuantity == other.mQuantity;
}

const bool Package::operator!=(const Package& other) const
{
	return !((*this) == other);
}
