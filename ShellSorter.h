//ShellSorter
#pragma once
#include "Sequence.h"
#include "Sorter.h"
#include <functional>

template<typename T>
class ShellSorter : public Sorter<T>
{
private:
	std::vector<std::pair<size_t, size_t>> swaps{};
public:
	void operator()(Containers::Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp) override;
	std::vector<std::pair<size_t, size_t>> GetSwaps() const;
};

template<typename T>
void ShellSorter<T>::operator()(Containers::Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp)
{
	for (size_t step = sequence.GetLength() / 2; step != 0; step /= 2)
		for (size_t i = step; i < sequence.GetLength(); i++)
			for (int j = i - step; (j >= 0) && comp(sequence.Get(j), sequence.Get(j + step)); j -= step)
				sequence.Swap(j, j + step), this->swaps.emplace_back(j, j + step);
}

template<typename T>
std::vector<std::pair<size_t, size_t>> ShellSorter<T>::GetSwaps() const
{
	return this->swaps;
}
