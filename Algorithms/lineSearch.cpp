#include <iostream>
using namespace std;

const int MAX = 20;

int intArray[MAX] = { 1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66 };

void pringln(int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		cout << "=";
	}
	cout << "=" << endl;
}

int find(int data)
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

void display() 
{
	cout << "[";
	// navigate through all items 
	for (int i = 0; i < MAX; i++)
	{
		cout << intArray[i];
	}
	cout << "]" << endl;
}