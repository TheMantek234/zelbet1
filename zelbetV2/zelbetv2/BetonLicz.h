#pragma once
#include <cmath>
#include <algorithm>

class BetonLicz final
{
public:
	double lcol = 0.0, Beta = 0.0, b = 0.0, h = 0.0, Ned = 0.0, M0ed = 0.0, stosm = 0.0, RH = 0.0, t0 = 0.0, bufor = 0.0, cmind = 0.0;
	double fck = 0.0, fcd = 0.0, fcm = 0.0, Ecm = 0.0, Ecd = 0.0, ec2 = 0.0, ecu2 = 0.0, fyk = 0.0, fyd = 0.0, Es = 0.0, eyd = 0.0;
	double zefflim = 0.0, Ac = 0.0, u = 0.0, h0 = 0.0, fRH = 0.0, Betafcm = 0.0, Betat0 = 0.0, F0 = 0.0, fef = 0.0, l0 = 0.0, a1 = 0.0, Ic = 0.0, i = 0.0, lamb = 0.0, A = 0.0, B = 0.0, C = 0.0, n = 0.0;
	double lamblim = 0.0;
	double e0 = 0.0, ei = 0.0, eta = 1.0, rob, etot;
	double k1 = 0, k2 = 0, Kc = 0, Is = 0, EI = 0, NB = 0;
	double e1 = 0.0, e2 = 0.0, Asmin = 0.0, As2 = 0.0, n2req = 0.0, fi2 = 0.0, n1req = 0.0, fi1 = 0.0, Mrd = 0.0, Med = 0.0, n2prov=0.0, n1prov=0.0;
	double xeff = 0.0, As1 = 0.0, rop = 0.0, Isp = 0.0, EIp = 0.0, NBp = 0.0, etap = 0.0, etotp = 0.0, Medp = 0.0, propmim = 0.0;
	bool min1 = false, min2 = false, smuklosc = false, gmp = false;
	double cmin = 0.0, dcdur = 0.0, dcdurs = 0.0, dcdura = 0.0, cminb = 0.0;
    double a2 = 0.0, d = 0.0, xefflim = 0;

    void bet1()
    {
        fcm = fck + 8.0;
        Ecd = Ecm / 1.2;
        fcd = fck / 1.4;
    }
    void stl1()
    {
        fyd = fyk / 1.15;
        eyd = -(fyd) / Es * 0.001;
    }


	void PelzLicz();
	void liczsmukly();
	void wtracenie();
	
	/*WYMIAR WYBOR PRET*/
	void wymiar();
	void wyborpret1();
	void wyborpret2();


	/*ROZMIESZCZENIE PRETOW*/
	void rozmieszczenie()
	{
		cminb = 20.0;
		cmin = std::max(std::max(cminb, 10.0), cmind - dcdur - dcdura);
	}
	void ostobliczenia();
	
	void nosnosc();
	
};
