#include "search.h"
using namespace std;

int intArray[MAX] = { 1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66 };

search::search()
{
}

search::~search()
{
	
}

int search::lineSearch(int data)
{
	int comparisons = 0;
	int index = -1;
	for (int i = 0; i < MAX; i++)
	{
		comparisons++;
		if (data == intArray[i])
		{
			index = i;
			break;
		}
	}
	cout << "Total comparisons made: " << comparisons << endl;
	return index;
}

int search::interpolationSearch(int data)
{
	int lower = 0;
	int high = MAX - 1;
	int mid = -1;
	int comparisons = 1;
	int index = -1;

	while (lower <= high)
	{
		printf("\nComparison %d  \n", comparisons);
		printf("lower : %d, list[%d] = %d\n", lower, lower, intArray[lower]);
		printf("high : %d, list[%d] = %d\n", high, high, intArray[high]);

		comparisons++;
		// probe the mid point 
		mid = lower + (((double)(high - lower) / (intArray[high] - intArray[lower])) * (data - intArray[lower]));
		printf("mid = %d\n", mid);

		// data found 
		if (intArray[mid] == data) {
			index = mid;
			break;
		}
		else {
			if (intArray[mid] < data) {
				// if data is larger, data is in upper half 
				lower = mid + 1;
			}
			else {
				// if data is smaller, data is in lower half 
				high = mid - 1;
			}
		}
	}

	printf("\nTotal comparisons made: %d", --comparisons);
	return index;
}

int search::binarySearch(int data)
{
	int lowerBound = 0;
	int upperBound = MAX - 1;
	int midPoint = -1;
	int comparisons = 0;
	int index = -1;

	while (lowerBound <= upperBound)
	{
		cout << "Comparison " << comparisons + 1 << endl;
		cout << "lowerBound :" << lowerBound << ", intArray[" << lowerBound << "] = " << intArray[lowerBound] << endl;
		cout << "upperBound :" << upperBound << ", intArray[" << upperBound << "] = " << intArray[upperBound] << endl;
		comparisons++;

		// compute the mid point 
		// midPoint = (lowerBound + upperBound) / 2;
		midPoint = lowerBound + (upperBound - lowerBound) / 2;

		// data found
		if (intArray[midPoint] == data) {
			index = midPoint;
			break;
		}
		else {
			// if data is larger 
			if (intArray[midPoint] < data) {
				// data is in upper half
				lowerBound = midPoint + 1;
			}
			// data is smaller 
			else {
				// data is in lower half 
				upperBound = midPoint - 1;
			}
		}
	}
	cout << "Total Comparisons made: " << comparisons << endl;
	return index;
}
