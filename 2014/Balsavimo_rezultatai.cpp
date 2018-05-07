#include <iostream>
#include <fstream>

#define data "U1.txt"
#define answ "U1rez.txt"

void task_Skyr(int A[], int B[]);
int laimetojas(int A[], int B[]);
int didziausiTks(int A[]);
void dir_Plius(int A[], int B[]);

int main() {
	int n; // Skyriu skaicius
	int logTskGal[3] = { 0 }; // Galutininai logotipu taskai
	int logTskSum[3] = { 0 }; // Logotipu taskai skyriuje susumuoti
	int logTskSk[3]; // Logotipu taskai skyriuje
	int dirTsk[3]; // Direktoriaus skiriami taskai

	std::ifstream ifs(data);
	ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >> logTskSk[0] >> logTskSk[1] >> logTskSk[2];
		for (int j = 0; j < 3; j++)
			logTskSum[j] += logTskSk[j];
		task_Skyr(logTskSk, logTskGal);
	}
	ifs >> dirTsk[0] >> dirTsk[1] >> dirTsk[2];
	ifs.close();

	std::ofstream ofs(answ);
	ofs << logTskSum[0] << " " << logTskSum[1] << " " << logTskSum[2] << std::endl;
	ofs << logTskGal[0] << " " << logTskGal[1] << " " << logTskGal[2] << std::endl;
	ofs << laimetojas(logTskGal, dirTsk);
	ofs.close();
	
	return 0;
}

void task_Skyr(int A[], int B[]) {
	if (A[0] == A[1] && A[1] == A[2]) {
		return;
	} else if (A[0] > A[1] && A[0] > A[2]) {
		B[0] += 4;
	} else if (A[1] > A[0] && A[1] > A[2]) {
		B[1] += 4;
	} else if (A[2] > A[1] && A[2] > A[0]) {
		B[2] += 4;
	} else if (A[0] == A[1]) {
		B[0] += 2;
		B[1] += 2;
	} else if (A[0] == A[2]) {
		B[0] += 2;
		B[2] += 2;
	} else if (A[2] == A[1]) {
		B[2] += 2;
		B[1] += 2;
	}
}

int laimetojas(int A[], int B[]) {
	if (A[0] == A[1] && A[1] == A[2]) {
		dir_Plius(A, B);
		return didziausiTks(A);
	} else if (A[0] == A[1]) {
		dir_Plius(A, B);
		return didziausiTks(A);
	} else if (A[0] == A[2]) {
		dir_Plius(A, B);
		return didziausiTks(A);
	} else if (A[2] == A[1]) {
		dir_Plius(A, B);
		return didziausiTks(A);
	} else return didziausiTks(A);
}

int didziausiTks(int A[]) {
	int max = A[0];
	int idx = 0;
	for (int i = 1; i < 3; i++) {
		if (A[i] > max) {
			max = A[i];
			idx = i;
		}
	}
	return idx + 1;
}

void dir_Plius(int A[], int B[]) {
	for (int i = 0; i < 3; i++)
		A[i] += B[i];
}
