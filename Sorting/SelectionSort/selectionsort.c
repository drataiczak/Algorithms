#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 10
#define BS_RAND_MIN 0
#define BS_RAND_MAX 10

/* In place sorting using a pre-malloced array */
void sort(int *array, int arraySize) {
  int min;
  int temp;

  for(int i = 0; i < arraySize - 1; i++) {
    min = i;

    for(int j = i + 1; j < arraySize; j++) {
      if(array[j] < array[min]) {
        min = j;
      }
    }

    temp = array[min];
    array[min] = array[i];
    array[i] = temp;
  }
}

int main() {
  int *array = NULL;

  array = malloc(sizeof(int) * ARR_SIZE);
  srand(time(NULL));

  printf("The original array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    array[i] = rand() % (BS_RAND_MAX - BS_RAND_MIN + 1) + BS_RAND_MIN;  
    
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);
  }

  sort(array, ARR_SIZE);

  printf("The sorted array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);  
  }

  return 0;
}
