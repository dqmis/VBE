#include <iostream>
#include <algorithm>
#include <fstream>

#define data "U2.txt"
#define answ "U2rez.txt"

struct staciakampis {
	int x; // Staciakampio x koordinate
	int y; // Staciakampio y koordinate
	int dx; // Staciakampio plotis
	int dy; // Staciakampio ilgis
	int R, G, B; // Spalvos
};

void skaitymas(staciakampis A[], int & n) {
	std::ifstream read(data);
	read >> n;
	for(int i = 0; i < n; i++) {
		read >> A[i].x >> A[i].y;
		read >> A[i].dx >> A[i].dy;
		read >> A[i].R >> A[i].G >> A[i].B;
	}
	read.close();
}

void uzdejimas(staciakampis A[], int laukas[][100], int n, int & max, int & may) {
	for(int i = 0; i < n; i++) {
		for(int j = A[i].y; j < A[i].dy + A[i].y; j++) {
			for(int z = A[i].x; z < A[i].dx + A[i].x; z++) {
				if(A[i].y + A[i].dy > max) {
					max = A[i].y + A[i].dy;
				}
				if(A[i].x + A[i].dx > may) {
					may = A[i].x + A[i].dx;
				}
				laukas[j][z] = i;	
			}
		}
	}
}

void spausdinimas(staciakampis A[], int laukas[][100], int n, int max, int may) {
	std::ofstream write(answ);
	write << may << " " <<  max << std::endl;
	for(int i = 0; i < max; i++) {
		for(int j = 0; j < may; j++) {
			if(laukas[i][j] == -1) {
				write << "255 255 255" << std::endl;
			} else {
				write << A[laukas[i][j]].R << " " << A[laukas[i][j]].G << " " << A[laukas[i][j]].B << std::endl;
			}
		}
	}
	write.close();
}

int main() {
	staciakampis staciakampiai[100]; // Staciakampiu masyvas
	int laukas[100][100]; // Laukas, kuriame ezistuoja stacikampiai
	int n; // Staciakmpiu skaicius
	int max = 0; // Piesinio ilgis;
	int may = 0; // Piesinio aukstis;
	
	for(int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			laukas[i][j] = -1; // Uzpildome masyva -1, tam, kad galetumeme priskirti 0 velesnese operacijose
		}
	}

	skaitymas(staciakampiai, n);
	uzdejimas(staciakampiai, laukas, n, max, may);
	spausdinimas(staciakampiai, laukas, n, max, may);

	return 0;
}