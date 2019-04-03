#pragma once
#include <iostream>
#include <string>
using namespace std;

class DoubleConectedList
{
	struct listElement {
		int value;
		listElement *next;
		listElement *previous;
	};

private:
	listElement *front;
	listElement * back;
	int size=0;

public:
	DoubleConectedList();
	~DoubleConectedList();
	void addHead(int addNumb);	//dodaj na poczatku		
	void addTail(int addNumb);	//dodaj na koncu	//chyba ok	
	void addPos(int addNumb, int numbPos);	//dodanie na wybranej pozycji	
	void removeHead();	//usun na poczatku	//ok
	void removeTail();	//usun na koncu		//ok
	void removePos(int numbPos);	//usun z pozycji
	void removeValue(int numbValue);	//usun wartosc
	void append(int addNumb);

	bool searchNumb(int numbWanted);//wyszukanie elementu //Bool zawiera, nie zawiera, nie zwraca adressu gdzie, nie zwraca ilosci: ile?
	int getNumb(int numbPos);	//pozyskanie elementu z pozycji

	void display();	//wyswietl na ekran	
	void displayN();
	static void loadFromFile(string fileName, DoubleConectedList * loadedArray);
	void createRand(int sizeOfArray);	//utworzenie randomowo wygenerowanej talbicy

	void removeList();
};

