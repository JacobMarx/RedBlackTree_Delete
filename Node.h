/*
	Created by Jacob Marx, 4/21/19.
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
	Node(int data = 0, int color = 0) {
		this->data = data;
		this->color = color;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	int color;
	int data;
	Node* left;
	Node* right;
	Node* parent;
};
	
#endif