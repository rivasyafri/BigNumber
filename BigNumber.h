#ifndef BigNumber_h
#define BigNumber_h

#include <iostream>
#include <string>

using namespace std;

class BigNumber{
public:
	// 5 Sekawan

	BigNumber (); // Construktor
	BigNumber (string X); // Construktor Parameter
	BigNumber (BigNumber const& BN); // Copy Construktor
	BigNumber& operator= (BigNumber const& BN); // Operasi Operator =
	~ BigNumber (); // Destruktor
	
	// Method untuk cin dan cout
	
	friend ostream &operator<<(ostream &output, const BigNumber& BN) {
		if (BN.sign){
			output << BN.Number;
		} else {
			output << "-" << BN.Number;
		}
		return output;
	}
	friend istream &operator>>(istream &input, BigNumber& BN) {
		string a;
		input >> a;
		if (a.front() == '-') {
			BN.sign = false;
			a.erase(0,1);
			BN.Number = a;
		} else {
			BN.sign = true;
			BN.Number = a;
		}
		while (BN.Number.length() > 0 && BN.Number.front() == '0') {
			BN.Number.erase(0,1);
		}
		if (BN.Number.length() == 0) {
			BN.Number = '0';
		}
		if (BN.Number.compare("0") == 0) {
			BN.sign = true;
		}
		return input;
	}
	
	// Fungsi dan Prosedur Plus

	BigNumber operator+ (BigNumber const& BN); // Operasi Operator +
	BigNumber& operator+= (BigNumber const& BN); // Operasi Operator +=
	string ADCP (string x, string y); // Operasi Divide and Conquer Plus
	void CarrierP (string* Result, int x); //Melakukan rekursif dengan basis apabila pertambahan carry <= 9
	
	// Fungsi dan Prosedur Minus

	BigNumber operator- (BigNumber const & BN); // Operasi Operator -
	BigNumber& operator-= (BigNumber const & BN); // Operasi Operator -=
	string ADCM (string x, string y); // Operasi Divide and Conquer Minus
	void CarrierM (string* Result, int x); // Melakukan rekursif dengan basis apabila pertambahan carry >= 0

	// Fungsi dan Prosedur Times

	BigNumber operator* (BigNumber const & BN); // Operasi Operator *
	BigNumber& operator*= (BigNumber const & BN);  // Operasi Operator *=
	string ADCT (string x, string y);

	BigNumber AAKaratsuba (BigNumber const& BN1, BigNumber const& BN2);
	BigNumber Karatsuba (BigNumber x, BigNumber y);
	
	// Fungsi dan Prosedur Divide

	BigNumber operator/ (BigNumber const & BN); // Operasi Operator '/'
	BigNumber& operator/= (BigNumber const & BN); // Operasi Operator "/="
	
	// Fungsi tambahan

	BigNumber operator% (BigNumber const & BN); // Operasi Operator '%'
	BigNumber& operator%= (BigNumber const & BN); // Operasi Operator "%="

	// Prosedur dan Fungsi Bantuan

	bool isEqual (string x, string y);
	bool isBigger (string x, string y);
	bool isSmaller (string x, string y);
	void RemoveZero (string *B); // Menghilangkan 0 yang ada di depan string
	bool setsignTD(bool BN1, bool BN2); // Mengatur tanda positif dan negatif untuk operasi * dan /
	int chartoint (char e);
	char inttochar (int a);

	// Predikat

	bool operator == (BigNumber X);
	bool operator >= (BigNumber X);
	bool operator > (BigNumber X);
	bool operator <= (BigNumber X);
	bool operator < (BigNumber X);

	// Getter

	bool& getSign ();
	string& getNumber ();

private:
	string Number;
	bool sign;
};


#endif
