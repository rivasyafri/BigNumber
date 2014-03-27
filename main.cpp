#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "BigNumber.h"

using namespace std;

int main() {
	// Kamus Lokal
	// Untuk angka
	string X, Y;
	clock_t t1,t2,tp,tm,tt,tk,td,tmod;

	// Untuk menyimpan hasil
	BigNumber BN1, BN2;

	// Algoritma
	// Masukan angka awal
	cout << "A : ";
	cin >> BN1;

	// Masukan angka akhir
	cout << "B : ";
	cin >> BN2;

	// Set Operasi
	cout << endl << endl;
	cout << "Pertambahan" << endl;
	t1 = clock();
	BigNumber ResultP = BN1 + BN2;
	t2 = clock();
	tp = t2-t1;
	cout << "Waktu pengerjaan : " << tp << " ms\n" << endl;
	cout << BN1 << endl << BN2 << endl;
	cout << "------------------------------------------------------------------------ +" << endl;
	cout << ResultP << endl << endl;
	cout << "Pengurangan" << endl;
	t1 = clock();
	BigNumber ResultM = BN1 - BN2;
	t2 = clock();
	tm = t2-t1;
	cout << "Waktu pengerjaan : " << tm << " ms\n" << endl;
	cout << BN1 << endl << BN2 << endl;
	cout << "------------------------------------------------------------------------ -" << endl;
	cout << ResultM << endl << endl;
	cout << "Perkalian Divide and Conquer biasa" << endl;
	t1 = clock();
	BigNumber ResultT = BN1 * BN2;
	t2 = clock();
	tt = t2-t1;
	cout << "Waktu pengerjaan : " << tt << " ms\n" << endl;
	cout << BN1 << endl << BN2 << endl;
	cout << "------------------------------------------------------------------------ *" << endl;
	cout << ResultT << endl << endl;
	cout << "Perkalian A.A. Karatsuba" << endl;
	t1 = clock();
	BigNumber ResultK = BN1.AAKaratsuba(BN1,BN2);
	t2 = clock();
	tk = t2-t1;
	cout << "Waktu pengerjaan : " << tk << " ms\n" << endl;
	cout << BN1 << endl << BN2 << endl;
	cout << "------------------------------------------------------------------------ *" << endl;
	cout << ResultK << endl << endl;
	cout << "Pembagian" << endl;
	t1 = clock();
	BigNumber ResultD = BN1 / BN2;
	t2 = clock();
	td = t2-t1;
	cout << "Waktu pengerjaan : " << td << " ms\n" << endl;
	cout << BN1 << endl << BN2 << endl;
	cout << "------------------------------------------------------------------------ :" << endl;
	cout << ResultD << endl << endl;
	cout << "Modulus" << endl;
	t1 = clock();
	BigNumber ResultMod = BN1 % BN2;
	t2 = clock();
	tmod = t2-t1;
	cout << "Waktu pengerjaan : " << tmod << " ms\n" << endl;
	cout << BN1 << endl << BN2 << endl;
	cout << "------------------------------------------------------------------------ %" << endl;
	cout << ResultMod << endl << endl;
	cout << endl;
	system("pause");
	return 0;
}
