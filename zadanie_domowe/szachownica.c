#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int is_binary(char* input) {
    if (input[0] != '0' || input[1] != 'b') return 0;
    for (int charIndex = 2; input[charIndex] != '\0'; charIndex++) {
        if (input[charIndex] != '0' && input[charIndex] != '1') return 0;
    }
    return 1;
}

int binary_to_decimal(char* input) {
    int decimal_value = 0;
    for (int charIndex = 2; input[charIndex] != '\0'; charIndex++) {
        decimal_value = decimal_value * 2 + (input[charIndex] - '0');
    }
    return decimal_value;
}

int is_negative(char* input) {
    return input[0] == '-';
}

int get_valid_input(const char *prompt) {
    char input[100];
    int value;

    while (1) {
        printf("%s", prompt);
        scanf("%s", input);
        
        if (is_negative(input)) {
            printf("Liczba nie może być ujemna. Spróbuj ponownie.\n");
            continue;
        }

        if (is_binary(input)) {
            value = binary_to_decimal(input);
            break;
        } else {
            char* end;
            value = strtol(input, &end, 10);
            if (*end == '\0' && value >= 0) break;
            else printf("Błędny format. Spróbuj ponownie (np. 0b101 lub 100).\n");
        }
    }
    return value;
}

void generate_chessboard(int numRows, int numColumns, int board[numRows][numColumns]) {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            if ((row + column) % 2 == 0) {
                board[row][column] = (rand() % 50) * 2;
            } else {
                board[row][column] = (rand() % 50) * 2 + 1;
            }
        }
    }
}

void display_chessboard(int numRows, int numColumns, int board[numRows][numColumns]) {
    int len = numColumns * 5 + 6;
    char line[len + 1];
    
    for (int i = 0; i < len; i++) {
        line[i] = '-';
    }
    line[len] = '\0';

    char title[] = "CUDOWNA SZACHOWNICA";
    int title_len = strlen(title);
    int padding_left = (len - title_len) / 2;
    int padding_right = len - title_len - padding_left;
    
    printf("%s\n", line);
    printf("%*s%s%*s\n", padding_left, "", title, padding_right, "");
    printf("%s\n", line);
    
    printf("    ");
    for (int column = 0; column < numColumns; column++) {
        printf("%4d ", column + 1);
    }
    printf("\n");
    printf("   +");
    for (int column = 0; column < numColumns; column++) {
        printf("-----");
    }
    printf("\n");
    for (int row = 0; row < numRows; row++) {
        printf("%2d |", row + 1);
        for (int column = 0; column < numColumns; column++) {
            printf("%4d ", board[row][column]);
            fflush(stdout);
            int delay = (rand() % 150000) + 10000;
            usleep(delay);
        }
        printf("\n");
    }
    printf("%s\n", line);

    char end_title[] = "KONIEC SZACHOWNICY";
    int end_title_len = strlen(end_title);
    padding_left = (len - end_title_len) / 2;
    padding_right = len - end_title_len - padding_left;

    printf("%*s%s%*s\n", padding_left, "", end_title, padding_right, "");
    printf("%s\n", line);
}

void clear_terminal() {
    printf("\033[H\033[J");
}

int main() {
    srand(time(NULL));
    
    while (1) {
        int numRows = get_valid_input("Podaj liczbę wierszy (N): ");
        int numColumns = get_valid_input("Podaj liczbę kolumn (M): ");
        
        if (numRows > 30 || numColumns > 30) {
            printf("Bez przesady! Tablica nie może mieć więcej niż 30 wierszy i 30 kolumn, bo się nie zmieści na ekranie.\n");
            continue;
        }

        int board[numRows][numColumns];
        generate_chessboard(numRows, numColumns, board);
        display_chessboard(numRows, numColumns, board);

        char user_choice;
        printf("To co? Jeszcze raz? (t/n): ");
        
        char input[100];
        while (1) {
            fgets(input, 100, stdin);
            
            if (input[0] == '\0' || input[0] == '\n') {
                continue;
            }

            user_choice = tolower(input[0]);

            if (user_choice == 't' || user_choice == 'n') {
                break;
            } else {
                printf("Proszę, nie śmieszkować. To co? Jeszcze raz? (t/n): ");
            }
        }

        if (user_choice == 't') {
            clear_terminal();
        } else if (user_choice == 'n') {
            break;
        }
    }

    return 0;
}
