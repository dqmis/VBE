#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

#define data "U1.txt"
#define answ "U1rez.txt"

int main() {
	int n; // Imoniu skaicius
	int lim; // Dienos limitas
	int km = 0; // Nuvaziuotu km skaicius
	int im = 0; // Aptarnautu imoniu skaicius
	std::string pav; // Imones pavadinimas
	std::string gPav; // Paskutines imones pavadinimas
	int ats; // Atstumas iki imones
	int x, y; // Imones koordinates

	std::ifstream read(data);
	read >> n >> lim;
	for(int i = 0; i < n; i++) {
		read >> pav >> x >> y;
		ats = 2*(std::abs(x) + std::abs(y));
		if(lim - ats >= 0) {
			km += ats;
			lim -= ats;
			 im++;
			gPav = pav;
		}
	}
	read.close();

	std::ofstream write(answ);
	write << im << " " << km << " " << gPav;
	write.close();

	return 0;
}