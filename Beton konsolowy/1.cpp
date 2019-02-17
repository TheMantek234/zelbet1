/*
Skip to content

Pull requests
Issues
Marketplace
Explore

@TheMantek234

0
0

0

TheMantek234 / zelbet1
Code
Issues 0
Pull requests 0
Projects 0
Wiki
Insights
Settings
zelbet1 / Beton konsolowy / 1.cpp
6887be9 3 hours ago
@TheMantek234 TheMantek234 Update 1.cpp
147 lines(127 sloc) 3.56 KB
*/
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include "funkcje.h"

using namespace std;

int main()
{
	double lcol = 0.0, Beta = 0.0, b = 0.0, h = 0.0, Ned = 0.0, M0ed = 0.0, stosm = 0.0, RH = 0.0, t0 = 0.0, bufor = 0.0, cmind = 0.0;
	string klesp, klbet, klstl;
	/*cout << "Podaj wysokosc slupa: ";
	cin >> lcol; cout << endl;
	cout << "Podaj wspolczynnik wyboczeniowy Beta: ";
	cin >> Beta; cout << endl;
	cout << "Podaj przekroj slupa b h: " << endl;
	cin >> b >> h; cout << endl;
	cout << "Podaj Ned: " << endl;
	cin >> Ned; cout << endl;
	cout << "Podaj M0ed: " << endl;
	cin >> M0ed; cout << endl;
	cout << "Podaj stosunek momentow zginajacych: " << endl;
	cin >> stosm; cout << endl;
	cout << "Podaj wilgotnosc wzgledna srodowiska: " << endl;
	cin >> RH; cout << endl;
	cout << "Podaj czas przylozenia obciazenia: " << endl;
	cin >> t0; cout << endl;*/

	//-------------------------------------------------------------

	lcol = 5.0;
	Beta = 1.8;
	b = 0.3;
	h = 0.5;
	Ned = 800.0;
	M0ed = 265.0;
	stosm = 0.6;
	klesp = "XC1";
	RH = 50.0;
	klbet = "C20/25";
	klstl = "B500B";
	t0 = 60.0;


	/*--------------------------------------------------------------*/

	double fck = 0.0, fcd = 0.0, fcm = 0.0, Ecm = 0.0, Ecd = 0.0, ec2 = 0.0, ecu2 = 0.0, fyk = 0.0, fyd = 0.0, Es = 0.0;
	double eyd = 0.0;
	// KLASA EKSPOZYCJI

	do {
		if (cmind == -1.0)
		{
			cout << "Niepoprawna klasa" << endl;
		}
		cout << "Podaj klase ekspozycji: " << endl;
		cin >> klesp; cout << endl;
		cmind = get_klesp(klesp);

	} while (cmind == -1.0);



	// KLASA Betonu -----------------------------

	do {
		if (fck == -1.0)
		{
			cout << "Niepoprawna klasa" << endl;
		}
		cout << "Podaj klase betonu: " << endl;
		cin >> klbet; cout << endl;
		fck = get_klbet(klbet, &Ecm, &ec2, &ecu2);

	} while (fck == -1.0);
	fcd = bet1(fck, Ecm, &fcm, &Ecd);

	// KLASA Stali ---------------------------

	do {
		if (fyk == -1.0)
		{
			cout << "Niepoprawna klasa" << endl;
		}
		cout << "Podaj gatunek stali: " << endl;
		cin >> klstl; cout << endl;
		fyk = get_klstl(klstl, &Es);

	} while (fyk == -1.0);
	eyd = stl1(fyk, Es, &fyd);
	// POCZATEK OBLICZEN
	// Koncowyy i efektywny wspolczynnik pelzania
	double zefflim = 0.8*ecu2 / (ecu2 - eyd);
	double Ac = b * h;
	double u = 2.0 * (b + h);
	double h0 = 2.0*Ac / u;
	double fRH = 0.0;
	if (fcm <= 35.0)
	{
		fRH = 1 + (((1 - (RH / 100.0)) / (0.1*cbrt(h0*1000.0))));

	}

	double Betafcm = 16.8 / sqrt(fcm);
	double Betat0 = 1.0 / (0.1 + pow(t0, 0.2));
	double F0 = fRH * Betat0 * Betafcm;
	double fef = F0 * stosm;

	// OBLICZENIA WYTRZYMALOSCIOWE

	double l0 = Beta * lcol;
	double a1 = 0.0, a2 = 0.0, d = 0.0, xefflim = 0;
	a1 = 0.04; a2 = a1;
	d = h - a1;
	xefflim = d * zefflim;
	// SMUKLOSC
	double Ic = b * h*h*h / 12;
	double i = sqrt(Ic / Ac);
	double lamb = l0 / i;
	double A, B, C, n;
	A = 1.0 / (1.0 + 0.2*fef);
	B = 1.1;
	C = 0.7;
	n = Ned / (fcd * 1000.0 * Ac);
	double lamblim = 20.0 * A*B*C / sqrt(n);
	double e0 = 0.0, ei = 0.0, eta = 1.0, rob, etot;
	double k1 = 0, k2 = 0, Kc = 0, Is = 0, EI = 0, NB = 0;
	e0 = M0ed / Ned;
	bufor = max(l0 / 400.0, h / 30.0);
	ei = max(bufor, 0.02);
	if (lamb > lamblim)
	{
		/*cout << "Element jest smukly, podaj zalozony stopien zbrojenia: ";
		cin >> rob; cout << endl;*/
		rob = 0.0218;

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
		/*cout << "Element jest krepy, podaj zalozony stopien zbrojenia: ";
		cin >> rob; cout << endl;*/
		rob = 0.015;
		eta = 1.0;
		etot = eta * (e0 + ei);
	}
	double e1 = 0.0, e2 = 0.0, Asmin = 0.0, As2 = 0.0, n2 = 0.0, fi2 = 0.0, n1 = 0.0, fi1 = 0.0, Mrd = 0.0, Med = 0.0;
	double xeff = 0.0, As1 = 0.0, rop = 0.0, Isp = 0.0, EIp = 0.0, NBp = 0.0, etap = 0.0, etotp = 0.0, Medp = 0.0, propmim = 0.0;
	bool min1 = false, min2 = false;
	Med = Ned * etot;
	e1 = etot + 0.5*h - a1;
	e2 = etot - 0.5*h + a2;
	Asmin = max((0.1*Ned) / (fyd * 1000), 0.002*b*h);

	wymiar(As1, As2, xeff, a2, h, Ned, e1, e2, fcd, b, xefflim, d, Asmin, fyd, zefflim, min1, min2);
	wyborpret(As1, As2, n1, n2, fi1, fi2, min1, min2);

	/*ROZMIESZCZANIE PRETOW WORK IN PROGRESS HEHE XD */

	double cmin = 0.0, dcdur = 0.0, dcdurs = 0.0, dcdura = 0.0, cminb = 0.0;
	cminb = 20.0;
	cmin = max(max(cminb, 10.0), cmind - dcdur - dcdura);

	/*dopisac rozmieszczenie do konca */

	/*KONCOWE OBLICZENIA*/

	rop = (As1 + As2) / (b*d);
	Isp = As1 * pow((0.5*h - a1), 2.0) + As2 * pow((0.5*h - a2), 2.0);
	EIp = 0.995678*(Kc * Ecd*Ic * 1000 + Es * 1000 * Isp);
	NBp = ((3.14*3.14) / (l0*l0))*EIp * 1000;
	etap = 1 + ((1.23) / ((NBp / Ned) - 1.0));
	etotp = etap * (e0 + ei);
	e1 = etotp + 0.5*h - a1;
	e2 = etotp - 0.5*h + a2;
	Medp = etotp * Ned;
	propmim = etotp / etot;
	cout << propmim << endl;

	nosnosc(xeff, Ned, fyd, As2, As1, fcd, b, e1, e2, a1, a2, Mrd, Med, d, xefflim, zefflim, h);

	cout << Mrd << endl;

	system("PAUSE");
	return 0;
}
/*
© 2019 GitHub, Inc.
Terms
Privacy
Security
Status
Help

Contact GitHub
Pricing
API
Training
Blog
About

Press h to open a hovercard with more details.
*/
