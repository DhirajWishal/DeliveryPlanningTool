#include "Location.h"

const int Location::GetOrderSize() const
{
	int size = 0;
	for (const auto item : m_items)
		size += item.GetSize();

	return size;
}