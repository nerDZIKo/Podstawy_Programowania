#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicjalizacja generatora liczb losowych
    srand(time(NULL));

    // Losowanie liczby całkowitej w zakresie [1, 100]
    int random_number = 1 + rand() % 100;
    printf("Losowa liczba calkowita w zakresie [1, 100]: %d\n", random_number);

    // Losowanie liczby zmiennoprzecinkowej w zakresie [0.0, 1.0]
    double random_float = rand() / (RAND_MAX + 1.0);
    printf("Losowa liczba zmiennoprzecinkowa w zakresie [0.0, 1.0]: %f\n", random_float);

    // Losowanie liczby zmiennoprzecinkowej w zakresie [3.0, 7.0]
    double random_range_float = 3.0 + (rand() / (RAND_MAX + 1.0)) * (7.0 - 3.0);
    printf("Losowa liczba zmiennoprzecinkowa w zakresie [3.0, 7.0]: %f\n", random_range_float);

    return 0;
}
