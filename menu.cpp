#include "pch.h"
#include "menu.h"
#include <chrono>

menu::menu()
{
}


menu::~menu()
{
}

void menu::displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu::menu_table()
{
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- TABLICA ---");
		opt = _getch();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			//delete myTab;
			//myTab = new Array();
			clearData();
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			myTab->loadFromFile(fileName , myTab);
			myTab->display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj index:";
			cin >> index;
			//myTab.deleteFromTable(index);
			myTab->removePos(index);
			myTab->display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << "podaj wartosc:";
			cin >> value;
			myTab->addPos(value, index);
			myTab->display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << "podaj wartosc:";
			cin >> value;
			if (myTab->searchNumb(value))		//myTab.IsValueInTable(value)
				cout << "podana wartosc jest w tablicy";
			else
				cout << "podanej wartosci nie ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			clearData();
			cout << "Podaj ilosc elementow tablicy:";
			cin >> value;
			//myTab.generateTable(value);
			myTab->createRand(value);
			myTab->display();
			break;

		case '6':  //tutaj wy?wietlanie tablicy
			myTab->display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie b?dzie testowana przez prowadz?cego 
			cout << "rozpoczynam symulacje" << endl;
			cout << "podaj rozmiar problemu:" << endl;
			int sizeOfProblem;
			cin >> sizeOfProblem;
			for (int i = 0; i < 100; i++) {
				myTab->createRand(sizeOfProblem);
				int myRand = rand();
				auto startTest = std::chrono::high_resolution_clock::now();
				myTab->addHead(myRand);
				auto endTest = std::chrono::high_resolution_clock::now();
				chrono::duration<double> diff = endTest - startTest;
				//cout << "Czas wykonania addHead : " << diff.count();
				fstream wyniki;
				wyniki.open("wyniki.txt", ios::out | ios::app);
				if (wyniki.good() == true) {
					wyniki << diff.count() << endl;
					wyniki.close();
				}
				clearData();
			}
			//myTab->createRand(value);	
			break;
		}

	} while (opt != '0');
	clearData();
}

void menu::menu_list()
{
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- LISTA DWUKIERUNKOWA ---");
		opt = _getch();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  listy z pliku
			//delete myList;
			//myList = new DoubleConectedList;
			clearData();
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			myList->loadFromFile(fileName, myList);
			myList->display();
			break;

		case '2': //tutaj usuwanie wybranej wartosci z listy
			cout << " podaj wartosc:";
			cin >> index;
			//myTab.deleteFromTable(index);
			myList->removeValue(index);
			myList->display();
			break;

		case '3': //tutaj dodawanie elemetu do listy
			cout << " podaj index:";
			cin >> index;
			cout << "podaj wartosc:";
			cin >> value;
			myList->addPos(value, index);
			myList->display();
			break;

		case '4': //tutaj znajdowanie elemetu w liscie
			cout << "podaj wartosc:";
			cin >> value;
			if (myList->searchNumb(value))		//myTab.IsValueInTable(value)
				cout << "podana wartosc jest w liscie";
			else
				cout << "podanej wartosci nie ma w liscie";
			break;

		case '5':  //tutaj generowanie  listy
			cout << "Podaj ilosc elementow lisy:";
			cin >> value;
			//myTab.generateTable(value);
			myList->createRand(value);
			myList->display();
			break;

		case '6':  //tutaj wy?wietlanie tablicy
			myList->display();
			break;

			//case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie b?dzie testowana przez prowadz?cego 
			//		  // mo¿na sobie tu doda? w?asne case'y
			//	break;
		}

	} while (opt != '0');
	clearData();
}

void menu::menu_heap()
{
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- KOPIEC ---");
		opt = _getch();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  kopca z pliku
			//delete myHeap;
			//myHeap = new BinHeap();
			clearData();
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			myHeap->loadFromFile(fileName, myHeap);

			myHeap->display();
			break;

		case '2': //tutaj usuwanie wybranej wartosci z kopca
			cout << " podaj wartosc:";
			cin >> index;
			//myTab.deleteFromTable(index);
			myHeap->removeValue(index);
			myHeap->display();
			break;

		case '3': //tutaj dodawanie elemetu do listy
			cout << " podaj index:";
			cin >> index;
			cout << "podaj wartosc:";
			cin >> value;
			myList->addPos(value, index);
			myList->display();
			break;

		case '4': //tutaj znajdowanie elemetu w kopcu
			cout << "podaj wartosc:";
			cin >> value;
			if (myHeap->searchNumb(value))		//myTab.IsValueInTable(value)
				cout << "podana wartosc jest w kopcu";
			else
				cout << "podanej wartosci nie ma w kopcu";
			break;

		case '5':  //tutaj generowanie  kopca
			cout << "Podaj ilosc elementow kopca:";
			cin >> value;
			//myTab.generateTable(value);
			myHeap->createRand(value);
			myHeap->display();
			break;

		case '6':  //tutaj wy?wietlanie tablicy
			myHeap->display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie b?dzie testowana przez prowadz?cego 
			break;
		}

	} while (opt != '0');
	clearData();
}

void menu::clearData()
{
	delete myTab;
	myTab = new Array();
	delete myList;
	myList = new DoubleConectedList;
	delete myHeap;
	myHeap = new BinHeap();
}
