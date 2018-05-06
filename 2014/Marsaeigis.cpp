#include <fstream>
#include <string>

#define data "U2.txt"
#define rez "U2rez.txt"

struct Seka {
	std::string zinute;
	int jud; // Judesiu skaicius
	int komandos[30];

	void res() {
		zinute = "pasiektas tikslas";
	}
	void err() {
		zinute = "sekos pabaiga";
	}
};

struct Marsaeigis {
	int pradX, pradY; // Pradines marsaeigio koordinates;
	int finX, finY; // Keliones tikslo koordinates
};

void skaitymas(Marsaeigis &A, Seka B[], int &sekSk);
void judejimas(Marsaeigis A, Seka B[], int sekSk);
void judesys(Marsaeigis A, Seka &B);
void rasymas(Seka A[], int sekSk);

int main() {
	Marsaeigis Marsas;
	Seka Sekos[10];
	int sekSk; // Seku skaicius

	skaitymas(Marsas, Sekos, sekSk);
	judejimas(Marsas, Sekos, sekSk);
	rasymas(Sekos, sekSk);
	
	return 0;
}

void skaitymas(Marsaeigis &A, Seka B[], int &sekSk) {
	std::ifstream ifs(data);
	ifs >> A.pradX >> A.pradY;
	ifs >> A.finX >> A.finY;
	ifs >> sekSk;
	for (int i = 0; i < sekSk; i++) {
		ifs >> B[i].jud;
		for (int j = 0; j < B[i].jud; j++) {
			ifs >> B[i].komandos[j];
		}
	}
	ifs.close();
}

void judejimas(Marsaeigis A, Seka B[], int sekSk) {
	for (int i = 0; i < sekSk; i++)
		judesys(A, B[i]);
}

void judesys(Marsaeigis A, Seka &B) {
	int vyk = 0; // Ivykdytu judesiu skaicius
	for (int i = 0; i < B.jud; i++) {
		if (B.komandos[i] == 1)
			A.pradY++;
		else if (B.komandos[i] == 2)
			A.pradX++;
		else if (B.komandos[i] == 3)
			A.pradY--;
		else A.pradX--;
		vyk++;
		if (A.pradX == A.finX && A.pradY == A.finY) {
			B.res();
			B.jud = vyk;
			return;
		}
	}
	B.err();
}

void rasymas(Seka A[], int sekSk) {
	std::ofstream ofs(rez);
	for (int i = 0; i < sekSk; i++) {
		ofs << A[i].zinute << " ";
		for (int j = 0; j < A[i].jud; j++)
			ofs << A[i].komandos[j] << " ";
		ofs << A[i].jud << std::endl;
	}
	ofs.close();
}
