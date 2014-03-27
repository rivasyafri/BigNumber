#include "BigNumber.h"

using namespace std;

// 5 Sekawan

BigNumber::BigNumber () {
	Number = "0";
	sign = true;
}

BigNumber::BigNumber (string X) {
	if (X.front() == '-') {
		sign = false;
		X.erase(0,1);
		Number = X;
	} else {
		sign = true;
		Number = X;
	}
	RemoveZero(&Number);
	if (Number.compare("0") == 0) {
		sign = true;
	}
}

BigNumber::BigNumber (BigNumber const & BN) {
	Number = BN.Number;
	sign = BN.sign;
}

BigNumber& BigNumber::operator= (BigNumber const & BN) {
	Number = BN.Number;
	sign = BN.sign;
	return *this;
}

BigNumber::~ BigNumber () {
}

// Operasi - Operasi

BigNumber BigNumber::operator+ (BigNumber const & BN) {
	BigNumber Result;
	if ((sign && BN.sign) || (!sign && !BN.sign)) {
		Result.Number = ADCP(Number,BN.Number);
		if (!sign && !BN.sign) {
			Result.sign = false;
		} else {
			Result.sign = true;
		}
	} else if (sign && !BN.sign) {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = true;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = false;
		} else {
			Result.Number = "0";
			Result.sign = true;
		}
	} else {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = false;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = true;
		} else {
			Result.Number = "0";
			Result.sign = true;
		}
	}
	RemoveZero(&Result.Number);
	return Result;
}

BigNumber& BigNumber::operator+= (BigNumber const & BN) {
	BigNumber Result;
	if ((sign && BN.sign) || (!sign && !BN.sign)) {
		Result.Number = ADCP(Number,BN.Number);
		if (!sign && !BN.sign) {
			Result.sign = false;
		} else {
			Result.sign = true;
		}
	} else if (sign && !BN.sign) {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = true;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = false;
		} else {
			Result.Number = '0';
			Result.sign = true;
		}
	} else {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = false;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = true;
		} else {
			Result.Number = '0';
			Result.sign = true;
		}
	}
	RemoveZero(&Result.Number);
	Number = Result.Number;
	sign = Result.sign;
	return *this;
}

BigNumber BigNumber::operator- (BigNumber const & BN) {
	BigNumber Result;
	if ((sign && !BN.sign) || (!sign && BN.sign)) {
		Result.Number = ADCP(Number,BN.Number);
		if (!sign && BN.sign) {
			Result.sign = false;
		} else {
			Result.sign = true;
		}
	} else if (sign && BN.sign) {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = true;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = false;
		} else {
			Result.Number = '0';
			Result.sign = true;
		}
	} else {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = false;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = true;
		} else {
			Result.Number = '0';
			Result.sign = true;
		}
	}
	RemoveZero(&Result.Number);
	return Result;
}

BigNumber& BigNumber::operator-= (BigNumber const & BN) {
	BigNumber Result;
	if ((sign && !BN.sign) || (!sign && BN.sign)) {
		Result.Number = ADCP(Number,BN.Number);
		if (!sign && BN.sign) {
			Result.sign = false;
		} else {
			Result.sign = true;
		}
	} else if (sign && BN.sign) {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = true;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = false;
		} else {
			Result.Number = '0';
			Result.sign = true;
		}
	} else {
		if (isBigger(Number,BN.Number)) {
			Result.Number = ADCM(Number,BN.Number);
			Result.sign = false;
		} else if (isBigger(BN.Number,Number)) {
			Result.Number = ADCM(BN.Number,Number);
			Result.sign = true;
		} else {
			Result.Number = '0';
			Result.sign = true;
		}
	}
	RemoveZero(&Result.Number);
	Number = Result.Number;
	sign = Result.sign;
	return *this;
}

BigNumber BigNumber::operator* (BigNumber const & BN){
	BigNumber Result;
	string number;
	if (Number.length() > BN.Number.length()) {
		number = BN.Number;
		int M = Number.length() - BN.Number.length();
		number.insert(0,M,'0');
		Result.Number = ADCT(Number,number);
	} else if (Number.length() < BN.Number.length()) {
		number = Number;
		int M = BN.Number.length() - Number.length();
		number.insert(0,M,'0');
		Result.Number = ADCT(number,BN.Number);
	} else {
		Result.Number = ADCT(Number,BN.Number);
	}
	Result.sign = setsignTD(sign,BN.sign);
	RemoveZero(&Result.Number);
	return Result;
}

BigNumber& BigNumber::operator*= (BigNumber const & BN){
	BigNumber Result;
	string number;
	if (Number.length() > BN.Number.length()) {
		number = BN.Number;
		int M = Number.length() - BN.Number.length();
		number.insert(0,M,'0');
		Result.Number = ADCT(Number,number);
	} else if (Number.length() < BN.Number.length()) {
		number = Number;
		int M = BN.Number.length() - Number.length();
		number.insert(0,M,'0');
		Result.Number = ADCT(number,BN.Number);
	} else {
		Result.Number = ADCT(Number,BN.Number);
	}
	Result.sign = setsignTD(sign,BN.sign);
	RemoveZero(&Result.Number);
	Number = Result.Number;
	sign = Result.sign;
	return *this;
}

BigNumber BigNumber::operator/ (BigNumber const & BN){
	BigNumber Result;
	string jj;
	jj = BN.Number;
	RemoveZero(&jj);
	if (jj.compare("0")==0) {
		cout << "Error" <<endl;
	} else if (isBigger(Number,BN.Number)) {
		string number = Number;
		string a;
		do {
			a += number[0];
			if (isSmaller(a,BN.Number)) {
				Result.Number += '0';
				if (a.compare("0") == 0) {
					a.clear();
				}
			} else if (isBigger(a,BN.Number)) {
				int j = 1;
				string b,temp;
				b = inttochar(j);
				while (isBigger(a,ADCT(BN.Number,b)) || isEqual(a,ADCT(BN.Number,b))) {
					j++;
					if (j > 9) {
						b = "10";
					} else {
						b = inttochar(j);
					}
				}
				j--;
				b = inttochar(j);
				temp = ADCM(a,ADCT(BN.Number,b));
				if (temp.compare("0") != 0) {
					a = temp;
				} else {
					a.clear();
				}
				Result.Number += b;
			} else {
				Result.Number += '1';
				a.clear();
			}
			number.erase(0,1);
		} while (number.length() != 0);
	} else if (isEqual(Number,BN.Number)) {
		Result.Number = '1';
	} else {
		Result.Number = '0';
	}
	RemoveZero(&Result.Number);
	Result.sign = setsignTD(sign,BN.sign);
	return Result;
} // Operasi Operator '/'

BigNumber& BigNumber::operator/= (BigNumber const & BN){
	BigNumber Result;
	string jj;
	jj = BN.Number;
	RemoveZero(&jj);
	if (jj.compare("0")) {
		cout << "Error" <<endl;
	} else if (isBigger(Number,BN.Number)) {
		string number = Number;
		string a;
		do {
			a += number[0];
			if (isSmaller(a,BN.Number)) {
				Result.Number += '0';
				if (a.compare("0") == 0) {
					a.clear();
				}
			} else if (isBigger(a,BN.Number)) {
				int j = 1;
				string b,temp;
				b = inttochar(j);
				while (isBigger(a,ADCT(BN.Number,b)) || isEqual(a,ADCT(BN.Number,b))) {
					j++;
					if (j > 9) {
						b = "10";
					} else {
						b = inttochar(j);
					}
				}
				j--;
				b = inttochar(j);
				temp = ADCM(a,ADCT(BN.Number,b));
				if (temp.compare("0") != 0) {
					a = temp;
				} else {
					a.clear();
				}
				Result.Number += b;
			} else {
				Result.Number += '1';
				a.clear();
			}
			number.erase(0,1);
		} while (number.length() != 0);
	} else if (isEqual(Number,BN.Number)) {
		Result.Number = '1';
	} else {
		Result.Number = '0';
	}
	RemoveZero(&Result.Number);
	Result.sign = setsignTD(sign,BN.sign);
	Number = Result.Number;
	sign = Result.sign;
	return *this;
} // Operasi Operator '/'

BigNumber BigNumber::operator% (BigNumber const & BN){
	BigNumber Result;
	string jj;
	jj = BN.Number;
	RemoveZero(&jj);
	if (jj.compare("0")==0) {
		cout << "Error" <<endl;
	} else if (isBigger(Number,BN.Number)) {
		string number = Number;
		string a;
		bool stop = false;
		do {
			a += number[0];
			if (isSmaller(a,BN.Number)) {
				if (a.compare("0") == 0) {
					a.clear();
				}
			} else if (isBigger(a,BN.Number)) {
				int j = 1;
				string b,temp;
				b = inttochar(j);
				while (isBigger(a,ADCT(BN.Number,b)) || isEqual(a,ADCT(BN.Number,b))) {
					j++;
					if (j > 9) {
						b = "10";
					} else {
						b = inttochar(j);
					}
				}
				j--;
				b = inttochar(j);
				temp = ADCM(a,ADCT(BN.Number,b));
				if (temp.compare("0") != 0) {
					a = temp;
				} else {
					a.clear();
				}
			} else {
				a.clear();
			}
			number.erase(0,1);
		} while (number.length() != 0);
		Result.Number = a;
	} else if (isEqual(Number,BN.Number)) {
		Result.Number = '0';
	} else {
		Result.Number = Number;
	}
	RemoveZero(&Result.Number);
	Result.sign = sign;
	return Result;
} // Operasi Operator '%'

BigNumber& BigNumber::operator%= (BigNumber const & BN){
	BigNumber Result;
	string jj;
	jj = BN.Number;
	RemoveZero(&jj);
	if (jj.compare("0")==0) {
		cout << "Error" <<endl;
	} else if (isBigger(Number,BN.Number)) {
		string number = Number;
		string a;
		bool stop = false;
		do {
			a += number[0];
			if (isSmaller(a,BN.Number)) {
				if (a.compare("0") == 0) {
					a.clear();
				}
			} else if (isBigger(a,BN.Number)) {
				int j = 1;
				string b,temp;
				b = inttochar(j);
				while (isBigger(a,ADCT(BN.Number,b)) || isEqual(a,ADCT(BN.Number,b))) {
					j++;
					if (j > 9) {
						b = "10";
					} else {
						b = inttochar(j);
					}
				}
				j--;
				b = inttochar(j);
				temp = ADCM(a,ADCT(BN.Number,b));
				if (temp.compare("0") != 0) {
					a = temp;
				} else {
					a.clear();
				}
			} else {
				a.clear();
			}
			number.erase(0,1);
		} while (number.length() != 0);
		Result.Number = a;
	} else if (isEqual(Number,BN.Number)) {
		Result.Number = '0';
	} else {
		Result.Number = Number;
	}
	RemoveZero(&Result.Number);
	Result.sign = sign;
	Number = Result.Number;
	sign = Result.sign;
	return *this;
} // Operasi Operator '/'

// Fungsi dan Prosedur Pembantu

void BigNumber::RemoveZero (string *B) {
	while ((*B).length() > 0 && (*B).front() == '0') {
		(*B).erase(0,1);
	}
	if ((*B).length() == 0) {
		(*B) = '0';
	}
}

bool BigNumber::setsignTD(bool BN1, bool BN2) {
	if ((BN1 && BN2) || (!BN1 && !BN2)) {
		return true;
	} else {
		return false;
	}
}

string BigNumber::ADCP (string x, string y) {
	// Membagi string menjadi beberapa bagian yang lalu di passing ke argumen.
	string result;
	string xx = x;
	string yy = y;
	string a,b,c,d;
	int s;
	while (xx.length() > yy.length()) {
		yy = '0' + yy;
	}
	while (xx.length() < yy.length()) {
		xx = '0' + xx;
	}
	int n = xx.length();
	if (n == 1) {
		// basis
		result = to_string(chartoint(x[0])+chartoint(y[0]));
	} else {
		s = n / 2;
		if (n % 2 == 1) {
			// dibagi untuk divide and conquer
			a = xx.substr(0,s+1);
			b = xx.substr(s+1);
			c = yy.substr(0,s+1);
			d = yy.substr(s+1);
		} else {
			// dibagi untuk divide and conquer
			a = xx.substr(0,s);
			b = xx.substr(s);
			c = yy.substr(0,s);
			d = yy.substr(s);
		}
		string exp, exp2;
		for (int i = 0; i < s; i++) {
			exp += '0';
			exp2 += "00";
		}
		string e = ADCP(a,c);
		if (e.length() > a.length()) {
			CarrierP(&result,chartoint(e.front()));
			e.erase(0,1);
		}
		result += e;
		e = ADCP(b,d);
		if (e.length() > b.length()) {
			CarrierP(&result,chartoint(e.front()));
			e.erase(0,1);
		}
		result += e;
	}
	return result;
}

void BigNumber::CarrierP (string * Result, int x) {
	// Mengatur carrier yang merupakan dampak dari penjumlahan atau pengurangan
	if ((*Result).length() != 0) {
		if (x + chartoint((*Result).back()) <= 9) {	
			// basis
			(*Result).back() = inttochar(chartoint((*Result).back()) + x);
		} else {
			// rekurens
			int a;
			a = chartoint((*Result).back()) + x;
			(*Result).pop_back();
			CarrierP(Result,a/10);
			(*Result) += inttochar(a%10);
		}
	} else {
		// basis
		(*Result) += inttochar(x);
	}
}

string BigNumber::ADCM (string x, string y) {
	// Kamus
	string xx = x;
	string yy = y;
	string result;
	while (xx.length() > yy.length()) {
		yy = '0' + yy;
	}
	while (xx.length() < yy.length()) {
		xx = '0' + xx;
	}
	int i = 1;
	bool stop = false;
	do {
		int a;
		if (yy.length() > 0) {
			a = chartoint(xx.back()) - chartoint(yy.back());
			xx.pop_back();
			yy.pop_back();
			if (a >= 0) {
				result.insert(0,1,inttochar(a));
			} else {
				CarrierM(&xx,1);
				result.insert(0,1,inttochar(a+10));
			}
			i++;
		} else {
			stop = true;
		}
	} while (xx.length() > 0 && !stop);
	RemoveZero(&result);
	return result;
}

void BigNumber::CarrierM (string * Result, int x) {
	// Mengatur carrier yang merupakan dampak dari pengurangan
	if (chartoint((*Result).back()) - x >= 0) {
		(*Result).back() = inttochar(chartoint((*Result).back()) - x);
	} else {
		int a = chartoint((*Result).back()) - x;
		(*Result).pop_back();
		CarrierM(Result,1);
		if ((*Result).front() == '0') {
			(*Result).pop_back();
		}
		(*Result) += inttochar(a+10);
	}
}

string BigNumber::ADCT (string x, string y) {
	string xx = x;
	string yy = y;
	string a,b,c,d,result;
	int s;
	while (xx.length() > yy.length()) {
		yy = '0' + yy;
	}
	while (xx.length() < yy.length()) {
		xx = '0' + xx;
	}
	int n = xx.length();
	if (n == 1) {
		if (chartoint(xx[0])*chartoint(yy[0]) > 0) {
			result = to_string(chartoint(xx[0])*chartoint(yy[0]));
		}
	} else {
		s = n / 2;
		if (n % 2 == 1) {
			// dibagi untuk divide and conquer
			a = xx.substr(0,s+1);
			b = xx.substr(s+1);
			c = yy.substr(0,s+1);
			d = yy.substr(s+1);
		} else {
			// dibagi untuk divide and conquer
			a = xx.substr(0,s);
			b = xx.substr(s);
			c = yy.substr(0,s);
			d = yy.substr(s);
		}
		string exp, exp2;
		for (int i = 0; i < s; i++) {
			exp += '0';
			exp2 += "00";
		}
		result = ADCP(ADCP(ADCT(a,c)+exp2,ADCT(b,c)+exp),ADCP(ADCT(a,d)+exp,ADCT(b,d)));
	}
	RemoveZero(&result);
	return result;
}

BigNumber BigNumber::AAKaratsuba (BigNumber const& BN1, BigNumber const& BN2) {
	BigNumber Result;
	string number;
	if (BN1.Number.length() > BN2.Number.length()) {
		BigNumber BN3;
		BN3.Number = BN2.Number;
		int M = BN1.Number.length() - BN2.Number.length();
		BN3.Number.insert(0,M,'0');
		BN3.sign = BN2.sign;
		Result = Karatsuba(BN3,BN1);
	} else if (BN1.Number.length() < BN2.Number.length()) {
		BigNumber BN3;
		BN3.Number = BN1.Number;
		int M = BN2.Number.length() - BN1.Number.length();
		BN3.Number.insert(0,M,'0');
		BN3.sign = BN1.sign;
		Result = Karatsuba(BN3,BN2);
	} else {
		Result = Karatsuba(BN1,BN2);
	}
	setsignTD(BN1.sign,BN2.sign);
	RemoveZero(&Result.Number);
	return Result;
}

BigNumber BigNumber::Karatsuba (BigNumber x, BigNumber y) {
	string xx = x.Number;
	string yy = y.Number;
	BigNumber a,b,c,d,result;
	int s;
	while (xx.length() > yy.length()) {
		yy = '0' + yy;
	}
	while (xx.length() < yy.length()) {
		xx = '0' + xx;
	}
	int n = xx.length();
	if (n == 1) {
		if (chartoint(xx[0])*chartoint(yy[0]) > 0) {
			result.Number = to_string(chartoint(xx[0])*chartoint(yy[0]));
			setsignTD(x.sign,y.sign);
		}
	} else {
		s = n / 2;
		if (n % 2 == 1) {
			// dibagi untuk divide and conquer
			a.Number = xx.substr(0,s+1);
			a.sign = x.sign;
			b.Number = xx.substr(s+1);
			b.sign = x.sign;
			c.Number = yy.substr(0,s+1);
			c.sign = y.sign;
			d.Number = yy.substr(s+1);
			d.sign = y.sign;
		} else {
			// dibagi untuk divide and conquer
			a.Number = xx.substr(0,s);
			a.sign = x.sign;
			b.Number = xx.substr(s);
			b.sign = x.sign;
			c.Number = yy.substr(0,s);
			c.sign = y.sign;
			d.Number = yy.substr(s);
			d.sign = y.sign;
		}
		string exp, exp2;
		for (int i = 0; i < s; i++) {
			exp += '0';
			exp2 += "00";
		}
		BigNumber P,Q,R;
		P = Karatsuba(a,c);
		Q = Karatsuba(b,d);
		R = Karatsuba(ADCP(a.Number,b.Number),ADCP(c.Number,d.Number));
		BigNumber Min = R - Q - P;
		Min.Number += exp;
		P.Number += exp2;
		result = P + Min + Q;
	}
	return result;
}

// Predikat

bool BigNumber::operator == (BigNumber X) {
	if (sign && !X.sign) {
		return false;
	} else if (!sign && X.sign) {
		return false;
	} else {
		if (isEqual(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	}
}

bool BigNumber::operator >= (BigNumber X) {
	if (sign && !X.sign) {
		return true;
	} else if (!sign && X.sign) {
		return false;
	} else if (sign && X.sign) {
		if (isBigger(Number,X.Number) || isEqual(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	} else {
		if (isSmaller(Number,X.Number) || isEqual(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	}
}

bool BigNumber::operator > (BigNumber X) {
	if (sign && !X.sign) {
		return true;
	} else if (!sign && X.sign) {
		return false;
	} else if (sign && X.sign) {
		if (isBigger(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	} else {
		if (isSmaller(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	}
}

bool BigNumber::operator <= (BigNumber X) {
	if (sign && !X.sign) {
		return false;
	} else if (!sign && X.sign) {
		return true;
	} else if (sign && X.sign) {
		if (isSmaller(Number,X.Number) || isEqual(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	} else {
		if (isBigger(Number,X.Number) || isEqual(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	}
}

bool BigNumber::operator < (BigNumber X) {
	if (sign && !X.sign) {
		return false;
	} else if (!sign && X.sign) {
		return true;
	} else if (sign && X.sign) {
		if (isSmaller(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	} else {
		if (isBigger(Number,X.Number)) {
			return true;
		} else {
			return false;
		}
	}
}

bool BigNumber::isEqual (string x, string y) {
	if (x.length() > y.length()) {
		return false;
	} else if (x.length() < y.length()) {
		return false;
	} else {
		bool stop = true;
		bool cek = true;
		int i = 0;
		int M = x.length();
		do {
			if (chartoint(x[i]) < chartoint(y[i])) {
				cek = false;
				stop = false;
			} else if (chartoint(x[i]) > chartoint(y[i])) {
				stop = false;
				cek = false;
			} else {
				i++;
			}
		} while (i < M && stop);
		return cek;
	}
}

bool BigNumber::isBigger (string x, string y) {
	if (x.length() > y.length()) {
		return true;
	} else if (x.length() < y.length()) {
		return false;
	} else {
		bool stop = true;
		bool cek = true;
		int i = 0;
		int M = x.length();
		do {
			if (chartoint(x[i]) < chartoint(y[i])) {
				cek = false;
				stop = false;
			} else if (chartoint(x[i]) > chartoint(y[i])) {
				stop = false;
			} else {
				i++;
			}
		} while (i < M && stop);
		if (i == M && chartoint(x[i-1]) == chartoint(y[i-1])) {
			cek = false;
		}
		return cek;
	}
}

bool BigNumber::isSmaller (string x, string y) {
	if (x.length() < y.length()) {
		return true;
	} else if (x.length() > y.length()) {
		return false;
	} else {
		bool stop = true;
		bool cek = true;
		int i = 0;
		int M = x.length();
		do {
			if (chartoint(x[i]) > chartoint(y[i])) {
				cek = false;
				stop = false;
			} else if (chartoint(x[i]) < chartoint(y[i])) {
				stop = false;
			} else {
				i++;
			}
		} while (i < M && stop);
		if (i == M && chartoint(x[i-1]) == chartoint(y[i-1])) {
			cek = false;
		}
		return cek;
	}
}

// Getter

string & BigNumber::getNumber () {
	return Number;
}

bool & BigNumber::getSign () {
	return sign;
}

// Fungsi dan Prosedur Tambahan

int BigNumber::chartoint (char e) {
	switch(e) {
		case '1':	return 1;
					break;
		case '2':	return 2;
					break;
		case '3':	return 3;
					break;
		case '4':	return 4;
					break;
		case '5':	return 5;
					break;
		case '6':	return 6;
					break;
		case '7':	return 7;
					break;
		case '8':	return 8;
					break;
		case '9':	return 9;
					break;
		default :	return 0;
					break;
	}
}

char BigNumber::inttochar (int a) {
	switch(a) {
		case 1	:	return '1';
					break;
		case 2	:	return '2';
					break;
		case 3	:	return '3';
					break;
		case 4	:	return '4';
					break;
		case 5	:	return '5';
					break;
		case 6	:	return '6';
					break;
		case 7	:	return '7';
					break;
		case 8	:	return '8';
					break;
		case 9	:	return '9';
					break;
		default	:	return '0';
					break;
	}
}
