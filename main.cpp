#include <iostream>
#include <cstddef>
#include <cstdint>
#include <random>

#include "array.h"


int main(int argc, char* argv[])
{
	//array<int> lst1(8, 3);
	//array<double> lst3(15, 3.14159);
	//array<float> lst2(1000, 0);
	//lst1[0] = 12;
	//lst1[1] = 34;
	//lst3[3] = 33;
	//lst1.print();

	//std::cout << lst1.data_size() << '\t' << lst2.data_size() << '\t' << sizeof(long int) << '\n';
	//double raw_array[10] = { 0.18954932420590787, 0.9815853266153907, 0.1182619429237155, 0.24020743046802462,
	//	0.17391436652827874, 0.452261916487374, 0.35184099296650473, 0.42676874830607936,
	//	0.6457640043603359,0.5178816338229062};
	//
	//array<double> x(raw_array, 10);
	//x.print();



	// Create a random number generator engine (using Mersenne Twister in this case)
	std::mt19937 rng(std::random_device{}());

	// Create a uniform distribution for floating-point numbers between 0 and 1
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	const int64_t N = 20;
	array<double> a(N, 0);
	array<double> b(N, 0);


	for (int i = 0; i < N; i++)
	{
		a[i] = dist(rng);
		b[i] = dist(rng);
	}

	std::cout << "\n";
	std::cout << "Random arrays: \n";

	array<double> c;
	c.add_arrays(a, b);
	c.print();
	std::cout << "\n\n";

	std::cout << "linspace function \n";
	array<double> x;
	x.linspace(0, 10, 101);
	x.print();

	return 0;
}