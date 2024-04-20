#include<iostream>
#include<cstdlib>
using namespace std;

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
	HotDogStand hds1(1, 8), hds2(2, 243), hds3(3, 323), hds4;
	cout << "The total sold of hot dog stands " << HotDogStand::getTotalSold() << endl;
	cout << "(" << hds1.getSold() << "+" << hds2.getSold() << "+" << hds3.getSold() << "+" << hds4.getSold() << ")" << endl;

	hds1.JustSold();
	hds1.JustSold();
	hds2.JustSold();
	hds1.JustSold();
	hds4.JustSold();

	cout << "\n<One hour later>" << endl;
	cout << "The total sold of hot dog stands " << HotDogStand::getTotalSold() << endl;
	cout << "(" << hds1.getSold() << "+" << hds2.getSold() << "+" << hds3.getSold() << "+" << hds4.getSold() << ")" << endl;

	system("pause");
	return(0);
}

HotDogStand::HotDogStand(int Id, int Sold) : id(Id),sold(Sold){
	totalSold += sold;
}
HotDogStand::HotDogStand() : id(0), sold(0) {}
void HotDogStand::JustSold() {
	sold++;
	totalSold++;
}
