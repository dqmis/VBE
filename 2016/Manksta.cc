#include <iostream>
#include <fstream>
#include <string>

#define data "U2.txt"
#define rez "U2rez.txt"

struct pratimas {
	std::string pav; // Pratimo pavadinimas
	int kiek; // Pratimo atlikimo kiekis
};

void skaitymas(pratimas A[], int & n) {
	std::ifstream read(data);
	read >> n;
	for(int i = 0; i < n; i++) {
		read >> A[i].pav;
		read >> A[i].kiek;
	}
}

void trinimas(int & index, pratimas A[], int & n) { // Elemento trinimas is masyvo
	for(int i = index; i < n; i++) {
		A[i] = A[i+1];
	}
	n--;
	index--;
}

void vienodi(pratimas A[], int & n) { // Vienodu elementu masyze paieska
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(A[i].pav == A[j].pav) {
				A[i].kiek += A[j].kiek;
				trinimas(j, A, n);
			}
		}
	}
}

void rikiavimas(pratimas A[], int n) { // Rikiavimas
	pratimas F; // Laikinas kintamasis
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(A[j].kiek > A[i].kiek) {
				F = A[j];
				A[j] = A[i];
				A[i] = F;
			} else if(A[j].kiek == A[i].kiek) {
				if(A[j].pav < A[i].pav) {
					F = A[j];
					A[j] = A[i];
					A[i] = F;
				}
			}
		}
	}
}

void rasymas(pratimas A[], int n) {
	std::ofstream write(rez);
	for(int i = 0; i < n; i++) {
		write << A[i].pav << " " << A[i].kiek << std::endl;
	}
}

int main() {
	int n; // Pratimu kiekis
	pratimas A[100]; // Objektu masyvas (pratimai)
	skaitymas(A, n);
	vienodi(A, n);
	rikiavimas(A, n);
	rasymas(A, n);

	return 0;
}
