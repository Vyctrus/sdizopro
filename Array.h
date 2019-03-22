#pragma once
class Array
{
private:
	int* myArray;
	int size;
public:
	Array();
	~Array();
	void addHead(int addNumb);	//dodaj na poczatku //OK
	void addTail(int addNumb);	//dodaj na koncu //OK
	void addPos(int addNumb, int numbPos);	//dodanie na wybranej pozycji	//OK
	void removeHead();	//usun na poczatku //OK
	void removeTail();	//usun na koncu //OK
	void removePos(int numbPos);	//usun z pozycji	//OK

	bool searchNumb(int numbWanted);//wyszukanie elementu //Bool zawiera, nie zawiera, nie zwraca adressu gdzie, nie zwraca ilosci: ile?
	int getNumb(int numbPos);	//pozyskanie elementu z pozycji	//chyba OK

	void display();	//wyswietl na ekran	//OK

	void createRand(int sizeOfArray);	//utworzenie randomowo wygenerowanej talbicy

};

