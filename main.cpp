#include <iostream>
#include <cstddef>
#include <cstdint>

#include "array.h"


int main(int argc, char* argv[])
{
	array<int> lst1(8, 3);
	array<double> lst3(10, 3.14159);
	array<float> lst2(1000, 0);
	lst1[0] = 12;
	lst1[1] = 34;
	lst3[3] = 33;
	lst1.print();

	std::cout << lst1.data_size() << '\t' << lst2.data_size() << '\t' << lst3.data_size() << '\n';


	return 0;
}