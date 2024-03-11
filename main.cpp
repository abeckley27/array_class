#include <iostream>
#include <cstddef>
#include <cstdint>

#include "array.h"


int main(int argc, char* argv[])
{
	array<float> lst(10, 1.5);
	lst.print();

	return 0;
}