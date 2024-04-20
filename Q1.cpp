#include<iostream>
using namespace std;
#define MAX_PIZZA 18
#define String Size[3] ={"Small", "Medium", "Large"}
class Pizza {
	public:
		void outputDescription();
		double computePrice();
		void setType(int);
		int getType();
		void setSize(int);
		int getSize();
		void setTopping(int);
		int getTopping();
	private:
		int type;
		int size;
		int topping;
};

int main() {
	Pizza user[MAX_PIZZA];

	for (int i = 0;i < 18;i++) {
		user[i].setType(i / 6 + 1);
		user[i].setSize((i % 6) / 2 + 1);
		user[i].setTopping(i % 2 + 1);

		user[i].outputDescription();
		cout << "\nPicee :" << user[i].computePrice() << endl;
		cout << "-----------------------------------------\n\n";

	}

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