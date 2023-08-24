
#pragma once
#include <iostream>
#include "timer.h"

using namespace std;

class SortPerformance {
private:
	double* list;
	long size;
	//################################################# 
// @par Name 
//    insertionSort
// @purpose 
//   sorts something into the proper location
// @param [in] : 
//     list,last, x
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void insertionSort(double* list, int last, long long int& x)
	{
		double hold = 0;
		int search = 0;

		for (int current = 1; current <= last; current++)
		{
			hold = list[current];
			for (search = current - 1; search >= 0 && hold < list[search]; search--)
			{
				x++;
				list[search + 1] = list[search];
			}
			list[search + 1] = hold;
		}
		return;

	}
	//################################################# 
// @par Name 
//    selectionSort
// @purpose 
//    finds the smallest element in the unsorted list and moves it to the top of the list
// @param [in] : 
//     list,last,x
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void selectionSort(double* list, int last, long long int& x)
	{
		int smallest = 0;
		
		double holdData = 0;

		for (int current = 0; current < last; current++)
		{
			smallest = current;
			for (int index = current + 1; index <= last; index++)
			{
				x++;
				if (list[index] < list[smallest])
				{
					smallest = index;
				}
			}
			holdData = list[current];
			list[current] = list[smallest];
			list[smallest] = holdData;
		}
		return;
	}
	//################################################# 
// @par Name 
//   shellSort
// @purpose 
//    sorts something into the proper location
// @param [in] : 
//     list,last,x
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void shellSort(double* list, int last, long long int& x)
	{
		
		double hold; 
		int incre;
		int index;

		incre = last / 2;
		while (incre != 0)
		{
			for (int curr = incre; curr <= last; curr++)
			{
				x++;
				hold = list[curr];
				index = curr - incre;
				while (index >= 0 && hold < list[index])
				{
					x += 2;

					list[index + incre] = list[index];

					index = (index - incre);
				}
				x++;

				list[index + incre] = hold;
			}


			incre = incre / 2;
		}
		return;
	}
	//################################################# 
// @par Name 
//    merge
// @purpose 
//   merges something into list
// @param [in] : 
//     low,high,mid,x
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void merge(double* a, int low, int high, int mid, long long int& x)
	{
		double c[100000]; 
		int i, j, k;
		i = low;
		j = mid + 1;
		k = low;
		while ((i <= mid) && (j <= high))
		{
			x++;
			if (a[i] < a[j])
			{
				c[k] = a[i];
				k++;
				i++;
			}
			else
			{
				c[k] = a[j];
				k++;
				j++;
			}
		}
		while (i <= mid)
		{
			c[k] = a[j];
			k++;
			i++;
			x++;
		}
		while (j <= high)
		{
			c[k] = a[i];
			k++;
			j++;
			x++;
		}
		for (i = low; i < k; i++)
		{
			a[i] = c[i];
			x++;
		}
	}
	
	int mergesort(double* a, int low, int high, long long int& x)
	{
		int mid;
		if (low < high)
		{
			mid = (low + high) / 2;
			mergesort(a, low, mid, x);
			mergesort(a, mid + 1, high, x);
			merge(a, low, high, mid, x);

		}
		return(0);
	}

	void copyList(double* cl) {
		for (int i = 0; i < size; i++)
			cl[i] = list[i];
	}

public:
	SortPerformance() {
		this->list = NULL;
		this->size = 0;
	}

	SortPerformance(double* list, long size) {
		this->list = list;
		this->size = size;
	}

	void setList(double* list, long size) {
		this->list = list;
		this->size = size;
	}
	//################################################# 
// @par Name 
//    measurePerformance
// @purpose 
//    uses timer.h to output a simulation of the sorted list
// @param [in] : 
//     None 
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void measurePerformance() {
		Timer t;
		long long int iterations;
		double* cl = new double[size];

		copyList(cl);
		iterations = 0;
		t.startTimer();
		insertionSort(cl, size - 1, iterations);
		t.stopTimer();
		cout << "Insertion sort took " << t.getSeconds() << " seconds and " << iterations << " iterations to sort the list." << endl;

		copyList(cl);
		iterations = 0;
		t.startTimer();
		selectionSort(cl, size - 1, iterations);
		t.stopTimer();
		cout << "Selection sort took " << t.getSeconds() << " seconds and " << iterations << " iterations to sort the list." << endl;

		copyList(cl);
		iterations = 0;
		t.startTimer();
		shellSort(cl, size - 1, iterations);
		t.stopTimer();
		cout << "Shell sort took " << t.getSeconds() << " seconds and " << iterations << " iterations to sort the list." << endl;

		copyList(cl);
		iterations = 0;
		t.startTimer();
		mergesort(cl, 0, size - 1, iterations);
		t.stopTimer();
		cout << "Merge sort took " << t.getSeconds() << " seconds and " << iterations << " iterations to sort the list." << endl;

		cout << endl;
		delete[] cl;
	}
};
