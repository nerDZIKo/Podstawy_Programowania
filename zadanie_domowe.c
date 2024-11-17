//https://www.geeksforgeeks.org/c-define-preprocessor/
#include <stdio.h>
#define N 5
#define M 5
int main() {
    int matrix[N][M] = { {0}, {0} };
    // for (int loop_columns = 0; loop_columns < N + 1; loop_columns++){
    //     matrix[loop_columns][0] = loop_columns;
    // }
        // printf("%i", matrix[0][0]);
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
    return 0;
}