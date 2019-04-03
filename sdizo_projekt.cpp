
#include "pch.h"
#include "Array.h"
#include "TwoDirList.h"
#include "DoubleConectedList.h"
#include "BSTree.h"
#include "BinHeap.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include<ctime>
#include <chrono>

using namespace std;


void saveFileDiff() {
	std::fstream saveFile;
	string fileName;
	Array *myLittleArray = new Array();
	cout << "Podaj nazwe pliku do ktorego zapisze dane :";
	auto startX = std::chrono::high_resolution_clock::now();
	cin >> fileName;
	int sizeOfData;
	cout << "Podaj rozmiar danych :";
	cin >> sizeOfData;
	srand(time(NULL));
	saveFile.open(fileName, ios::out);
	if (saveFile.good() == true) {
		int checker = rand();
		saveFile << sizeOfData << endl;
		for (int i = 0; i < sizeOfData; i++) {
			while (myLittleArray->searchNumb(checker)) {
				checker = rand();
			}
			myLittleArray->append(checker);
			saveFile << checker << endl;
		}
		saveFile.close();
		delete myLittleArray;
		cout << "Plik zapisano pomyslnie\n";
		auto endX = std::chrono::high_resolution_clock::now();
		chrono::duration<double> diff = endX - startX;
		cout << diff.count();
		return;
	}
	cout << "Wystapil problem podczas zapisywania\n";
}
void saveFile() {
	std::fstream saveFile;
	string fileName;
	cout << "Podaj nazwe pliku do ktorego zapisze dane :";
	auto start = std::chrono::high_resolution_clock::now();
	cin >> fileName;
	int sizeOfData;
	cout << "Podaj rozmiar danych :";
	cin >> sizeOfData;
	srand(time(NULL));
	saveFile.open(fileName, ios::out);
	if (saveFile.good() == true) {
		saveFile << sizeOfData << endl;
		for (int i = 0; i < sizeOfData; i++) {
			saveFile << rand() << endl;	
		}
		saveFile.close();
		cout << "Plik zapisano pomyslnie\n";
		auto end = std::chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << diff.count();
		return;
	}
	cout << "Wystapil problem podczas zapisywania\n";
	
}

void toExcel() {
	//----------miniProgram---------------------//
	fstream wyniki;
	fstream wynikiCor;
	std::string  dataRow;
	wynikiCor.open("wynikiCor.txt", ios::out);
	wyniki.open("wyniki.txt", ios::in);
	if (wynikiCor.good() && wyniki.good()) {
		for (int i = 0; i < 100; i++) {
			getline(wyniki, dataRow);
			int n = dataRow.length();
			char *chArray = &dataRow[0];
			for (int k = 0; chArray[k] != '\0'; k++) {
				if (chArray[k] == 'e') {
					chArray[k] = 'E';
				}
				if (chArray[k] == '.') {
					chArray[k] = ',';
				}
			}
			string str(chArray);
			wynikiCor << str << std::endl;
		}
		wyniki.close();
		wynikiCor.close();
	}
	//------------------------------------------------
}


void structureMenu()
{
	cout << endl;
	cout << "1.Tablica" << endl;
	cout << "2.List Dwukierunkowa" << endl;
	cout << "3.Kopiec" << endl;
	cout << "4.Generuj plik(5.diff)" << endl;
	cout << "0.Zakoncz" << endl;
	cout << "Podaj opcje:";
}
void runMenu(menu mMenu) {
	char opt;
	do {
		structureMenu();
		opt = _getch();
		cout << endl;
		switch (opt) {
		case '1':
			mMenu.menu_table();
			break;
		case '2':
			mMenu.menu_list();
			break;
		case '3':
			mMenu.menu_heap();
			break;
		case '4':
			saveFile();
			break;
		case '5':
			saveFileDiff();
			break;
		case '6':
			toExcel();
		}
	} while (opt != '0');
}
int main()
{
	menu mainMenu;
	runMenu(mainMenu);

	

	//cout << "rozpoczynam symulacje"<<endl;
	//Array *testArray = new Array;
	//testArray->loadFromFile("testM.txt", testArray);
	//cout << "rdy\n";
	//int myRand = rand();
	//auto startTest = std::chrono::high_resolution_clock::now();
	////testArray->testFile("testMM.txt", testArray);
	//testArray->addHead(myRand);
	//auto endTest = std::chrono::high_resolution_clock::now();
	//chrono::duration<double> diff = endTest - startTest;
	//cout << "Czas wykonania addHead *100 : " << diff.count();
	//fstream wyniki;
	//wyniki.open("wyniki.txt", ios::out|ios::app);
	//if (wyniki.good() == true) {
	//	wyniki << diff.count() << endl;
	//	wyniki.close();
	//}
}
