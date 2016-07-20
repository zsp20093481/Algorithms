#include <iostream>
#include <cstdbool>
using namespace std;

const int MAX = 6;
int intArray1[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek()
{
	return intArray1[front];
}

bool isEmpty()
{
	return itemCount == 0;
}

bool isFull()
{
	return itemCount == MAX;
}

int size()
{
	return itemCount;
}

void insertData(int data)
{
	if (!isFull()) {
		if (rear == MAX - 1)
		{
			rear = -1;
		}
		intArray1[++rear] = data;
		itemCount++;
	}
}

int removeData()
{
	int data = intArray1[front++];
	if (front == MAX)
	{
		front = 0;
	}
	itemCount--;
	return data;
}