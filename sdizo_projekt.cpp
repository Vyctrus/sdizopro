// sdizo_projekt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Array.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	Array testArray;
	testArray.removeTail();
	testArray.display();
	testArray.addHead(4);
	testArray.addHead(78);
	testArray.addHead(456);
	testArray.addTail(13803);
	testArray.addHead(12);
	testArray.addTail(79);
	testArray.display();
	testArray.removeHead();
	testArray.display();
	testArray.removeHead();
	testArray.display();
	testArray.removeTail();
	testArray.display();
	testArray.addPos(13, 3);
	testArray.display();
	testArray.addPos(0,2);
	testArray.display();
	testArray.addPos(90, 1);
	testArray.display();
	testArray.addPos(90, 7);
	testArray.display();
	testArray.addPos(90, 5);
	testArray.display();
	std::cout << testArray.getNumb(5) << std::endl;
	testArray.removePos(0);
	testArray.display();
	int x = 0;
	std::cin >> x;
	if (testArray.searchNumb(x)) {
		std::cout << "TRUE\n";
	}
	else {
		std::cout << "FALSE\n";
	}
	testArray.display();
	Array randArray;
	randArray.createRand(30);
	randArray.display();
}
