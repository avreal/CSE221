//============================================================================
// Name        : insertion-sort.cpp
// Author      : Alan Villarreal, Christopher Spear, Sidian Wu
// Date        : 02/14/13
// Copyright   : what
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void
InsertionSort::sort(int A[], int size)				// main entry point
{

	for(int k = 1; k < size; k++)
	{
		int tmp = A[k];
		int j = k;
		for ( ; (j>0) && (num_cmps++,tmp < A[j-1]); j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
  /* Complete this function with the implementation of insertion sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
}
