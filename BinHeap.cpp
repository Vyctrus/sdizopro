#include "pch.h"
#include "BinHeap.h"
#include <iostream>
#include <fstream>


BinHeap::BinHeap()
{
	size = 0;
	currSize = 0;
}


BinHeap::~BinHeap()
{
	delete[] myArray;
}

void BinHeap::push(int addNumb)
{
	if (size == 0 && currSize == 0) {
		myArray = new int[sizeInc];
		size = sizeInc;
		currSize = 1;
		myArray[0] = addNumb;
		return;
	}
	if (currSize == size) {
		expandArray();
	}

	myArray[currSize] = addNumb;
	sortAdd(currSize);
	++currSize;
	return;


}

int BinHeap::pop()
{
	
	if (size == 0 ||currSize==0) {	
		return 99999;
	}
	int temp = myArray[0];
	myArray[0] = myArray[currSize-1];		//przypisujemy najmlodszy lisc do korzenia
	--currSize;
	sortRem(0);		//bo zaczynamy sortowac od korzenia do lisci
	if (currSize < (size - sizeInc)) {
		reduceArray();
	}

	return temp;
}

void BinHeap::removeValue(int lookNumb)
{
	for (int i = 0; i < currSize; i++) {
		if (myArray[i] == lookNumb) {
			--currSize;
			myArray[i] = myArray[currSize];
			sortRem(i);
			if (currSize < (size - sizeInc)) {
				reduceArray();
			}
			return;
		}
	}
	return;
}

bool BinHeap::searchNumb(int lookNumb)
{
	for (int i = 0; i < currSize; i++) {
		if (myArray[i] == lookNumb) {
			//std::cout <<lookNumb<< " -Liczba jest w strukturze\n";
			return true;
		}
	}
	//std::cout<<lookNumb << " -Tej liczby nie ma w strukturze\n";
	return false;
}



void BinHeap::sortAdd(int tabIndex)	//currSize as first param
{
	if (myArray[tabIndex] > myArray[(tabIndex-1) / 2]) {
		int temp = myArray[(tabIndex-1) / 2];
		myArray[(tabIndex-1) / 2] = myArray[tabIndex];
		myArray[tabIndex] = temp;
		if ((tabIndex-1) / 2 == 0) {
			return;
		}
		sortAdd((tabIndex-1) / 2);
	}
}

void BinHeap::sortRem(int tabIndex)
{
	if ((tabIndex * 2) + 1 >= currSize) {
		return;		//to gwarantuje ze marr[tabindex*2)+1] istnieje
	}
	if (myArray[(tabIndex*2)+1] > myArray[tabIndex]) {
		int temp = myArray[tabIndex];
		myArray[tabIndex] = myArray[(tabIndex * 2) + 1];
		myArray[(tabIndex * 2) + 1] = temp;
		
		sortRem((tabIndex * 2) + 1);
	}
}

void BinHeap::printBT(string sp, string sn, int v)
{
	string cr, cl, cp;      // ³añcuchy do znaków ramek
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	string s;
	if (v < currSize)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, 2 * v + 2);
		s = s.substr(0, sp.length() - 2);
		cout << s << sn << myArray[v] << endl;
		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, 2 * v + 1);
	}
}

void BinHeap::display()
{
	printBT("", "", 0);
}

	void BinHeap::display2()
	{
		for (int i = 0; i < currSize; i++) {
			std::cout << myArray[i] << " ";
		}
		std::cout << std::endl;
	}

	void BinHeap::expandArray()
{
	//std::cout << "rozszerzam tablice\n";
	size += sizeInc;
	int *tempArray = new int[size]; //nowa, wieksza tablica
	for (int i = 0; i < currSize; i++) {
		tempArray[i] = myArray[i];	
	}
	delete[] myArray;
	myArray = tempArray;
	return;
}

void BinHeap::reduceArray()
{
	//std::cout << "pomniejszam tablice\n";
	size -= sizeInc;
	int *tempArray = new int[size]; //nowa, mniejsza tablica
	for (int i = 0; i < currSize; i++) {
		tempArray[i] = myArray[i];
	}
	delete[] myArray;
	myArray = tempArray;
	return;
}

void BinHeap::createRand(int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++) {
		push(rand());	//tutaj mozna dac rand() % maksymalna liczba
	}
}

void BinHeap::append(int addNumb)
{
	push(addNumb);
}

void BinHeap::loadFromFile(string fileName, BinHeap * loadedHeap)
{
	std::fstream file;
	std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {
		getline(file, dataRow);
		std::cout << "Poprawny odczyt z pliku\n";
		int numberOfData = std::stoi(dataRow);
		for (int i = 0; i < numberOfData; i++) {
			getline(file, dataRow);
			loadedHeap->append(std::stoi(dataRow));
		}
		file.close();
		return;//std::fstream &file
	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	return;
}
