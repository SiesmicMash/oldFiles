#include <iostream>
#include <cmath>
#include <time.h>
#include <random>

double randomeNumberGenerator();
double inventorySlots();
struct Inventory;
void mainMenu();
void input(Inventory &inventory);
void output(Inventory &inventory);
void game(Inventory &inventory);


int main() {
	mainMenu();
}

struct Inventory {
	std::string nameOfItem;
	double quantityOfTime;
};

double randomNumberGenerator() {
	return rand() % 10; 
}
void input(Inventory &inventory) {
	Inventory inventory;
	std::cout << "";
}


void mainMenu() {
	bool loop = true
	while (loop) {
		int userInput;
		std::cout << "Welcome to the inventory sorting game" << std::endl
			<< "1. Input new items" << std::endl
			<< "2. Output the current iventory" << std::endl
			<< "3. exit the program" << std::endl;
		std::cin >> userInput;
		switch (userInput) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			loop = false;
			break;
		default:
			std::cout << "Please input a proper number"<<std::endl;
		}
	}
}



