#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    // Poproś użytkownika o podanie liczby wartości
    printf("Podaj liczbę wartości do wprowadzenia: ");
    scanf("%d", &size);

    // Alokacja pamięci dla tablicy
    int *bufor = malloc(size * sizeof(int));
    if (bufor == NULL) {
        printf("Błąd alokacji pamięci\n");
        return 1;
    }

    // Wprowadzenie wartości
    for (int i = 0; i < size; i++) {
        printf("Wprowadź wartość %d: ", i + 1);
        scanf("%d", &bufor[i]);
    }

    // Wypisanie długości i zawartości tablicy
    printf("Długość tablicy: %d\n", size);
    printf("Zawartość tablicy: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", bufor[i]);
    }
    printf("\n");

    free(bufor); // Zwolnienie pamięci
    return 0;
}
