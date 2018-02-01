#include <fstream>
#include <string>
#include <iostream>

#define data "U1.txt"
#define answ "U1rez.txt"

void i_des(std::string A, int sk[]); // Funkcija konvertuojanti spalvos koda i desimtaini

int main() {
    int il, pl; // Piesinio ilgis ir plotis
    int sk[6]; // Spalvu kodu masyvas
    std::string spalv; // Spalvos kodas
    std::ifstream read(data);
    std::ofstream write(answ);
    read >> il >> pl;
    for(int i = 0; i < il; i++) {
        for(int j = 0; j < pl; j++) {
            read >> spalv;
            i_des(spalv, sk);
            for(int z = 0; z < 6; z +=2) {
                write << sk[z];
                if(z + 2 != 6) {
                    write << " ";
                }
            }
            if(j + 1 != pl) {
                write << ";";
            }
        }
        write << std::endl;
    }
    read.close();
    write.close();

    return 0;
}

void i_des(std::string A, int sk[]) {
    int sk1, sk2;
    char sim[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for(int i = 0; i < 6; i+=2) {
        for(int j = 0; j < 16; j++) {
            if(A[i] == sim[j]) {
                sk1 = j * 16;
            } if (A[i+1] == sim[j]) {
                sk2 = j;
            }
        }
       sk[i] = sk1 + sk2;
    }
}
