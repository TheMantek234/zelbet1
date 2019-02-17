#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main() {

	double xeff, Ned, fyd, As2, As1, fcd, b,e1,e2,a1,a2, Mrd, Med,d, xefflim, sefflim, h;
	xeff = (Ned - fyd * As2 + fyd * As1) / (fcd*b);
	if (xeff < 2.0 *a2) {
		xeff = 2.0 * a2;
		Med = Ned * e2;
		Mrd = fyd * As1*(d - a2);  /*KONIEC PRZYPADEK 1*/
	}
	else if ((xeff > 2 * a2) && (xeff <= xefflim)) {
		Med = Ned * e1;
		Mrd = fcd * b*xeff*(d - 0.5*xeff) + fyd * As2*(d - a2); /*KONIEC PRZYPADEK 2*/
	}
	else {
		xeff = d * (((Ned - fyd * As2 - fyd * As1)*(1 - sefflim) + 2 * fyd*As1) / (fcd*b*d*(1 - sefflim) + 2 * fyd*As1));
		if ((xeff > xefflim) && (xeff <= d)) {
			Med = Ned * e1;
			Mrd = fcd * b*xeff*(d - 0.5*xeff) + fyd * As2*(d - a2); /* KONIEC PRZYPADEK 3*/
		}
		else if (xeff > d){
			xeff = (Ned - fyd * As2 - fyd * As1) / (fcd*b);
			if ((xeff > d) && (xeff <= h)) {
				Med = Ned * e1;
				Mrd = fcd * b*xeff*(d - 0.5*xeff) + fyd * As2*(d - a2); /*KONIEC PRZYPADEK 4*/
			}
			else {
				cout << "GAUDE MATER POLONIA przekroj zle ";
 			}
		}
	}



	return 0;
}