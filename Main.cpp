#include "List.h"
#include <iostream>

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
	list.print();
	system("pause");
	list.sort();

	std::cout << std::endl;

	list.print();
	system("pause");
	std::cout << std::endl;

	list.destroy();
	list.destroy();
	list.insert(24, 0);
	list.insert(55, 1);
	list.print();
	system("pause");
	std::cout << std::endl;

	List<int> list2;
	list2 = list;

	list2.print();
	system("pause");
	list.destroy();
	list2.destroy();

	list.insert(10, -1);
	list2.insert(12, -1);

	list.print();
	list2.print();
	system("pause");
}