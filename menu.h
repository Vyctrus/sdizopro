#pragma once

#include<conio.h>
#include<string>
#include<iostream>
#include "Array.h"
#include "DoubleConectedList.h"
#include "BinHeap.h"
using namespace std;

class menu
{
public:
	menu();
	~menu();

	Array *myTab = new Array();
	DoubleConectedList *myList= new DoubleConectedList();
	BinHeap *myHeap= new BinHeap();

	void displayMenu(string info);
	void menu_table();
	void menu_list();
	void menu_heap();
	void clearData();
};

