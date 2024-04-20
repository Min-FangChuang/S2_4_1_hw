#include<iostream>
using namespace std;

class Money {
public:
	void setDollars(int);
	int getDollars();
	void setCents(int);
	int getCents();
	double moneyamount();
private:
	int dollars;
	int cents;
};

void clear();

int main() {
	Money accounts[10];
	int i = 0, dollar, cent;
	while (i < 10) {
		cout << "Account " << i + 1 << endl;
		cout << "Number of dollars: ";
		cin >> dollar;
		cout << "Number of cents: ";
		cin >> cent;
		accounts[i].setDollars(dollar);
		accounts[i].setCents(cent);

		cout << "\nThe money amount: " << accounts[i].moneyamount() << endl;
		cout << "-------------------------------------\n\n";
		if (i > 0) {
			//cout << ".";
			clear();
			cout << "/";
			cout << "Do you want to open a new account (y/n) ?";
			if (getchar() == 'n') {
				break;
			}
		}
		i++;
	}
}

void Money::setDollars(int num) {
	if (num >= 0) {
		dollars = num;
	}
	else {
		cout << "Error: the number of dollars is negative" << endl;
	}
}
int Money::getDollars() {
	return dollars;
}
void Money::setCents(int num) {
	if (num >= 0) {
		cents = num;
	}
	else {
		cout << "Error: the number of cents is negative" << endl;
	}
}
int Money::getCents() {
	return cents;
}
double Money::moneyamount() {
	double money;
	money = dollars;
	money += cents / 100.0;
	return money;
}

void clear() {
	do {
		if (getchar() == '\n') { break; }
	} while (1);
}