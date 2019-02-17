#pragma once

enum przypadek{C1=1,C2,C3,C4};
#include <string>
using namespace std;
// oblicza cmind zaleznosci od klasy ekspozycji
double get_klesp(string nazwa) {
	if (nazwa == "XC1")
	{
		return 15.0;
	}
	else
	{
		return -1.0;
	}
}

//zwraca fck
double get_klbet(string nazwa, double* Ecm, double* ec2, double* ecu2)
{
	if(Ecm == nullptr || ec2== nullptr || ecu2== nullptr)
	{
		return -1.0;
	}
	if (nazwa == "C20/25")
	{
		*Ecm = 30.0;
		*ec2 = 2.0*0.001;
		*ecu2 = 3.5*0.001;
		return 20.0;
	}
}
// liczy pozostale wartosci
double bet1(double fck, double Ecm, double* fcm, double* Ecd)
{
	if (fcm == nullptr || Ecd == nullptr) {
		return -1;
	}
	*fcm = fck + 8.0;
	*Ecd = Ecm / 1.2;
	return fck / 1.4;

	
}
// klasa stali
double get_klstl(string nazwa,double* Es)
{
	if((nazwa == "B500B") ||(nazwa ==  "RB-500W")){
		*Es = 200.0;
		return 500.0;

	}
	else
	{
		return -1.0;
	}
}
// liczy pozostale wartosci :)
double stl1(double fyk, double Es, double* fyd) {
	*fyd = fyk / 1.15;
	return -(*fyd) / Es * 0.001;
}

// licz przypadek
