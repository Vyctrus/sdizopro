#pragma once
#include <string>
using namespace std;
class BSTree
{
	struct nodeBST {
		int value;
		nodeBST* father;
		nodeBST* left;
		nodeBST* right;
	};
private:
	nodeBST * root;

public:
	BSTree();
	~BSTree();
	void printBT( std::string sp , std::string sn ,  nodeBST * v );
	
	void add(int addNumb);
	void algDSW();
	void rotLeft(nodeBST * currNode);
	void rotRight(nodeBST * currNode);
	bool search(int lookNumb);
	void remove(int remNumb);
	void preDelete(nodeBST * nodeX);
	
	void remAll();
	void display();
};

