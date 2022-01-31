#include "List.h"

int main()
{
	List<int> list = List<int>();

	list.pushFront(12);
	list.pushBack(10);
	list.pushFront(4);
	list.pushFront(6);
	list.print();
}