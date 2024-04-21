/*Programming: Min-Fang Chuang   Date: 2024/04/15
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *Define a class HotDogStand
 */
#include<iostream>
#include<cstdlib>
using namespace std;

//define HotDogStand
class HotDogStand {
public:
	HotDogStand(int Id, int Sold);
	HotDogStand();
	static int getTotalSold() { return totalSold; }
	void JustSold();
	int getSold() const { return sold; }
private:
	int id;
	int sold;
	static int totalSold;
};

int HotDogStand::totalSold = 0;
int main() {
	//create the object
	HotDogStand hds1(1, 8), hds2(2, 243), hds3(3, 323), hds4;

	//display the condition of sold
	cout << "The total sold of hot dog stands " << HotDogStand::getTotalSold() << endl;
	cout << "(" << hds1.getSold() << "+" << hds2.getSold() << "+" << hds3.getSold() << "+" << hds4.getSold() << ")" << endl;

	//sale some hot dog
	hds1.JustSold();
	hds1.JustSold();
	hds2.JustSold();
	hds1.JustSold();
	hds4.JustSold();

	//display the condition of sold again
	cout << "\n<One hour later>" << endl;
	cout << "The total sold of hot dog stands " << HotDogStand::getTotalSold() << endl;
	cout << "(" << hds1.getSold() << "+" << hds2.getSold() << "+" << hds3.getSold() << "+" << hds4.getSold() << ")" << endl;

	system("pause");
	return(0);
}

//constructor
HotDogStand::HotDogStand(int Id, int Sold) : id(Id),sold(Sold){
	totalSold += sold;
}
HotDogStand::HotDogStand() : id(0), sold(0) {}

//increments the number of hot dogs the stand has sold by one
void HotDogStand::JustSold() {
	sold++;
	totalSold++;
}
