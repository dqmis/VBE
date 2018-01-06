#include <iostream>
#include <fstream>

#define data "U1.txt"
#define rez "U1rez.txt"

int sunkiausia() {
	int n; // Kupriniu kiekis
	int max; // Didziausios kuprines mase
	int a; // Kintamasis
	std::ifstream read(data);
	read >> n;
	read >> max;
	for(int i = 1; i < n; i++) {
		read >> a;
		if(a > max) {
			max = a;
		}
	}
	return max;
}

int kiek(int max) {
	int n; // Kupriniu kiekis
	int a; // Kintamasis
	int kiek = 0; // Lengvesniu kupriniu kiekis
	std::ifstream read(data);
	read >> n;
	for(int i = 0; i < n; i++) {
		read >> a;
		std::cout << a << std::endl;
		if(a*2 <= max) {
			kiek++;
		}
	}
	return kiek;
}

int main() {
	int max = sunkiausia();
	std::ofstream write(rez);
	write << max << " " << kiek(max);
	return 0;
}