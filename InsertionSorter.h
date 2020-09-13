//InsertionSorter
#pragma once
#include "Sequence.h"
#include "Sorter.h"
#include <functional>
#include <vector>
#include <utility>

template<typename T>
class InsertionSorter : public Sorter<T>
{
private:
	std::vector<std::pair<size_t, size_t>> swaps{};
public:
	void operator()(Containers::Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp) override;
	std::vector<std::pair<size_t, size_t>> GetSwaps() const;
};

template<typename T>
void InsertionSorter<T>::operator()(Containers::Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp)
{
	for (size_t i = 1; i < sequence.GetLength(); i++)
		for (int j = i - 1; (j >= 0) && comp(sequence.Get(j), sequence.Get(j + 1)); j--)
			sequence.Swap(j, j + 1), this->swaps.emplace_back(j, j + 1);
}

template<typename T>
std::vector<std::pair<size_t, size_t>> InsertionSorter<T>::GetSwaps() const
{
	return this->swaps;
}
