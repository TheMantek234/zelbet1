#pragma once

enum przypadek { C1 = 1, C2, C3, C4 };
#include <string>
#include <conio.h>
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
	if (Ecm == nullptr || ec2 == nullptr || ecu2 == nullptr)
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
double get_klstl(string nazwa, double* Es)
{
	if ((nazwa == "B500B") || (nazwa == "RB-500W")) {
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


//WYMIAROWANIE ZBROJENIA

void wymiar(double & As1, double & As2, double & xeff, double & a2, const double h, const double Ned, const double e1, const double e2,
	const double fcd, const double b, const double xefflim, const double d, const double Asmin, const double fyd, const double sefflim, bool & min1, bool & min2) {
	a2 = 0.041;

	As2 = (Ned*e1 - fcd * 1000.0 * b*xefflim*(d - 0.5*xefflim)) / (fyd * 1000.0 * (d - a2));
	if (As2 < 2.26*0.0001)
	{
		As2 = 2.26*0.0001;
		/*ZBROJENIE MINIMALNE */
		min2 = true;
	}

	xeff = d - sqrt(d*d - (2.0 * (Ned*e1 - fyd * 1000.0 * As2*(d - a2))) / (fcd * 1000.0 * b));

	if (xeff <= 2.0 * a2)
	{
		As1 = (abs(Ned*e2)) / (fyd*1000.0*(d - a2)); /*PRZYPADEK C1*/
	}
	else
	{
		As1 = (-Ned + fcd * 1000.0 * b*xeff + fyd * 1000.0 * As2) / (fyd * 1000.0);
		if ((As1 >= 0.0) && (As1 <= 2.26*0.0001))
		{
			As1 = 2.26*0.0001;
			/*ZBROJENIE MINIMALNE */
			min1 = true;
		}
		if (As1 < 0.0) /*PRZYPADEK C3 lub C4*/
		{
			As1 = 0.5*Asmin;
			//ROZMIESZCZENIE 
			double Aw = a2 - (2.0*fyd*1000.0*As1*(d - a2)) / ((1.0 - sefflim)*fcd*1000.0*b*d);
			xeff = Aw + sqrt(Aw*Aw - (2 * ((1 - sefflim)*Ned*e2 - (1.0 + sefflim)*fyd*1000.0*As1*(d - a2))) / ((1.0 - sefflim)*fcd*1000.0*b));
			if (xeff < xefflim) {
				As2 = 0.5*Asmin; /*KONIEC */
			}
			if ((xeff <= d) && (xeff >= xefflim)) {
				As2 = (Ned * e1 - fcd * 1000.0 * b*xeff*(d - 0.5*xeff)) / (fyd*1000.0*(d - a2)); /*KONIEC PRZYPADEK C3*/
			}
			if (xeff > d) {
				xeff = a2 + sqrt(a2*a2 - ((2 * (Ned*e2 - fyd * 1000.0 * As1*(d - a2))) / (fcd*1000.0*b)));
				if (xeff <= h) {
					As2 = (Ned*e1 - fcd * 1000.0 * b*xeff*(d - 0.5*xeff)) / (fyd*1000.0*(d - a2)); /* KONIEC PRZYPADEK C4*/
				}
				else {
					xeff = h;
					As2 = (Ned*e1 - fcd * 1000.0 * b*h*(d - 0.5*h)) / (fyd*1000.0*(d - a2));
					As1 = -((Ned*e2 + fcd * 1000.0* b*h*(d - 0.5*h)) / (fyd*1000.0*(d - a2))); /*KONIEC MEKSYKASNKI PRZYPADEK XD*/
				}
			}
			/*W DALSZEJ CZESCI BEDZIE LICZONY RZECZYWISTY STOPIEN ZBROJENIA I ILOSC PRETOW*/
		}
	}
}
// LICZNEIE ILOSCI PREETOW
void wyborpret(double & As1, double & As2, double & n1, double & n2, double & fi1, double & fi2, const bool min1, const bool min2) {
	char d1 = 'f', d2 = 'f';
	if (min1 == false) {
		do {
			cout << "PODAJ SREDNICE PRETOW As1 [m]: ";
			cin >> fi1;
			n1 = (4.0 * As1) / (3.14*fi1*fi1);
			cout << "Potrzeba " << n1 << " pretow,";
			n1 = ceil(n1);
			cout << "zastosowano " << n1 << " zaakceptowac [t/f]?";
			d1 = _getch();
			cout << endl;
		} while (d1 == 'f' || d1 == 'F');
	}
	else { n1 = 2.0; fi1 = 0.012; }
	As1 = (n1 * 3.14*fi1*fi1) / 4.0;
	if (min2 == false) {
		do {
			cout << "PODAJ SREDNICE PRETOW As2 [m]: ";
			cin >> fi2;
			n2 = (4.0 * As2) / (3.14*fi2*fi2);
			cout << "Potrzeba " << n2 << " pretow,";
			n2 = ceil(n2);
			cout << "zastosowano " << n2 << " zaakceptowac [t/f]?";
			d2 = _getch();
			cout << endl;
		} while (d2 == 'f' || d2 == 'F');
	}
	else { n2 = 2.0; fi2 = 0.012; }
	As2 = (n2 * 3.14*fi2*fi2) / 4.0;

}
//LICZENIE NOSNOSCI PRZEKROJU
void nosnosc(double & xeff, const double Ned, const double fyd, const double As2, const double As1, const double fcd, const double b, const double e1,
	const double e2, const double a1, const double a2, double & Mrd, double & Med, const double d, const double xefflim, const double sefflim, const double h) {
	xeff = (Ned - fyd * 1000.0 * As2 + fyd * 1000.0 * As1) / (fcd * 1000.0 *b);
	if (xeff < 2.0 *a2) {
		xeff = 2.0 * a2;
		Med = Ned * e2;
		Mrd = fyd * 1000.0 * As1*(d - a2);  /*KONIEC PRZYPADEK 1*/
	}
	else if ((xeff > 2 * a2) && (xeff <= xefflim)) {
		Med = Ned * e1;
		Mrd = fcd * 1000.0 * b*xeff*(d - 0.5*xeff) + fyd * 1000.0 * As2*(d - a2); /*KONIEC PRZYPADEK 2*/
	}
	else {
		xeff = d * (((Ned - fyd * 1000.0 * As2 - fyd * 1000.0 * As1)*(1 - sefflim) + 2 * fyd*1000.0*As1) / (fcd*1000.0*b*d*(1 - sefflim) + 2 * fyd*1000.0*As1));
		if ((xeff > xefflim) && (xeff <= d)) {
			Med = Ned * e1;
			Mrd = fcd * 1000.0 * b*xeff*(d - 0.5*xeff) + fyd * 1000.0 * As2*(d - a2); /* KONIEC PRZYPADEK 3*/
		}
		else if (xeff > d) {
			xeff = (Ned - fyd * 1000.0 * As2 - fyd * 1000.0 * As1) / (fcd*1000.0*b);
			if ((xeff > d) && (xeff <= h)) {
				Med = Ned * e1;
				Mrd = fcd * 1000.0 * b*xeff*(d - 0.5*xeff) + fyd * 1000.0 * As2*(d - a2); /*KONIEC PRZYPADEK 4*/
			}
			else {
				cout << "GAUDE MATER POLONIA przekroj zle*1000.0 ";
			}
		}
	}
}
