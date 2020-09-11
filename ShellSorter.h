//ShellSorter
#pragma once
#include "Sequence.h"
#include "Sorter.h"
#include <functional>

template<typename T>
class ShellSorter : public Sorter<T>
{
public:
	void operator()(Containers::Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp) const override;
};

template<typename T>
void ShellSorter<T>::operator()(Containers::Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp) const
{
	for (size_t step = sequence.GetLength() / 2; step != 0; step /= 2)
		for (size_t i = step; i < sequence.GetLength(); i++)
			for (int j = i - step; (j >= 0) && comp(sequence.Get(j), sequence.Get(j + step)); j -= step)
				sequence.Swap(j, j + step);
}
