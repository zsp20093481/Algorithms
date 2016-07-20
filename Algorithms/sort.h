#include <iostream>
using namespace std;

const int MAX = 10;

class sort
{
public:
	sort();
	~sort();
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	void mergeSort(int unsorted[], int first, int last, int sorted[]);
	void shellSort();
	void quickSort(int left, int right);
};
