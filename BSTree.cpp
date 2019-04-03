#include "pch.h"
#include "BSTree.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include<cmath>

using namespace std;


BSTree::BSTree()
{
	root = NULL;
}


BSTree::~BSTree()
{
}

void BSTree::printBT(std::string sp, std::string sn, nodeBST * v)
{
	string s;
	string cr,cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	if (v) {
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, v->right);

		s = s.substr(0, sp.length() - 2);
		cout <<s << sn << v->value << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, v->left);
	}
}

void BSTree::add(int addNumb)
{
	nodeBST * currNode = new nodeBST();
	currNode->value = addNumb;
	currNode->left = NULL;
	currNode->right = NULL;
	currNode->father = NULL;

	if (root == NULL) {
		root = currNode;
		return;
	}
	nodeBST * tempRoot = root;
	while (true) {
		if (currNode->value < tempRoot->value) {
			if (tempRoot->left == NULL) {
				tempRoot->left = currNode;
				currNode->father = tempRoot;
				break;
			}
			else {
				tempRoot = tempRoot->left;//"idziemy w dol drzewa"
			}
		}

		else {//currNode.value >=tempRoot.value
			if (tempRoot->right == NULL) {
				tempRoot->right = currNode;
				currNode->father = tempRoot;
				break;
			}
			else {
				tempRoot = tempRoot->right;
			}
		}
	}


}

void BSTree::algDSW()
{
	unsigned n, s;
	nodeBST * currNode;
	n = 0;                          // W n zliczamy wêz³y
	currNode = root;                       // Rozpoczynamy tworzenie listy liniowej
	while (currNode)                        // Dopóki jesteœmy w drzewie
		if (currNode->left)                   // Jeœli przetwarzany wêze³ ma lewego syna,
		{
			rotRight(currNode);             // to obracamy wokó³ niego drzewo w prawo
			currNode = currNode->father;
		}
		else
		{
			n++;                        // Inaczej zwiêkszamy licznik wêz³ów
			currNode = currNode->right;               // i przesuwamy siê do prawego syna
		}
	// Teraz z listy tworzymy drzewo BST
	s = n + 1 - log2(n + 1);        // Wyznaczamy pocz¹tkow¹ liczbê obrotów

	currNode = root;                       // Rozpoczynamy od pocz¹tku drzewa
	for (int i = 0; i < s; i++)          // Zadan¹ liczbê razy
	{
		rotLeft(currNode);                // co drugi wêze³ obracamy w lewo
		currNode = currNode->father->right;
	}

	n = n - s;                      // Wyznaczamy kolejne liczby obrotów

	while (n > 1)                    // Powtarzamy procedurê obrotów wêz³ów
	{
		n >>= 1;                      // Jednak¿e wyznaczaj¹c za ka¿dym razem
		currNode = root;                     // odpowiednio mniejsz¹ liczbê obrotów, która
		for (int i = 0; i < n; i++)        // maleje z potêgami 2.
		{
			rotLeft(currNode);
			currNode = currNode->father->right;
		}
	}
}

void BSTree::rotLeft(nodeBST * currNode)
{
	if (currNode == NULL) {
		return;
	}
	nodeBST * rightNode = currNode->right;
	nodeBST* fatherNode = currNode->father;
	if (rightNode != NULL) {
		currNode->right = rightNode->left;// ustawia doln¹ "mala"czesc
		if (currNode->right != NULL) {
			rightNode->left->father = currNode;
		}

		rightNode->left = currNode;	//ustawia srodkowa czesc
		currNode->father = rightNode;

		rightNode->father = fatherNode;//ustawia najwyzsza czesc
		if (fatherNode != NULL) {
			if (fatherNode->left == currNode) {//sprawdza ktorym potomkiem byl currNode
				fatherNode->left = rightNode;//dolaczenie do gornej czesci drzewa
			}
			else {//currNode is fatherNode.right
				fatherNode->right = rightNode;
			}
		}
		else {
			root = rightNode;
		}
	}
}

void BSTree::rotRight(nodeBST * currNode)
{
	if (currNode == NULL) {
		return;
	}
	//nodeBST * rightNode = currNode->right;
	nodeBST* fatherNode = currNode->father;
	nodeBST* leftNode = currNode->left;
	if (leftNode != NULL) {
		currNode->left = leftNode->right;// ustawia doln¹ "mala"czesc
		if (currNode->left != NULL) {
			leftNode->right->father = currNode;
		}

		leftNode->right = currNode;	//ustawia srodkowa czesc
		currNode->father = leftNode;

		leftNode->father = fatherNode;//ustawia najwyzsza czesc
		if (fatherNode != NULL) {
			if (fatherNode->left == currNode) {//sprawdza ktorym potomkiem byl currNode
				fatherNode->left = leftNode;
			}
			else {//currNode is fatherNode.right
				fatherNode->right = leftNode;
			}
		}
		else {
			root = leftNode;
		}

	}
	
}

void BSTree::preDelete(nodeBST * nodeX)
{
	if (nodeX != NULL) {
		preDelete(nodeX->left);
		preDelete(nodeX->right);
		delete nodeX;
	}
}


void BSTree::remAll()
{
	preDelete(root);
}

void BSTree::display()
{
	printBT("", "", root);
}









