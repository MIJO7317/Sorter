#pragma once
#include "Sequence.h"
#include <functional>

template<typename T>
class Sorter
{
public:
	virtual void operator()(Sequence<T>& sequence, std::function<bool(const T&, const T&)> comp = [](const T& element_1, const T& element_2) {return element_1 > element_2; }) const = 0;
	virtual ~Sorter() {}
};