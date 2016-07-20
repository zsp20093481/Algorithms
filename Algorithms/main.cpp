#include <iostream>
#include "sort.h"
using namespace std;
int main() {
	printf("This is test.\n");
	
	sort * s = new sort();
	s->shellSort();
	getchar();
}
