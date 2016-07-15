#include <iostream>
using namespace std;

const int MAX = 20;

int intArray[MAX] = { 1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66 };

void println(int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		cout << "=";
	}
	cout << "=" << endl;
}

int find(int data)
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

void main() {
	cout << "Input Array: ";
	display();
	println(50);

	//find location of 1
	int location = find(55);

	// if element was found 
	if (location != -1)
	{
		cout << endl << "Element found at location: " << location + 1;
	}
	else
	{
		cout << endl << "Element not found.";
	}
	getchar();
}