#include <stdio.h>
int main() {
  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
    printf("%i", matrix[0][0]);
    printf("%i", matrix[3][0]);
    printf("%i", matrix[0][3]);

    // Initialize a 2D array (nested list) with 3 rows and 4 columns 
    int array[3][4] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12} 
    }; 
    
    // Print the 2D array 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 4; j++) { 
            printf("%d ", array[i][j]); 
        } 
        printf("\n"); 
    } 

  return 0;
}