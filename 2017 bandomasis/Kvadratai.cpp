#include <fstream>
#include <iostream>

#define data "U2.txt"
#define answ "U2rez.txt"

struct kvad {
	int R; // Spalvos
	int G;
	int B;
	int x, y; // Kvadarato koordinates
	int a; // ilgis
};

void uzdejimas(int laukas[][100], kvad A[], int n, int & lMax, int & aMax);

int main() {
	int n; // kvadaratu kiekis
	int lMax = 0;
	int aMax = 0;
	kvad kvadratai[100];
	int laukas[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			laukas[i][j] = -1;
		}
	}
	std::ifstream read(data);
	read >> n;
	for (int i = 0; i < n; i++) {
		read >> kvadratai[i].x >> kvadratai[i].y >> kvadratai[i].a >> kvadratai[i].R >> kvadratai[i].G >> kvadratai[i].B;
	}
	read.close();

	uzdejimas(laukas, kvadratai, n, lMax, aMax);

	std::ofstream write(answ);
	write << aMax << " " << lMax << std::endl;
	for (int i = 0; i < aMax; i++) {
		for (int j = 0; j < lMax; j++) {
			if (laukas[j][i] == -1) {
				write << "255 255 255" << std::endl;
			}
			else {
				write << kvadratai[laukas[i][j]].R << " " << kvadratai[laukas[i][j]].G << " " << kvadratai[laukas[i][j]].B << std::endl;
			}
		}
	}
	write.close();
	return 0;
}

void uzdejimas(int laukas[][100], kvad A[], int n, int & lMax, int & aMax) {
	for (int i = 0; i < n; i++) {
		for (int j = A[i].x; j < A[i].x + A[i].a; j++) {
			for (int z = A[i].y; z < A[i].y + A[i].a; z++) {
				if (laukas[z][j] == -1) {
					laukas[z][j] = i;
				}
				if (A[i].y + A[i].a > lMax) {
					lMax = A[i].y + A[i].a;
				}
				if (A[i].x + A[i].a > aMax) {
					aMax = A[i].x + A[i].a;
				}
			}
		}
	}
}

