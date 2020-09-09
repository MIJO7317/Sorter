//InsertionSorter
#pragma once
#include "Sequence.h"
#include "Sorter.h"
#include <functional>

template<typename T>
class InsertionSorter : public Sorter<T>
{
public:
	void operator()(Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp) const override;
};

template<typename T>
void InsertionSorter<T>::operator()(Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp) const
{
	for (size_t i = 1; i < sequence.GetLength(); i++)
		for (int j = i - 1; (j >= 0) && comp(sequence.Get(j), sequence.Get(j + 1)); j--)
			sequence.Swap(j, j + 1);
}
