#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 

int main() { 

  // Seed the random number generator with the current time 

  srand(time(NULL)); 


  // Generate a random number between 1 and 6 

  int random_number = rand() % 6 + 1; 

  printf("The random number is: %d\n", random_number); 

  return 0; 
}