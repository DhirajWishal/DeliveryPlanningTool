// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "Item.h"

#include <stdexcept>

Item::Item(const std::string& name, int size)
	: mName(name), m_size(size)
{
	if (mName.empty())
		throw std::runtime_error("Item name should not be empty!");

	if (size <= 0)
		throw std::runtime_error("Item size should be greater than zero!");
}

const bool Item::operator==(const Item& other) const
{
	return other.mName == this->mName && other.m_size == this->m_size;
}
