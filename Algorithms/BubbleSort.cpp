#include <iostream>
using namespace std;

const int MAX = 10;
int list[MAX] = { 1,8,4,6,0,3,5,2,7,9 };

void display1() {
	printf("[");

	// navigate through all items 
	for (int i = 0; i < MAX; i++) {
		printf("%d ", list[i]);
	}

	printf("]\n");
}

void bubbleSort()
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
		display1();
	}
}

//void main() {
//	printf("Input Array: ");
//	display1();
//	printf("\n");
//
//	bubbleSort();
//	printf("\nOutput Array: ");
//	display1();
//	getchar();
//}