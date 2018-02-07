#include <fstream>

#define data "U1.txt"
#define answ "U1rez.txt"

struct Mokinys {
	char vardas[20];
	int pazymiai[15];
	double vidurkis;
};

void vidurkis(Mokinys & A, int n) { // n - pazymiu kiekis
	A.vidurkis = 0; // pazymiu suma
	for(int i = 0; i < n; i++) {
		A.vidurkis += A.pazymiai[i];
	}
	A.vidurkis = A.vidurkis / n;
}

void skaitymas(Mokinys A[], int & n, int & p, double & v) {
	std::ifstream read(data);
	read >> n >> p >> v;
	read.ignore();
	for(int i = 0; i < n; i++) {
		read.get(A[i].vardas, 20);
		for(int j = 0; j < p; j++) {
			read >> A[i].pazymiai[j];
		}
		vidurkis(A[i], p);
		read.ignore();
	}
	read.close();
}

int pirm(Mokinys A[], int n, double v) { // n - mokiniu skaicius
	int sk = 0; // pirmunu skaicius
	for(int i = 0; i < n; i++) {
		if(A[i].vidurkis >= v) {
			sk++;
		}
	}
	return sk;
}

void irasymas(Mokinys A[], int n, double v) {
	std::ofstream write(answ);
	for(int i = 0; i < n; i++) {
		write << A[i].vardas << " " << A[i].vidurkis << std::endl;
	}
	write << pirm(A, n, v) << std::endl;
	write.close();
}

int main() {
	int n; // mokiniu kiekis
	int p; // pazymiu kiekis
	double v;	// vidurkio reikalavimas
	Mokinys Mokiniai[15];

	skaitymas(Mokiniai, n, p, v);
	irasymas(Mokiniai, n, v);

	return 0;
}