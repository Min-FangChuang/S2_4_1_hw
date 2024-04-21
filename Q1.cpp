/*Programming: Min-Fang Chuang   Date: 2024/04/01
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *Define a class "Pizza" to creat various pizza object
 */
#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX_PIZZA 18   //the number of pizza

//define Pizza
class Pizza {
	public:
		void outputDescription();   //display the description of the Pizza
		double computePrice();   //return the price of the Pizza
		void setType(int);
		int getType();
		void setSize(int);
		int getSize();
		void setTopping(int);
		int getTopping();
	private:
		int type;   //deep dish, hand tossed, or pan
		int size;   //small, medium, or large
		int topping;  //one or two toppings
};

int main() {
	Pizza user[MAX_PIZZA];

	//create objects
	for (int i = 0;i < 18;i++) {
		//set the different value
		user[i].setType(i / 6 + 1);
		user[i].setSize((i % 6) / 2 + 1);
		user[i].setTopping(i % 2 + 1);

		//display the description and price
		user[i].outputDescription();
		cout << "\nPicee :" << user[i].computePrice() << endl;
		cout << "-----------------------------------------\n\n";

	}

	system("pause");
	return (0);
}

void Pizza::outputDescription() {
	cout << "Type: ";
	switch (type) {
	case 1:
		cout << "deep dish" << endl;
		break;
	case 2:
		cout << "hand tossed" << endl;
		break;
	case 3:
		cout << "pan" << endl;
		break;
	default:
		cout << "< Error >" << endl;
	}

	cout << "Size: ";
	switch (size) {
	case 1:
		cout << "small" << endl;
		break;
	case 2:
		cout << "medium" << endl;
		break;
	case 3:
		cout << "large" << endl;
		break;
	default:
		cout << "< Error >" << endl;
	}

	cout << "Number of topping: ";
	switch (topping) {
	case 1:
		cout << "One topping (choose pepperoni or cheese)" << endl;
		break;
	case 2:
		cout << "Two topping (pepperoni or cheese)" << endl;
		break;
	default:
		cout << "< Error >" << endl;
	}
}

//compute the price by the formula
double Pizza::computePrice() {
	double price = 0;
	switch (size) {
	case 1:
		price += 10;
		break;
	case 2:
		price += 14;
		break;
	case 3:
		price += 17;
		break;
	default:
		cout << "Error: the size isn't in rule" << endl;
	}
	price += topping * 2;
	return price;
}


void Pizza::setType(int num) {
	//check the value is in the range
	if (num > 0 && num < 4) {
		type = num;
	}
	else {
		cout << "Error: The value of 'type' is out of the range" << endl;
	}
}
int Pizza::getType() {
	return type;
}
void Pizza::setSize(int num) {
	//check the value is in the range
	if (num > 0 && num < 4) {
		size = num;
	}
	else {
		cout << "Error: The value of 'size' is out of the range" << endl;
	}
}
int Pizza::getSize() {
	return size;
}
void Pizza::setTopping(int num) {
	//check the value is in the range
	if (num > 0 && num < 3) {
		topping = num;
	}
	else {
		cout << "Error: The value of 'topping' is out of the range" << endl;
	}
}
int Pizza::getTopping() {
	return topping;
}