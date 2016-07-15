#include <iostream>
using namespace std;

const int MAX = 10;

int list[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };

int find(int data)
{
	int lower = 0;
	int high = MAX - 1;
	int mid = -1;
	int comparisons = 1;
	int index = -1;

	while (lower <= high)
	{
		printf("\nComparison %d  \n", comparisons);
		printf("lower : %d, list[%d] = %d\n", lower, lower, list[lower]);
		printf("high : %d, list[%d] = %d\n", high, high, list[high]);

		comparisons++;
		// probe the mid point 
		mid = lower + (((double)(high - lower) / (list[high] - list[lower])) * (data - list[lower]));
		printf("mid = %d\n", mid);

		// data found 
		if (list[mid] == data) {
			index = mid;
			break;
		}
		else {
			if (list[mid] < data) {
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