#include <fstream>
#include <string>

#define data "U1.txt"
#define answ "U1rez.txt"

std::string to_hex(int a) {
	std::string s;
	char sym[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	s += sym[a/16];
	s += sym[a%16];
	return s;
}

int main() {
	int l; // ilgis
	int h; // aukstis
	int a; // nuskaitomas skaicius

	std::ifstream read(data);
	std::ofstream write(answ);
	read >> l >> h;
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < h; j++) {
			for(int z = 0; z < 3; z++) {
				read >> a;
				write << to_hex(a);
			}
			if(j + 1 != h) {
				write << ';';
			}
		} write << std::endl;
	}
	read.close();
	write.close();

	return 0;
}