#include <iostream>
using namespace std;

const int SIZE = 20;

struct  DataItem
{
	int data;
	int key;
};

struct DataItem * hashArray[SIZE];
struct DataItem * dummyItem;
struct DataItem * item;

int hashCode(int key)
{
	return key%SIZE;
}

struct DataItem * search(int key)
{
	// get the hash
	int hashIndex = hashCode(key);

	// move in array until an empty
	while (hashArray[hashIndex] != NULL)
	{
		if (hashArray[hashIndex]->key == key)
		{
			return hashArray[hashIndex];
		}
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;
}

void insert(int key, int data)
{
	struct DataItem * item = (struct DataItem *)malloc(sizeof(struct DataItem));
	item->data = data;
	item->key = key;

	// get the hash
	int hashIndex = hashCode(key);

	//move in array until an empty or deleted cell
	while (hashArray[hashIndex] != NULL&&hashArray[hashIndex]->key != -1)
	{
		++hashIndex;
		hashIndex %= SIZE;
	}
	hashArray[hashIndex] = item;
}

struct DataItem * deleteItem(struct DataItem * item)
{
	int key = item->key;
	// get the hash
	int hashIndex = hashCode(key);

	// move in array until an empty
	while (hashArray[hashIndex] != NULL)
	{
		if (hashArray[hashIndex]->key == key)
		{
			struct DataItem * temp = hashArray[hashIndex];
			//assign a dummy item at deleted position
			hashArray[hashIndex] = dummyItem;
			return temp;
		}
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;
}