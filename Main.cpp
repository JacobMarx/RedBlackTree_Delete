/*
	Created by Jacob Marx, 4/21/19.
	This program creates a red black tree you can
	add and delete nodes to.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "Node.h"
#include "Tree.h"

bool getInput(Tree*, char*);
char* clear(char*);

void build();
void getInput(Tree*);
void enter(Tree* tree);
void help();

int main() {
	Tree* tree = new Tree();
	bool stop = false;
	
	//std::cout << "This is into deletion the delete is not implemented yet do not use 'delete'" << std::endl;
	
	while (stop == false) {
		//std::cout << "Would you like to input a file or through the console?" << std::endl;
		char* in = new char[20];
		clear(in);
		//std::cin >> in;
		if (tree->isempty() == true) { // If there is no tree then asks user if they want to make one
			std::cout << "You do not have a tree would you like to create one? (yes or no)" << std::endl;
			std::cin >> in;
			if (strcmp(in, "yes") == 0) {
				enter(tree);
				clear(in);
				//tree->display();
			}
		}
		else { // If tree is not empty t ask the user what commands they want to execute
			std::cout << "Would you like to 'add', 'read', 'print', 'search', or 'quit'?" << std::endl;
			std::cin >> in;
			if (strcmp(in, "add") == 0) { // Adds one number
				getInput(tree);
				clear(in);
				//tree->display();
			}
			/*
			else if (strcmp(in, "remove") == 0) {
				std::cout << "What number would you like to remove from the tree?" << std::endl;
				std::cin >> in;
				int input = 0;
				int index = 0;
				while (true) { // Gage did this
					char current = in[index++];
					if (current == '\0') {
						break;
					} else if (current == ',') {
						tree->push(input);
						input = 0;
						continue;
					}
					int digit = current - '0';
					input = input * 10 + digit;
				}
				tree->remove(input);
				clear(in);
			}
			*/
			else if (strcmp(in, "read") == 0) { // Read in file
				clear(in);
				std::cout << "What is the name of the file?" << std::endl;
				std::cin >> in;
				getInput(tree, in);
			}
			else if (strcmp(in, "print") == 0) { // Print tree
				tree->display(); 
				clear(in);
			}
			else if (strcmp(in, "quit") == 0) { //Stops program
				stop = true;
				// Need to delete tree
				break;
			}
			else if (strcmp(in, "remove")  == 0) {
				int data;
				std::cout << "What value would you like to remove (3 digits max)" << std::endl;
				std::cin >> data;
				tree->remove(data);
			}
			else if (strcmp(in, "search") == 0) { // Runs search
				std::cout << "What number are you searching for?" << std::endl;
				int search = 0;
				std::cin >> search;
				if (tree->search(tree->getRoot(), search) == NULL) {
					std::cout << search << " is not in this tree." << std::endl;
				}
				else {
					std::cout << search << " is in the tree!" << std::endl;
				}
				
			}
			else { // If they don't enter valid input it asks the user if they want help
				std::cout << "You did not enter a valid input. If you would like help enter 'help'." 
				<< std::endl;
				std::cin >> in;
				if (strcmp(in, "help") == 0) {
					help();
				}
				else {
					continue;
				}
			}
		}
		
	}
	
	/*
	tree->push(12);
	tree->push(6);
	tree->push(3);
	tree->push(9);
	tree->push(16);
	tree->push(1);
	tree->push(45);
	tree->push(23);
	tree->push(34);
	tree->push(19);
	tree->push(4);
	tree->push(21);
	tree->push(25);
	tree->push(15);
	*/
	
	//tree->display();
	return 0;
}

void enter(Tree* tree) { // Ask the user if they want to input values via add or read function
	char* in = new char[20];
	clear(in);
	std::cout << "Would you like to 'add' one number, or 'read' in from a file" << std::endl;
	std::cin >> in;
	if (strcmp(in, "add") == 0) { // Allows user to add one number
		getInput(tree);
	}
	else if (strcmp(in, "read") == 0) { // Allows user to input through file
		clear(in);
		std::cout << "What is the name of the file?" << std::endl;
		std::cin >> in;
		getInput(tree, in);
	}
}

void help() { // Help function that list all commands
	std::cout << "********************HELP********************" << std::endl 
	<< std::endl << "COMMANDS:" << std::endl 
	<< "\t" << "'add' = Allows you to add to the tree." << std::endl 
	<< "\t" << "'read' = Insert numbers from a file into the tree." << std::endl 
	<< "\t" << "'print' = Visually print the tree." << std::endl 
	<< "\t" << "'quit' = Stops the program." << std::endl << std::endl
	<< "\t" << "'search' = Search for a number in the tree." << std::endl << std::endl
	<< "\t" << "'remove' = Removes specified number form the tree." << std::endl << std::endl
	<< "********************************************" << std::endl;
}

bool getInput(Tree* tree, char* fileName) { // Input function with file
	std::ifstream file;
	//std::cout << "goon" << std::endl;
	file.open(fileName);
	if (file.is_open()) {
		//char* in = new char[1000];
		char* in = new char[4000];
		int input = 0;
		int index = 0;
		//std::cout << file.get() << std::endl;
		//file.unget();
		file >> in;
		while (true) { // Gage did this
			char current = in[index++];
			if (current == '\0') {
				break;
			} 
			else if (current == ',') {
				tree->push(input);
				//std::cout << "Input: " << input << std::endl;
				input = 0;
				continue;
			}
			int digit = current - '0';
			input = input * 10 + digit;
		}
		//std::cout << "Input: " << input << std::endl;
		if (input <= 1000 && input >= 1) {
			tree->push(input);
		}
		return true;
	}
	return false;
}

void getInput(Tree* tree) { // Inptu function for one number
	while (true) {
		int input = 0;
		//std::cout << "ghflkfjlj\n";
		std::cout << "What value do you want to add?" << std::endl;
		std::cin >> input;
		if (input <= 1000 && input >= 1) {
			//std::cout << input << std::endl;
			tree->push(input);
			//std::cout << "goon\n";
		}
		else if (input == 1001) {
			for (int i = 499; i > 0; i--) {
				int add = rand() % 999;
				if (tree->search(tree->getRoot(), add) != NULL) {
					i++;
				}
				else {
					tree->push(add);
				}
			}
			break;
		}
		//std::cin.unget();
		//std::cout << "Whitespace: " << int(std::cin.get()) << std::endl;
		//std::cin.unget();
		if (std::cin.get() == '\n' || std::cin.get() == ' ') {
			//std::cout << "hi\n";
			break;
		}
	}
	//std::cout << "Left function" << std::endl;
}

char* clear(char* arr) { // Set array passed through to all NULLs
	for (int i = 0; i <= 20; i++) {
		arr[i] = '\0';
	}
}

void build() { // Build function used for early debugging
	Tree* tree = new Tree();
	
	/* LL
	std::cout << "****************************" << std::endl;
	tree->push(4);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(2);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(6);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(3);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(1);
	tree->display();
	*/
	
	/*
	std::cout << "****************************" << std::endl;
	tree->push(23);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(54);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(12);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(34);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(27);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(11);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(7);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(47);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(39);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(20);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(59);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(15);
	tree->display();
	*/
	
	/*
	std::cout << "****************************" << std::endl;
	tree->push(4);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(2);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(6);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(1);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(3);
	tree->display();
	*/
	
}