#include <iostream>
#include <math.h>
#include <cmath>


using namespace std;

int main() {
	double As1=0.0, As2 = 0.0, xeff = 0.0, a2 = 0.0, h =0.0;
	double Ned = 0.0, e1 = 0.0, e2 = 0.0, fcd, b, xefflim, d, Asmin, fyd, a2, sefflim;
	bool min = false;
	
	As2 = (Ned*e1 - fcd * 1000 * b*xefflim*(d - 0.5*xefflim)) / (fyd * 1000 * (d - a2));
	if (As2 < 2.26*0.0001)
	{
		As2 = 2.26*0.0001;
		/*ZBROJENIE MINIMALNE */
		min = true;
	}
	
	xeff = d - sqrt(d*d - (2 * (Ned*e1 - fyd * 1000 * As2*(d - a2))) / (fcd * 1000 * b));

	if (xeff <= 2 * a2)
	{
		As1 = (abs(Ned*e2)) / (fyd*(d - a2)); /*PRZYPADEK C1*/
	}
	else
	{
		As1 = (-Ned + fcd * b*xeff + fyd * As2) / fyd;
		/*if (As1 > 0)
		{
			return As1; PRZYPADEK C2 DOPISAC WARUNEK NA MINIMALNE ZBROJENIE 2 fi 12 
		}*/
		if (As1 < 0) /*PRZYPADEK C3 lub C4*/
		{
			As1 = 0.5*Asmin;
			//ROZMIESZCZENIE 
			double Aw = a2 - (2.0*fyd*As1*(d - a2)) / ((1 - sefflim)*fcd*b*d);
			xeff = Aw + sqrt(Aw*Aw - (2 * ((1 - sefflim)*Ned*e2 - (1.0 + sefflim)*fyd*As1*(d - a2))) / ((1.0 - sefflim)*fcd*b));
			if (xeff < xefflim) {
				As2 = 0.5*Asmin; /*KONIEC */
			}
			if ((xeff <= d) && (xeff >= xefflim)) {
				As2 = (Ned * e1 - fcd * b*xeff*(d - 0.5*xeff)) / (fyd*(d - a2)); /*KONIEC PRZYPADEK C3*/
			}
			if (xeff > d) {
				xeff = a2 + sqrt(a2*a2 - ((2 * (Ned*e2 - fyd * As1*(d - a2))) / (fcd*b)));
				if (xeff <= h) {
					As2 = (Ned*e1 - fcd * b*xeff*(d - 0.5*xeff)) / (fyd*(d - a2)); /* KONIEC PRZYPADEK C4*/
				}
				else {
					xeff = h;
					As2 = (Ned*e1 - fcd * b*h*(d - 0.5*h)) / (fyd*(d - a2));
					As1 = -((Ned*e2 + fcd * b*h*(d - 0.5*h)) / (fyd*(d - a2))); /*KONIEC MEKSYKASNKI PRZYPADEK XD*/
				}
			}
			/*W DALSZEJ CZESCI BEDZIE LICZONY RZECZYWISTY STOPIEN ZBROJENIA I ILOSC PRETOW*/ 
		}
	}

	return 0;
}