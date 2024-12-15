#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_value_in_array(int value, int values[], int current_size) {
    for (int current_index = 0; current_index < current_size; current_index++) {
        if (values[current_index] == value) {
            return true;
        }
    }
    return false;
}

void fill_array_with_unique_values(int array_size, int lower_bound, int upper_bound, int values[]) {
    int total_draws = 0;
    int filled_size = 0;

    while (filled_size < array_size) {
        int random_value = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
        total_draws++;

        if (!is_value_in_array(random_value, values, filled_size)) {
            values[filled_size] = random_value;
            filled_size++;
        }
    }
    printf("Całkowita liczba losowań: %d\n", total_draws);
}

void print_array(int array_size, int values[]) {
    printf("Wygenerowana tablica:\n");
    for (int current_index = 0; current_index < array_size; current_index++) {
        printf("%d ", values[current_index]);
    }
    printf("\n");
}

int get_positive_integer(const char* prompt) {
    int entered_value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &entered_value) != 1 || entered_value <= 0) {
            while(getchar() != '\n');
            printf("Błąd: Proszę wprowadzić liczbę całkowitą większą niż 0.\n");
        } else {
            return entered_value;
        }
    }
}

int get_integer_in_range(const char* prompt, int min_value, int max_value) {
    int entered_value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &entered_value) != 1 || entered_value < min_value || entered_value > max_value) {
            while(getchar() != '\n');
            printf("Błąd: Proszę wprowadzić liczbę całkowitą w przedziale [%d, %d].\n", min_value, max_value);
        } else {
            return entered_value;
        }
    }
}

bool is_fraction(char* str) {
    int current_index = 0;
    while (str[current_index] != '\0') {
        if (str[current_index] == '/') {
            return true;
        }
        current_index++;
    }
    return false;
}

bool is_float(char* str) {
    int dot_count = 0;
    for (int current_index = 0; str[current_index] != '\0'; current_index++) {
        if (str[current_index] == '.') {
            dot_count++;
        }
        if (!isdigit(str[current_index]) && str[current_index] != '.') {
            return false;
        }
    }
    return dot_count == 1;
}

int get_integer_in_range_no_fractions(const char* prompt, int min_value, int max_value) {
    char input_string[100];
    while (1) {
        printf("%s", prompt);
        scanf("%s", input_string);
        
        if (is_fraction(input_string)) {
            printf("Błąd: Nie można wprowadzać ułamków w tym zakresie. Proszę podać liczbę całkowitą.\n");
            continue;
        }

        if (is_float(input_string)) {
            printf("Błąd: Nie można wprowadzać liczb zmiennoprzecinkowych w tym zakresie. Proszę podać liczbę całkowitą.\n");
            continue;
        }
        
        int entered_value = atoi(input_string);
        if (entered_value >= min_value && entered_value <= max_value) {
            return entered_value;
        } else {
            printf("Błąd: Proszę wprowadzić liczbę całkowitą w przedziale [%d, %d].\n", min_value, max_value);
        }
    }
}

void print_menu() {
    printf("\n******************************************\n");
    printf("*               MENU                    *\n");
    printf("******************************************\n");
    printf("* 1. Wygeneruj unikalne liczby w tablicy *\n");
    printf("* 2. Zakończ program                    *\n");
    printf("******************************************\n");
    printf("Wybierz opcję (1-2): ");
}

void clear_terminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int selected_option;

    srand(time(NULL));

    while (1) {
        print_menu();
        if (scanf("%d", &selected_option) != 1 || selected_option < 1 || selected_option > 2) {
            while (getchar() != '\n');
            printf("Błąd: Wybierz poprawną opcję.\n");
            continue;
        }

        switch (selected_option) {
            case 1:
                {
                    int array_size = get_positive_integer("Podaj rozmiar tablicy: ");
                    int lower_bound, upper_bound;
                    
                    while (1) {
                        lower_bound = get_integer_in_range_no_fractions("Podaj dolny zakres losowania: ", -1000000, 1000000);
                        upper_bound = get_integer_in_range_no_fractions("Podaj górny zakres losowania: ", lower_bound + 1, 1000000);

                        if (upper_bound > lower_bound) {
                            break;
                        } else {
                            printf("Błąd: Górny zakres musi być większy od dolnego. Spróbuj ponownie.\n");
                        }
                    }

                    int values[array_size];

                    fill_array_with_unique_values(array_size, lower_bound, upper_bound, values);
                    print_array(array_size, values);

                    printf("\nCzy kontynuujemy program? (T/N): ");
                    char continue_choice;
                    while (1) {
                        scanf(" %c", &continue_choice);  
                        if (continue_choice == 'T' || continue_choice == 't') {
                            clear_terminal();  
                            break;
                        } else if (continue_choice == 'N' || continue_choice == 'n') {
                            printf("Zakończenie programu.\n");
                            return 0;
                        } else {
                            printf("Błąd: Wybierz 'T' lub 'N'.\n");
                        }
                    }
                }
                break;
            case 2:
                printf("Zakończenie programu.\n");
                return 0;
            default:
                printf("Błąd: Wybierz poprawną opcję.\n");
        }
    }

    return 0;
}
