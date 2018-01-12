#include <iostream>
#include <fstream>
#include <string>

#define data "U2.txt"
#define answ "U2rez.txt"

struct Avis {
	std::string vardas;
	std::string DNR;
	int kof = -1;
};

void skaitymas(Avis A[], int & n, int & d, int & t) {
	std::ifstream read(data);
	read >> n >> d >> t;
	for(int i = 0; i < n; i++) {
		read >> A[i].vardas;
		read >> A[i].DNR;
	}
	read.close();
}

void kofSk(Avis A[], int n, int d, int t) {
	for(int i = 0; i < n; i++) {
		if(i != t - 1) {
			A[i].kof = 0;
			for(int j = 0; j < d; j++) {
				if(A[t - 1].DNR[j] == A[i].DNR[j]) {
					A[i].kof++;
				}
			}
		}
	}
}

void rik(Avis A[], int n) {
	Avis F; // Kintamasis reikalingas rikiavimui
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(A[i].kof < A[j].kof) {
				F = A[i];
				A[i] = A[j];
				A[j] = F;
			} else if(A[i].kof == A[j].kof) {
					if(A[i].vardas > A[j].vardas) {
						F = A[i];
						A[i] = A[j];
						A[j] = F;
					}
				}
		}
	}
}

void rasymas(Avis A[], int n) {
	std::ofstream write(answ);
	write << A[n - 1].vardas << std::endl;
	for(int i = 0; i < n - 1; i++) {
		write << A[i].vardas << " " << A[i].kof << std::endl;
	}
	write.close();
}

int main () {
	Avis Avys[20];
	int n; // Aviu kiekis
	int d; // DNR ilgis
	int t; // Tiriamos avies numeris
	skaitymas(Avys, n, d, t);
	kofSk(Avys, n, d, t);
	rik(Avys, n);
	rasymas(Avys, n);

	return 0;
}