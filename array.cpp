#include <iostream>

#include "array.h"



template<typename T>
void array<T>::print()
{
	for (int i = 0; i < n_alloc - 1; i++)
	{
		std::cout << data[i] << ", ";
	}
	std::cout << data[n_alloc - 1] << std::endl;
}



