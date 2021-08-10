#include "Item.h"

#include <stdexcept>

Item::Item(const std::string& name, int size)
	: m_name(name), m_size(size)
{
	if (m_name.empty())
		throw std::runtime_error("Item name should not be empty!");

	if (size == 0)
		throw std::runtime_error("Item size should not be zero!");
}
