#include "pch.h"
#include "DoubleConectedList.h"
#include <iostream>

DoubleConectedList::DoubleConectedList()
{
	back = NULL;
	front = NULL;
}


DoubleConectedList::~DoubleConectedList()
{
}

void DoubleConectedList::addHead(int addNumb)
{
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac

	if (size == 0) {
		front = currElm;
		back = currElm;
	}
	(*currElm).next = front; // dostawia sie przed pierwszym i wskazuje na niego
	(*currElm).previous = back; //jest rowniez za "koncowym" i wskazuje go jako poprzednika
	front->previous = currElm;
	back->next = currElm;

	front = currElm;
	++size;
}

void DoubleConectedList::addTail(int addNumb)
{
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac

	if (size == 0) {
		front = currElm;
		back = currElm;
	}
	(*currElm).next = front; // dostawia sie przed pierwszym i wskazuje na niego
	(*currElm).previous = back; //jest rowniez za "koncowym" i wskazuje go jako poprzednika
	front->previous = currElm;
	back->next = currElm;

	back = currElm;//jedyna roznica miedzy addTail a addHead
	++size;
}

void DoubleConectedList::addPos(int addNumb, int numbPos)
{
	if (size == 0 || numbPos==0) {
		addHead(addNumb);
		return;
	}
	if (numbPos == size) {
		addTail(addNumb);
		return;
	}
	if (numbPos > size) {
		std::cout << "Bledna pozycja";
		return;
	}
	listElement *currElm;
	currElm = new listElement;
	(*currElm).value = addNumb;		//element na ktorym bede pracowac

	listElement * iter = front;
	for (int i = 0; i < numbPos-1; i++) {
		iter = iter->next;
	}

	currElm->previous = iter;
	currElm->next = iter->next;
	iter->next->previous = currElm;
	iter->next = currElm;

	++size;
}

void DoubleConectedList::removeHead()
{
	if (size == 0) {
		return;
	}
	if (size == 1) {
		front = NULL;
		back = NULL;
		--size;
		return;
	}
	front->previous->next = front->next;	//previous->next to to samo tutaj co back->next
	front->next->previous = front->previous;
	front = front->next;
	--size;
}

void DoubleConectedList::removeTail()
{
	if (size == 0) {
		return;
	}
	if (size == 1) {
		front = NULL;
		back = NULL;
		--size;
		return;
	}

	back->previous->next = back->next;
	back->next->previous = back->previous;
	back = back->previous;
	--size;
}

void DoubleConectedList::removePos(int numbPos)
{
	if (size == 0 || numbPos>size) {
		return;
	}
	if (size == 1) {
		front = NULL;
		back = NULL;
		--size;
		return;
	}
	if (numbPos == 0) {
		removeHead();
		return;
	}
	if (numbPos == size-1) {
		removeTail();
		return;
	}
	listElement * iter = front;
	for (int i = 0; i < numbPos; i++) {
		iter = iter->next;
	}

	iter->previous->next = iter->next;
	iter->next->previous = iter->previous;
	//iter = iter->previous;
	--size;
}

void DoubleConectedList::append(int addNumb)
{
	addTail(addNumb);
}

bool DoubleConectedList::searchNumb(int numbWanted)
{
	listElement* iter = front;
	for (int i = 0; i < size; i++) {
		if (iter->value == numbWanted) {
			return true;
		}
		iter = iter->next;
	}
	return false;
}

int DoubleConectedList::getNumb(int numbPos)
{
	if (size == 0 || numbPos >= size) {
		std::cout << "odwolanie do blednego indeksu\n";
		return 0;
	}
	if (size == 1 ||numbPos==0) {
		return front->value;
	}

	listElement * iter = front;
	for (int i = 0; i < numbPos; i++) {
		iter = iter->next;
	}

	return iter->value;
}

void DoubleConectedList::display()
{
	listElement *iter = front;
	for (int i = 0; i < size; i++) {
		std::cout << iter->value << " ";
		iter = iter->next;
	}
	std::cout << std::endl;
}

void DoubleConectedList::displayN()// wyswietlanie od tylu
{
	listElement *iter = back;
	for (int i = 0; i < size; i++) {
		std::cout << iter->value << " ";
		iter = iter->previous;
	}
	std::cout << std::endl;
}

void DoubleConectedList::createRand(int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++) {
		addHead(rand());	//tutaj mozna dac rand() % maksymalna liczba
	}
}
