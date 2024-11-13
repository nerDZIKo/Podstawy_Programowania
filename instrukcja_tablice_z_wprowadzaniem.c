#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Podaj liczbę wartości do wprowadzenia: ");
    scanf("%d", &size);

    int *bufor = malloc(size * sizeof(int));
    if (bufor == NULL) {
        printf("Błąd alokacji pamięci\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Wprowadź wartość %d: ", i + 1);
        scanf("%d", &bufor[i]);
    }

    printf("Długość tablicy: %d\n", size);
    printf("Zawartość tablicy: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", bufor[i]);
    }
    printf("\n");

    free(bufor); 
    return 0;
}
