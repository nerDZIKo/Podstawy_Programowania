#include <stdio.h>

int main() {
    int tablica[] = {2147483647, 20, 30, 40, 50, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int dlugosc = sizeof(tablica) / sizeof(tablica[0]);
    printf("Wartości w Bajtach! :)\n");
    printf("%d \n",sizeof(tablica));
    printf("%d \n",sizeof(tablica[0]));
    // Wyświetlenie długości
    printf("Długość tablicy: %d\n", dlugosc);

    return 0;
}
