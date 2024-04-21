/*Programming: Min-Fang Chuang   Date: 2024/04/01
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *Define the class "weight" to stores a weight internally in pound
 */
#include<iostream>
#include<cstdlib>
using namespace std;

//define class weight
class weight {
public:
	void setWeightPounds(double);
	void setWeightKilograms(double);
	void setWeightOunces(double);
	double getPounds();
	double getKilograms();
	double getOunces();
private:
	double pounds;
};

int main() {
	//set by ponds
	weight WInP;
	double pound;
	cout << "Enter a weight in pounds: ";
	cin >> pound;
	WInP.setWeightPounds(pound);
	cout << "Weight in pounds: " << WInP.getPounds() << "\nWeight in kilograms: " << WInP.getKilograms() << "\nWeight in ounces: " << WInP.getOunces() << endl;
	cout << "-----------------------------------\n\n";

	//set by kilograms
	weight WInK;
	double kilogram;
	cout << "Enter a weight in kilograms: ";
	cin >> kilogram;
	WInK.setWeightKilograms(kilogram);
	cout << "Weight in pounds: " << WInK.getPounds() << "\nWeight in kilograms: " << WInK.getKilograms() << "\nWeight in ounces: " << WInK.getOunces() << endl;
	cout << "-----------------------------------\n\n";

	//set by ounces
	weight WInO;
	double ounce;
	cout << "Enter a weight in ounces: ";
	cin >> ounce;
	WInO.setWeightOunces(ounce);
	cout << "Weight in pounds: " << WInO.getPounds() << "\nWeight in kilograms: " << WInO.getKilograms() << "\nWeight in ounces: " << WInO.getOunces() << endl;

	system("pause");
	return(0);
}

//convert to pounds and set
void weight::setWeightPounds(double num) {
	pounds = num;
}
void weight::setWeightKilograms(double num) {
	pounds = num * 2.21;
}
void weight::setWeightOunces(double num) {
	pounds = num / 16;
}

//convert and return
double weight::getPounds() {
	return pounds;
}
double weight::getKilograms() {
	return pounds / 2.21;
}
double weight::getOunces() {
	return pounds * 16;
}
