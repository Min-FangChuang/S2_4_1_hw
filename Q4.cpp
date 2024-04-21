/*Programming: Min-Fang Chuang   Date: 2024/04/01
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *Define the class BoxOfProduce that contains three bundles of fruits or vegetables
 */
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

//define BoxOfProduce
class BoxOfProduce {
public:
	void setVandF(const string item[3]);
	void getVandF(string item[3]);
	void output();

private:
	string VandF[3];  //three bundles of fruits or vegetables
};

int main() {
	//get the list off items from a text file
	ifstream types;
	types.open("fiveVandF.txt");

	string fiveType[5];
	for (int i = 0;i < 5;i++) {
		types >> fiveType[i];
	}

	//create a object
	BoxOfProduce Box;
	srand(time(NULL));

	//random the item
	string createBox[3];
	for (int i = 0;i < 3;i++) {
		createBox[i] = fiveType[rand() % 5];
	}
	Box.setVandF(createBox);

	string originalBox[3];
	int fiveOfone, threeOfone;

	//display the item can be choose
	cout << "Five types of fruits or vagetables:  ";
	for (int i = 0;i < 5;i++) {
		cout << i+1 <<"."<<fiveType[i] << " ";
	}
	cout << endl;

	//display the items in the box
	Box.getVandF(originalBox);
	cout << "Fruits or vegetables in the box:  ";
	for (int i = 0;i < 3;i++) {
		cout << i + 1 << "." << originalBox[i] << " ";
	}
	cout << endl;

	//let the user to substitute one item
	cout << "\nSubstitute any one of the five type fruits or vegetables for any of the fruits or vegetables in the box." << endl;
	cout << "Choose a number of the five type fruits or vegetables (1~5): ";
	cin >> fiveOfone;
	cout << "Choose a number of the fruits or vegetables in the box (1~3): ";
	cin >> threeOfone;
	//substitute
	originalBox[threeOfone - 1] = fiveType[fiveOfone - 1];
	Box.setVandF(originalBox);
	cout << endl;

	//display the final items in the box
	cout << "-------------------------------------------------\n";
	Box.output();

	system("pause");
	return(0);
}

void BoxOfProduce::setVandF(const string item[3]) {
	for (int i = 0;i < 3;i++) {
		VandF[i] = item[i];
	}
}
void BoxOfProduce::getVandF(string item[3]) {
	for (int i = 0;i < 3;i++) {
		item[i] = VandF[i];
	}
}
void BoxOfProduce::output() {
	cout << "The contents of the box: ";
	for (string i :VandF) {
		cout <<i << " ";
	}
	cout << endl;
}
