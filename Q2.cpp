/*Programming: Min-Fang Chuang   Date: 2024/04/01
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *Define a class name "Money" that stores a monetary amount
 */
#include<iostream>
#include<cstdlib>
using namespace std;

//define class "Money"
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

//function prototype
void clear();

int main() {
	Money accounts[10];  //create ten object

	int i = 0, dollar, cent;
	while (i < 10) {   //
		//get the value of Money by user
		cout << "Account " << i + 1 << endl;
		cout << "Number of dollars: ";
		cin >> dollar;
		cout << "Number of cents: ";
		cin >> cent;

		//Set the value of Money
		accounts[i].setDollars(dollar);
		accounts[i].setCents(cent);

		//display the money amount
		cout << "\nThe money amount: " << accounts[i].moneyamount() << endl;
		cout << "-------------------------------------\n\n";

		if (i > 0 && i < 9) {   // at least two object and ten object is the maximum
			clear();
			//a new object or not?
			cout << "Do you want to open a new account (y/n) ?";
			if (getchar() == 'n') {
				break;
			}
		}
		i++;
	}

	system("pause");
	return(0);
}

void Money::setDollars(int num) {
	//chech the dollars is allowed
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
	//chech the cents is allowed
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

//compute the mony amount
double Money::moneyamount() {
	double money;
	money = dollars;
	money += cents / 100.0;
	return money;
}

//clean the char
void clear() {
	do {
		if (getchar() == '\n') { break; }
	} while (1);
}