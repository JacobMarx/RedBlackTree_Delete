/*
	Created by Jacob Marx, 4/21/19.
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Node.h"

class Tree {
	
public:
	//Constructors
	Tree();
	~Tree();
	
	//Member Functions
	bool isempty() const;
	int pop();
	int getCase(Node*, Node*, Node*, Node*);
	Node* getRoot();
	Node* findSucc(Node*);
	Node* min(Node*);
	Node* search(Node*, int);
	
	void lLeft(Node*, Node*, Node*, Node*);
	void lRight(Node*, Node*, Node*, Node*);
	void rRight(Node*, Node*, Node*, Node*);
	void rLeft(Node*, Node*, Node*, Node*);
	void setFam(Node*);
	void display();
	void remove(int);
	void push(int);
	void reColor(Node*);

private:
	// Private Members
	Node* root;
	
	// Private Functions
	void push(Node*&, int);
	void print(Node*, int) const;
	
};

#endif