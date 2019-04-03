#pragma once
#include <string>
using namespace std;

class BinHeap
{
private:
	int* myArray;
	int size;
	int currSize;
	int const sizeInc = 5;
public:
	BinHeap();
	~BinHeap();
	void push(int addNumb);//wstawienie elementu do kopca
	int pop(); //usuwanie elementu ze szczytu kopca
	//**usuwanie konkretnej wartosci z kopca
		//**szukanie danej wartosc w kopcu
	void removeValue(int currNumber);
	bool searchNumb(int lookNumb);
	void sortAdd(int tabIndex);
	void sortRem(int tabIndex);

	void printBT(string sp, string sn, int v);
	void display2();
	void display();
	void expandArray();
	void reduceArray();

	void createRand(int sizeOfArray);
	void append(int addNumb);
	static void loadFromFile(string fileName, BinHeap * loadedArray);

};

