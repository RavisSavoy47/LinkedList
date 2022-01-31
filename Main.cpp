#include "List.h"

int main()
{
	List<int> list = List<int>();

	list.pushBack(12);
	list.pushBack(10);
	list.pushFront(4);
	list.pushFront(6);
	list.insert(20, 1);
	list.pushFront(56);
	list.pushFront(46);

	list.remove(56);
	list.remove(1);
	list.remove(10);
	list.remove(12);
	list.remove(6);
	list.remove(4);
	list.remove(20);
	list.remove(46);
	list.remove(46);
	list.sort();
	list.print();
}