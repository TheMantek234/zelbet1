#include "BetonLicz.h"

void BetonLicz::PelzLicz()
{
	// POCZATEK OBLICZEN
// Koncowyy i efektywny wspolczynnik pelzania
	zefflim = 0.8*ecu2 / (ecu2 - eyd);
	Ac = b * h;
	u = 2.0 * (b + h);
	h0 = 2.0*Ac / u;
	fRH = 0.0;
	if (fcm <= 35.0)
	{
		fRH = 1 + (((1 - (RH / 100.0)) / (0.1*cbrt(h0*1000.0))));
		/*DOPISAC JEZELI NIE*/
	}

	Betafcm = 16.8 / sqrt(fcm);
	Betat0 = 1.0 / (0.1 + pow(t0, 0.2));
	F0 = fRH * Betat0 * Betafcm;
	fef = F0 * stosm;

	// OBLICZENIA WYTRZYMALOSCIOWE

	l0 = Beta * lcol;

	a1 = 0.04; a2 = a1;
	d = h - a1;
	xefflim = d * zefflim;
	// SMUKLOSC
	Ic = b * h*h*h / 12;
	i = sqrt(Ic / Ac);
	lamb = l0 / i;
    A = 1.0 / (1.0 + 0.2*fef);
	B = 1.1;
	C = 0.7;
	n = Ned / (fcd * 1000.0 * Ac);
	lamblim = 20.0 * A*B*C / sqrt(n);
    e0 = M0ed / Ned;
	bufor = std::max(l0 / 400.0, h / 30.0);
	ei = std::max(bufor, 0.02);
	smuklosc = (lamb > lamblim);
}

void BetonLicz::liczsmukly()
{
	if (smuklosc == true)
	{
		k1 = sqrt(fck / 20.0);
		k2 = n * lamb / 170.0;
		if (k2 >= 0.2) {
			k2 = 0.2;
		}
		Kc = (k1*k2) / (1 + fef);
		Is = rob * b*d*pow((0.5*h - a1), 2.0);
		EI = (Kc * Ecd*Ic + Es * Is) * 1000;
		NB = ((3.14*3.14) / (l0*l0))*EI * 1000.0;
		eta = 1 + ((1.23) / (NB / Ned - 1.0));
		etot = eta * (e0 + ei);


	}
	else
	{
		eta = 1.0;
		etot = eta * (e0 + ei);

	}

	Medp = etotp * Ned;
}

void BetonLicz::wtracenie()
{
	Med = Ned * etot;
	e1 = etot + 0.5*h - a1;
	e2 = etot - 0.5*h + a2;
	Asmin = std::max((0.1*Ned) / (fyd * 1000), 0.002*b*h);
}

void BetonLicz::wymiar()
{
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
			double Aw = a2 - (2.0*fyd*1000.0*As1*(d - a2)) / ((1.0 - zefflim)*fcd*1000.0*b*d);
			xeff = Aw + sqrt(Aw*Aw - (2 * ((1 - zefflim)*Ned*e2 - (1.0 + zefflim)*fyd*1000.0*As1*(d - a2))) / ((1.0 - zefflim)*fcd*1000.0*b));
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



void BetonLicz::ostobliczenia()
{
	rop = (As1 + As2) / (b*d);
	Isp = As1 * pow((0.5*h - a1), 2.0) + As2 * pow((0.5*h - a2), 2.0);
	EIp = 0.995678*(Kc * Ecd*Ic * 1000 + Es * 1000 * Isp);
	NBp = ((3.14*3.14) / (l0*l0))*EIp * 1000;
	etap = 1 + ((1.23) / ((NBp / Ned) - 1.0));
	etotp = etap * (e0 + ei);
	propmim = etotp / etot;
	e1 = etotp + 0.5*h - a1;
	e2 = etotp - 0.5*h + a2;
	if (smuklosc == false) {
		e1 = etot + 0.5*h - a1;
		e2 = etot - 0.5*h + a2;
	}
}

void BetonLicz::nosnosc()
{
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
		xeff = d * (((Ned - fyd * 1000.0 * As2 - fyd * 1000.0 * As1)*(1 - zefflim) + 2 * fyd*1000.0*As1) / (fcd*1000.0*b*d*(1 - zefflim) + 2 * fyd*1000.0*As1));
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
				gmp = true;
			}
		}
	}


}
