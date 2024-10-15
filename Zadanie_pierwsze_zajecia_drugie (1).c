#include <stdio.h>
#include <math.h>    


void print_ilosc_pieniedzy(float ilosc_pieniedzy_ady, float ilosc_pieniedzy_anny) {
   printf("Ilość pieniędzy Ady: %0.2f\n", ilosc_pieniedzy_ady);
   printf("Ilość pieniędzy Anny: %0.2f\n", ilosc_pieniedzy_anny);
}


int main() {
    int okres_rozliczeniowy = 30;
    float wzrost_procentowy = 0.05; 
    float gotowka = 5.00;
    float ilosc_pieniedzy_ady = 0.00;
    float ilosc_pieniedzy_anny = 0.00;
    int dzien = 1;

    while (dzien <= okres_rozliczeniowy) {
        if (dzien%2 == 1) {
            ilosc_pieniedzy_ady = ilosc_pieniedzy_ady + gotowka;
        }
        if (dzien%2 == 0) {
            ilosc_pieniedzy_anny = ilosc_pieniedzy_anny + gotowka;
        }
        printf("Dzień %d\n", dzien);
        ilosc_pieniedzy_ady = ilosc_pieniedzy_ady + (ilosc_pieniedzy_ady*wzrost_procentowy);
        ilosc_pieniedzy_anny = ilosc_pieniedzy_anny + (ilosc_pieniedzy_anny*wzrost_procentowy);
        print_ilosc_pieniedzy(ilosc_pieniedzy_ady, ilosc_pieniedzy_anny);
        dzien++;
    }
    printf("-----------------finalnie-----------\n");
    print_ilosc_pieniedzy(ilosc_pieniedzy_ady, ilosc_pieniedzy_anny);
    return 0;
}
