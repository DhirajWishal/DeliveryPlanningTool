// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#ifndef UTILITY_H
#define UTILITY_H

#include <vector>

namespace Utility
{
	/**
	 * Perform merge sort on the input vector.
	 * 
	 * @param input The input vector.
	 * @tparam Type The input vector type.
	 * @tparam Compare The comparison operator. Default is std::less.
	 */
	template<typename Type, typename Compare = std::less<Type>>
	void MergeSort(std::vector<Type>& input)
	{
		const Compare compare = Compare{};
		const size_t orderCount = input.size();
		std::vector<Type> temporary(orderCount);

		// Perform merge sort on the items.
		for (size_t i = 1; i < orderCount; i *= 2)
		{
			for (size_t j = 0; j < orderCount; j += 2 * i)
			{
				const size_t left = j;
				const size_t right = std::min(j + i, orderCount);
				const size_t end = std::min(j + 2 * i, orderCount);

				size_t firstHalf = left, secondHalf = right;

				// Sort and merge the two halves.
				for (size_t k = left; k < end; k++)
				{
					if (firstHalf < right && (secondHalf >= end || compare(input[firstHalf], input[secondHalf])))
						temporary[k] = input[firstHalf], firstHalf++;
					else
						temporary[k] = input[secondHalf], secondHalf++;
				}
			}

			std::copy(temporary.begin(), temporary.end(), input.begin());
		}
	}
}

#endif	// UTILITY_H
