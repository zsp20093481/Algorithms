#include <iostream>
using namespace std;

void merge(int unsorted[],int first,int mid,int last,int sorted[])
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

void merge_sort(int unsorted[], int first, int last, int sorted[])
{
	if (first + 1 < last)
	{
		int mid = (first + last) / 2;
		cout << "{" << first << "}" << "{" << mid << "}" << "{" << last << "}" << endl;
		merge_sort(unsorted, first, mid, sorted);
		merge_sort(unsorted, mid, last, sorted);
		merge(unsorted, first, mid, last, sorted);
	}
}

int main() {
	printf("This is test.\n");
	int x[] = { 6,2,4,1,5,9 };
	int sorted[6];
	merge_sort(x, 0, 6, sorted);
	for (int i = 0; i < 6; i++)
	{
		if (x[i] > 0)
		{
			cout << x[i] << endl;
		}
	}
	//getchar();
	system("pause");
}