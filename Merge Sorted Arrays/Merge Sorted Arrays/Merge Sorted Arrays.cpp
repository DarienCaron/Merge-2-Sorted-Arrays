
// Code referenced from https://www.geeksforgeeks.org/merge-two-sorted-arrays/
// Simple application to input 2 sets of 10 digits and merge them into one array.
//Written by Darien Caron
#include "pch.h"
#include <algorithm>
#include <iostream>
using namespace std;



void MergeArrays(int arr1[], int arr2[], int sizeArr1, int sizeArr2, int arr3[])
{
	int aI = 0; // itterator index for our first array
	int bI = 0; // itterator index for our second array
	int cI = 0; // itterator index for our third array

	while (aI < sizeArr1 && bI < sizeArr2) // while our indexes for arrays 1 and 2 are less than then size of our arrays 1 and 2.
	{
		if (arr1[aI] < arr2[bI])		// Compare the size of the first elements in arrays 1 and 2. 
		{								// If true for array 1, store it in array 3 and increment array 1.
										// else its true for array 2.
			arr3[cI++] = arr1[aI++];
		}
		else
		{
			arr3[cI++] = arr2[bI++];
		}
	}

	while (aI < sizeArr1) // Fill the array with the rest of array 1's values
	{
		arr3[cI++] = arr1[aI++];
	}

	while (bI < sizeArr2)  // Fill the array with the rest of array 2's values
	{
		arr3[cI++] = arr2[bI++];
	}

}


int main()
{
	int Arr1Nums[10] = {};


	cout << "Please input 10 digits" << endl;

	for (int i = 0; i < 10; i++) // Cin 10 digits for the first array
	{
		cin >> Arr1Nums[i];

	}

	int Arr2Nums[10] = {};

	cout << "Please input another 10 digits" << endl;

	for (int i = 0; i < 10; i++) // Cin 10 digits for the second array
	{
		cin >> Arr2Nums[i];

	}



	const int size1 = sizeof(Arr1Nums) / sizeof(Arr1Nums[0]); // get the size of array 1

	const int size2 = sizeof(Arr2Nums) / sizeof(Arr2Nums[0]); // get the size of array 2

	int array3[size1 + size2]; // Create an empty 3rd array using both size 1 and 2

	std::sort(Arr1Nums, Arr1Nums + size1); // Sort Array 1
	std::sort(Arr2Nums, Arr2Nums + size2); // Sort Array 2


	MergeArrays(Arr1Nums, Arr2Nums, size1, size2, array3); // Call the merge function.

	cout << "Here are the numbers inputed merged in a sorted order" << endl;

	for (int i = 0; i < size1 + size2; i++)
	{
		cout << array3[i] << " "; // Cout the numbers in array 3
	}


	system("PAUSE");
	return 0;
    
}
