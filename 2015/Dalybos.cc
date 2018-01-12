#include <iostream>
#include <fstream>

#define data "U1.txt"
#define answ "U1rez.txt"

void slyv(int A[], int B[]) { // Slyvu valgymo skaiciavimas
	int k; // Kintamas reikalingas ciklui
	for(int i = 0; i < 10; i++) {
		k = i + 1;
		while(B[i] > 0) {
			A[k] += 1;
			B[i] -= 1;
			k++;
		}
	}
}

int main() {
	int A[20] = { 0 }; // Masyvas, kuriame skacius kiek zmogus suvalge
	int B[10]; // Masyvas, kuriame slyvu skaicius likus po mergaiciu valgymo

	std::ifstream read(data);
	for(int i = 0; i < 10; i++) {
		read >> A[i];
		B[i] = 10 - A[i];
	}
	read.close();

	slyv(A, B);

	std::ofstream write(answ);
	for(int i = 0; i < 20; i++) {
		write << A[i] << " ";
	}
	write.close();
	
	return 0;
}
