




#include<iostream>
#include <cstdlib>
#include <limits>


#define NOMINMAX


#include "sort_performance.h"

using namespace std;
using std::cout;
using std::endl;

double randDouble() {
	double min = numeric_limits<double>::min(), max = numeric_limits<double>::max();
	double num = (double)rand() / RAND_MAX;
	return min + num * (max - min);
}

int main()
{
	SortPerformance sp;
	double* list;
	for (long size = 10000; size <= 100000; size += 10000) {
		list = new double[size];
		for (int i = 0; i < size; i++)
			list[i] = randDouble();
		sp.setList(list, size);

		cout << "Simulation " << size / 10000 << " with random list of size " << size << ":" << endl;
		sp.measurePerformance();
		delete[] list;
	}
	return 0;
}
