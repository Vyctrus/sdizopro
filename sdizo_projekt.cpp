
#include "pch.h"
#include "Array.h"
#include "TwoDirList.h"
#include "DoubleConectedList.h"
#include <iostream>
#include <fstream>
#include <string>

int loadFromFile(std::fstream &file, Array *testStorage) {	
	std::string fileName;
	std::cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane: ";
	std::cin >> fileName;
	std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {
		getline(file, dataRow);
		std::cout << "Poprawny odczyt z pliku\n";
		int numberOfData = std::stoi(dataRow);
		for (int i = 0; i < numberOfData; i++) {
			getline(file, dataRow);
			(*testStorage).append(std::stoi(dataRow));
		}
		file.close();
		return std::stoi(dataRow);
	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	return 0;
}

int main()
{
	std::cout << "Hello World!\n";
	DoubleConectedList testList;
	testList.addPos(13803, 0);
	testList.display();
	testList.addTail(1);
	testList.display();
	testList.addTail(2);
	testList.removeTail();
	testList.display();
	testList.displayN();
	testList.addTail(3);	
	testList.display();
	testList.addTail(4);
	testList.addPos(6969,5);
	testList.display();
	testList.addTail(5);
	testList.display();
	testList.displayN();
	testList.addPos(13803, 0);
	testList.removePos(6);
	testList.display();
	if (testList.searchNumb(2))
		std::cout << "true";
	std::cout << testList.getNumb(4);
}
