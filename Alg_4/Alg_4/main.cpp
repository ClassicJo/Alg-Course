#include <iostream>
#include "FordFulkerson.h"
using namespace std;

int main()
{
	FordFulkerson algorythm;
	algorythm.readList("graph.txt");
	int result = algorythm.MaxFlow();
	cout << "Max. network stream: ";
	cout << result;
}
