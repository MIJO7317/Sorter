#include<iostream>
#include"ShellSorter.h"
#include"InsertionSorter.h"
#include"ArraySequence.h"
#include"ListSequence.h"

template<typename T>
void Sort(Sequence<T>& arr, const Sorter<T>& sorter = ShellSorter<T>{})
{
	sorter(arr);
}

int main()
{
	ArraySequence<int> arr = {1,4,6,7,3,9,5,1,6,67,34,24,86,3,5,7,34,886,34,77,43,66,21};
	for (size_t i = 0; i < arr.GetLength(); i++)
	{
		std::cout << arr.Get(i) << ' ';
	}
	std::cout << std::endl;
	Sort(arr, InsertionSorter<int>{});
	for (size_t i = 0; i < arr.GetLength(); i++)
	{
		std::cout << arr.Get(i) << ' ';
	}
	std::cout << std::endl;
}