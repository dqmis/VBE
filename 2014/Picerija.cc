#include <iostream>
#include <fstream>

#define data "U1.txt"
#define answ "U1rez.txt"

int main() {
    int n; // Uzsakovu skaicius
    int s; // Dienos limitas
    int x; // Kordinate
    int km = 0; // Nuvaziuotas atstumas
    int ap; // Aptarnauti klientai
    std::ifstream read(data);
    read >> n >> s;
    while (s > 0) {
       read >> x;
       s -= 2*x;
       read >> x;
       s -= 2*x;
       if(s >= 0) {
           ap++;
       }
    }
    std::cout << n - ap;
    return 0;
}