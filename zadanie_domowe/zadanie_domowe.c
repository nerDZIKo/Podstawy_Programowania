//https://www.geeksforgeeks.org/c-define-preprocessor/
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#define LINE 5
#define COLUMN 5

void print_defined_part_of_matrix(int matrix[LINE][COLUMN], int line_to_print, int column_to_print) {
    printf("%i ", matrix[line_to_print][column_to_print]);
}

void create_EVEN_random_number()
{
    int random_number = rand() % 6 + 1; 
    printf("The random number is: %d\n", random_number); 
}
void create_ODD_random_number()
{
    int random_number = rand() % 6 + 1; 
    printf("The random number is: %d\n", random_number); 
}

int main() {
    srand(time(NULL)); 
    int matrix[LINE][COLUMN] = { {0, 1, 3, 4, 5} };
    for (int loop_line = 0; loop_line < LINE; loop_line++)
    {
        for (int loop_column = 0; loop_column < COLUMN; loop_column++)
        {
            print_defined_part_of_matrix(matrix, loop_line, loop_column);
        }
    }
    return 0;
}




    // for (int loop_columns = 0; loop_columns < N + 1; loop_columns++){
    //     matrix[loop_columns][0] = loop_columns;
    // }
        // printf("%i", matrix[0][0]);
    // for (int i = 0; i < N; i++) { 
    //     for (int j = 0; j < N; j++) { 
    //         printf("%d ", matrix[i][j]); 
    //     } 
    //     printf("\n"); 
    // } 