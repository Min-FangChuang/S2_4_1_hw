/*Programming: Min-Fang Chuang   Date: 2024/04/15
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *define a class "zipCode" that encode and decode five digit bar codes
 */
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

//define zipCode
class zipCode {
public:
	zipCode(int);
	zipCode(string);
	zipCode();
	void setZipcode(int);
	void setZipcodeBar(string);
	int getZipcode()const { return zipcode; }
	string getZipcodeBar()const { return zipcodeBar; }
private:
	int zipcode;
	string zipcodeBar;
	const int value[5] = { 7,4,2,1,0 };
	void testcode();
	void testbar();
	void encode();
	void decode();
};

int main() {
	//input as an integer   //input as a bar code string
	zipCode code(98765), bar("110100101000101011000010011");

	//display the result of encode or decode
	cout << "First: \nzip code as an integer: " << code.getZipcode() << "\nzip code as a bar code string: " << code.getZipcodeBar() << endl;
	cout << "\nSecond: \nzip code as an integer: " << bar.getZipcode() << "\nzip code as a bar code string: " << bar.getZipcodeBar() << endl;

	system("pause");
	return(0);
}

//constructor
zipCode::zipCode(int code) :zipcode(code){
	testcode();
	encode();
}
zipCode::zipCode(string bar):zipcodeBar(bar) {
	testbar();
	decode();
}
zipCode::zipCode():zipcode(0){}

//set the code
void zipCode::setZipcode(int code) {
	zipcode = code;
	testcode();
	encode();
}
void zipCode::setZipcodeBar(string bar) {
	zipcodeBar = bar;
	testbar();
	decode();
}

//test whether the code is allow
void zipCode::testcode() {
	if (zipcode >= 100000 ) {
		cout << "Illegal zip code : five digits" << endl;
		exit(1);
	}
}
void zipCode::testbar() {
	if (zipcodeBar.length() != 27) {
		cout << "Illegal zip bar code : 27 digits" << endl;
		exit(1);
	}
	if (zipcodeBar[0] != '1' || zipcodeBar[26] != '1') {
		cout << "Illegal zip bar code : the first and last digit must be '1'" << endl;
		exit(1);
	}

	int one = 0;
	for (int i = 1;i < 26;i++) {
		if (i % 5 == 1) { one = 0; }
		if (zipcodeBar[i] == '1') {
			one++;
		}
		if (i % 5 == 0) {
			if (one != 2) {
				cout << "Illegal zip bar code : a group of digit have two '1'" << endl;
				exit(1);
			}
		}
	}
}

//encode to a bar code
void zipCode::encode() {
	zipcodeBar = "1";
	int digit;
	for (int i = 0;i < 5;i++) {
		digit = zipcode / pow(10, 5 - 1 - i);
		digit %= 10;
		switch (digit) {
		case 0:
			zipcodeBar += "11000";
			break;
		case 1:
			zipcodeBar += "00011";
			break;
		case 2:
			zipcodeBar += "00101";
			break;
		case 3:
			zipcodeBar += "00110";
			break;
		case 4:
			zipcodeBar += "01001";
			break;
		case 5:
			zipcodeBar += "01010";
			break;
		case 6:
			zipcodeBar += "01100";
			break;
		case 7:
			zipcodeBar += "10001";
			break;
		case 8:
			zipcodeBar += "10010";
			break;
		case 9:
			zipcodeBar += "10100";
			break;
		default:
			cout<<"Error "<<endl;
		}
	}
	zipcodeBar += "1";
}

//decode to integer code
void zipCode::decode() {
	zipcode = 0;
	int digit;
	for (int i = 0;i < 5;i++) {
		digit = 0;
		zipcode *= 10;
		for (int j = 0;j < 5;j++) {
			digit += ((int)zipcodeBar[1 + 5 * i + j]-(int)'0')*value[j];
		}
		if (digit == 11) { digit = 0; }
		zipcode += digit;
	}
}
