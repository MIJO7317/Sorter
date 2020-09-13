#include<iostream>
#include"ShellSorter.h"
#include"InsertionSorter.h"
#include"ArraySequence.h"
#include"ListSequence.h"

template<typename T>
void Sort(Containers::Sequence<T>& arr, Sorter<T>& sorter = ShellSorter<T>{})
{
	sorter(arr);
	std::cout << sorter.GetSwaps().size() << std::endl;
}

int main()
{
	Containers::ArraySequence<int> arr = {1,4,6,7,3,9,5,1,6,67,34,24,86,3,5,7,34,886,34,77,43,66,21};
	for (size_t i = 0; i < arr.GetLength(); i++)
	{
		std::cout << arr.Get(i) << ' ';
	}
	std::cout << std::endl;
	InsertionSorter<int> ins_sorter;
	ShellSorter<int> shell_sorter;
	Sort(arr, shell_sorter);
	for (size_t i = 0; i < arr.GetLength(); i++)
	{
		std::cout << arr.Get(i) << ' ';
	}
	std::cout << std::endl;
}