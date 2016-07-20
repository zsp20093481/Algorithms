#include "sort.h"
using namespace std;

int list[MAX] = { 1,8,4,6,0,3,5,2,7,9 };

sort::sort()
{
}

sort::~sort()
{
}

void sort::bubbleSort()
{
	int temp;

	bool swapped = false;
	for (int i = 0; i < MAX - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < MAX - 1; j++)
		{
			cout << "Items compared: [ " << list[j] << ", " << list[j + 1] << "] ";

			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;

				swapped = true;
				cout << " => swapped [" << list[j] << ", " << list[j + 1] << "] " << endl;
			}
			else
			{
				cout << " => not swapped" << endl;
			}
		}
		if (!swapped)
		{
			break;
		}
		cout << "Iteration " << i + 1 << ": ";
	}
}

void sort::insertionSort()
{
	// loop through all numbers
	for (int i = 1; i < MAX; i++)
	{
		// select a value to be inserted.
		int valueToInsert = list[i];
		// select the hole position where number is to be inserted
		int holePosition = i;
		// check if previous no. is larger than value to be inserted
		while (holePosition > 0 && list[holePosition - 1] > valueToInsert)
		{
			list[holePosition] = list[holePosition - 1];
			holePosition--;
			cout << " item moved : " << list[holePosition] << endl;
		}

		if (holePosition != i)
		{
			cout << " item inserted : " << valueToInsert << ", at position : " << holePosition << endl;
			list[holePosition] = valueToInsert;
		}
	}
}

void sort::selectionSort()
{
	// loop through all numbers
	for (int i = 0; i < MAX - 1; i++)
	{
		// set current element as minimum
		int indexMin = i;
		// check the element to be minimum
		for (int j = i + 1; j < MAX; i++)
		{
			if (list[j] < list[indexMin])
			{
				indexMin = j;
			}
		}
		if (indexMin != i)
		{
			cout << "Items swapped: [ " << list[i] << ", " << list[indexMin] << " ]" << endl;
			// swap the numbers 
			int temp = list[indexMin];
			list[indexMin] = list[i];
			list[i] = temp;
		}
	}
}

void merging(int unsorted[], int first, int mid, int last, int sorted[])
{
	int i = first;
	int j = mid;
	int k = 0;
	while (i < mid && j < last)
	{
		if (unsorted[i] < unsorted[j])
		{
			sorted[k++] = unsorted[i++];
		}
		else
		{
			sorted[k++] = unsorted[j++];
		}
	}
	while (i < mid)
	{
		sorted[k++] = unsorted[i++];
	}
	while (j < last)
	{
		sorted[k++] = unsorted[j++];
	}
	for (int v = 0; v < k; v++)
	{
		unsorted[first + v] = sorted[v];
	}
}

void sort::mergeSort(int unsorted[], int first, int last, int sorted[])
{
	if (first + 1 < last)
	{
		int mid = (first + last) / 2;
		cout << "{" << first << "}" << "{" << mid << "}" << "{" << last << "}" << endl;
		mergeSort(unsorted, first, mid, sorted);
		mergeSort(unsorted, mid, last, sorted);
		merging(unsorted, first, mid, last, sorted);
	}
	else
	{
		return;
	}
}

void sort::shellSort() {
	int interval = 1;
	int elements = MAX;
	int i = 0;

	while (interval <= elements / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (int outer = interval; outer < elements; outer++)
		{
			int valueToInsert = list[outer];
			int inner = outer;
			while (inner > interval - 1 && list[inner - interval] >= valueToInsert)
			{
				list[inner] = list[inner - interval];
				inner -= interval;
				cout << " item moved : " << list[inner] << endl;
			}

			list[inner] = valueToInsert;
			cout << " item inserted : " << valueToInsert << ", at position : " << inner << endl;
		}

		interval = (interval - 1) / 3;
		i++;
	}
}

// Next is quick sort
void swap(int num1, int num2)
{
	int temp = list[num1];
	list[num1] = list[num2];
	list[num1] = temp;
}

int partition(int left, int right, int pivot)
{
	int leftPointer = left - 1;
	int rightpointer = right;

	while (true)
	{
		while (list[++leftPointer] < pivot)
		{

		}

		while (rightpointer > 0 && list[--rightpointer] > pivot)
		{

		}

		if (leftPointer > rightpointer)
		{
			break;
		}
		else
		{
			cout << " item swapped :" << list[leftPointer] << "," << list[rightpointer] << endl;
			swap(leftPointer, rightpointer);
		}
	}

	cout << " pivot swapped :" << list[leftPointer] << "," << list[right] << endl;
	swap(leftPointer, right);
	return leftPointer;
}

void sort::quickSort(int left, int right)
{
	if (right <= left)
	{
		return;
	}
	else
	{
		int pivot = list[right];
		int partitionPoint = partition(left, right, pivot);
		quickSort(left, partitionPoint - 1);
		quickSort(partitionPoint + 1, right);
	}
}