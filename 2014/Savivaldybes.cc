#include <iostream>
#include <fstream>
#include <string>

#define data "U2.txt"
#define answ "U2rez.txt"

struct Apskritis {
	std::string pav;
	int miest = 1; // Miestu skaicius
	int mok; // Mokyklu skaicius
};

void skait(Apskritis A[], int & n) {
	std::ifstream read(data);
	read >> n;
	for(int i = 0; i < n; i++) {
		read >> A[i].pav >> A[i].mok;
		read >> A[i].pav;
	} read.close();
}

void trinimas(Apskritis A[], int index, int & n) {
	for(int i = index; i < n; i++) {
		A[i] = A[i + 1];
	} n--;
}

void sujung(Apskritis A[], int & n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(A[i].pav == A[j].pav) {
				A[i].miest++;
				if(A[i].mok < A[j].mok) {
					A[i].mok = A[j].mok;
				}
				trinimas(A, j, n);
			}
		}
	}
}

void rasymas(Apskritis A[], int n) {
	std::ofstream write(answ);
	write << n << std::endl;
	for(int i = 0; i < n; i++) {
		write << A[i].pav << " " << A[i].miest << " " << A[i].mok << std::endl;
	} write.close();
}

int main() {
	Apskritis Apskritys[60];
	int n; // Apskriciu kiekis

	skait(Apskritys, n); // Nuskaiymas
	sujung(Apskritys, n); // Ieskojimas bendru apskriciu
	rasymas(Apskritys, n); // Rezultatu rasymas i faila

	return 0;
}