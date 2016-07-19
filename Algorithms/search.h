#include <iostream>
using namespace std;
const int MAX = 20;

class search
{	
public:
	search();
	~search();
	int lineSearch(int count);
	int interpolationSearch(int data);
	int binarySearch(int count);
};