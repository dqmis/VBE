#include <iostream>
#include <fstream>
#include <algorithm>

#define data "U1.txt"
#define answ "U1rez.txt"

int main() {
    int n; // Uzsakovu skaicius
    int s; // Dienos limitas
    int x, y; // Kordinates
    int km = 0; // Nuvaziuotas atstumas
    int ap = 0; // Aptarnauti klientai
    int ats; // Atstumas reikalingas nukeliauti iki picerijos

    std::ifstream read(data);
    read >> n >> s;
    for(int i = 0; i < n; i++) {
        read >> x >> y;
        ats = std::abs(2*x) + std::abs(y*2);
        if(s >= 0) {
            km += ats;
            ap++;
            s -= ats;
        }
    }
    read.close();

    std::ofstream write(answ);
    write << n - ap << " " << km;
    write.close();
    
    return 0;
}