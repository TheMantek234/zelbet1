#include <iostream>

using namespace std;

int main() {
	double As1, As2, fi1, fi2, n1, n2;
		char d1 = 'f', d2 = 'f';
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
		As1 = (n1 * 3.14*fi1*fi1) / 4.0;
		if (min == false) {
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



	return 0;
}