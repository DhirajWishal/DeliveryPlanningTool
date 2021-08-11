#include "Location.h"

#include <stdexcept>

Location::Location(const std::string& name)
	: m_name(name) 
{
	if (m_name.empty())
		throw std::runtime_error("Name of a location should not be empty!");
}

const bool Location::operator==(const Location& other) const
{
	return other.m_name == this->m_name;
}

const int Order::GetSize() const
{
	int size = 0;
	for (const auto item : mPackages)
		size += item.GetSize();

	return size;
}
