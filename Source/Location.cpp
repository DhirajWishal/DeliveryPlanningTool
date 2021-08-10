#include "Location.h"

#include <stdexcept>

Location::Location(const std::string& name)
	: m_name(name) 
{
	if (m_name.empty())
		throw std::runtime_error("Name of a location should not be empty!");
}

const int Location::GetOrderSize() const
{
	int size = 0;
	for (const auto item : m_items)
		size += item.GetSize();

	return size;
}