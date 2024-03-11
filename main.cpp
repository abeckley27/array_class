#include <iostream>
#include <cstddef>
#include <cstdint>

#include "array.h"


int main(int argc, char* argv[])
{
	array<int> lst1(8, 3298);
	array<double> lst2(10, 3.14159);
	array<float> lst3(1000, 0);
	lst1.print();
	lst2.print();
	lst3.print();

	return 0;
}